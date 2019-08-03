// Copyright (c) 2019 Aaron R Robinson

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _PPDB_CORSYM_CORSYM_HPP_
#define _PPDB_CORSYM_CORSYM_HPP_

#include <xplat_corsym.hpp>
#include <atomic>

// Every interface type should have a defined version of this function.
template<typename T>
bool IsIID(REFIID);

namespace Internal
{
    template<typename I>
    HRESULT __QueryInterfaceImpl(
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ void **ppvObject,
        /* [in] */ I obj)
    {
        if (IsIID<I>(riid))
        {
            *ppvObject = static_cast<I>(obj);
        }
        else
        {
            *ppvObject = nullptr;
            return E_NOINTERFACE;
        }

        return S_OK;
    }

    template<typename I1, typename ...IR>
    HRESULT __QueryInterfaceImpl(
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ void **ppvObject,
        /* [in] */ I1 i1,
        /* [in] */ IR... remain)
    {
        if (IsIID<I1>(riid))
        {
            *ppvObject = static_cast<I1>(i1);
            return S_OK;
        }

        return __QueryInterfaceImpl(riid, ppvObject, remain...);
    }
}

// Implementation of IUnknown operations
class UnknownImpl
{
public:
    UnknownImpl() = default;
    virtual ~UnknownImpl() = default;

    UnknownImpl(const UnknownImpl&) = delete;
    UnknownImpl& operator=(const UnknownImpl&) = delete;

    UnknownImpl(UnknownImpl&&) = default;
    UnknownImpl& operator=(UnknownImpl&&) = default;

    template<typename I1, typename ...IR>
    HRESULT DoQueryInterface(
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ void **ppvObject,
        /* [in] */ I1 i1,
        /* [in] */ IR... remain)
    {
        if (ppvObject == nullptr)
            return E_POINTER;

        if (IsIID<IUnknown *>(riid))
        {
            *ppvObject = static_cast<IUnknown *>(i1);
        }
        else
        {
            HRESULT hr = Internal::__QueryInterfaceImpl(riid, ppvObject, i1, remain...);
            if (hr != S_OK)
                return hr;
        }

        DoAddRef();
        return S_OK;
    }

    ULONG DoAddRef()
    {
        assert(_refCount > 0);
        return (++_refCount);
    }

    ULONG DoRelease()
    {
        assert(_refCount > 0);
        ULONG c = (--_refCount);
        if (c == 0)
            delete this;
        return c;
    }

private:
    std::atomic<ULONG> _refCount = 1;
};

class SymUnmanagedReader :
    public UnknownImpl,
    public ISymUnmanagedReader
{
public: // ISymUnmanagedReader
    virtual HRESULT STDMETHODCALLTYPE GetDocument(
        /* [in] */ __RPC__in WCHAR *url,
        /* [in] */ GUID language,
        /* [in] */ GUID languageVendor,
        /* [in] */ GUID documentType,
        /* [retval][out] */ __RPC__deref_out_opt ISymUnmanagedDocument **pRetVal);

    virtual HRESULT STDMETHODCALLTYPE GetDocuments(
        /* [in] */ ULONG32 cDocs,
        /* [out] */ __RPC__out ULONG32 *pcDocs,
        /* [length_is][size_is][out] */ __RPC__out_ecount_part(cDocs, *pcDocs) ISymUnmanagedDocument *pDocs[]);

    virtual HRESULT STDMETHODCALLTYPE GetUserEntryPoint(
        /* [retval][out] */ __RPC__out mdMethodDef *pToken);

    virtual HRESULT STDMETHODCALLTYPE GetMethod(
        /* [in] */ mdMethodDef token,
        /* [retval][out] */ __RPC__deref_out_opt ISymUnmanagedMethod **pRetVal);

    virtual HRESULT STDMETHODCALLTYPE GetMethodByVersion(
        /* [in] */ mdMethodDef token,
        /* [in] */ int version,
        /* [retval][out] */ __RPC__deref_out_opt ISymUnmanagedMethod **pRetVal);

    virtual HRESULT STDMETHODCALLTYPE GetVariables(
        /* [in] */ mdToken parent,
        /* [in] */ ULONG32 cVars,
        /* [out] */ __RPC__out ULONG32 *pcVars,
        /* [length_is][size_is][out] */ __RPC__out_ecount_part(cVars, *pcVars) ISymUnmanagedVariable *pVars[]);

    virtual HRESULT STDMETHODCALLTYPE GetGlobalVariables(
        /* [in] */ ULONG32 cVars,
        /* [out] */ __RPC__out ULONG32 *pcVars,
        /* [length_is][size_is][out] */ __RPC__out_ecount_part(cVars, *pcVars) ISymUnmanagedVariable *pVars[]);

    virtual HRESULT STDMETHODCALLTYPE GetMethodFromDocumentPosition(
        /* [in] */ __RPC__in_opt ISymUnmanagedDocument *document,
        /* [in] */ ULONG32 line,
        /* [in] */ ULONG32 column,
        /* [retval][out] */ __RPC__deref_out_opt ISymUnmanagedMethod **pRetVal);

    virtual HRESULT STDMETHODCALLTYPE GetSymAttribute(
        /* [in] */ mdToken parent,
        /* [in] */ __RPC__in WCHAR *name,
        /* [in] */ ULONG32 cBuffer,
        /* [out] */ __RPC__out ULONG32 *pcBuffer,
        /* [length_is][size_is][out] */ __RPC__out_ecount_part(cBuffer, *pcBuffer) BYTE buffer[]);

    virtual HRESULT STDMETHODCALLTYPE GetNamespaces(
        /* [in] */ ULONG32 cNameSpaces,
        /* [out] */ __RPC__out ULONG32 *pcNameSpaces,
        /* [length_is][size_is][out] */ __RPC__out_ecount_part(cNameSpaces, *pcNameSpaces) ISymUnmanagedNamespace *namespaces[]);

    virtual HRESULT STDMETHODCALLTYPE Initialize(
        /* [in] */ __RPC__in_opt IUnknown *importer,
        /* [in] */ __RPC__in const WCHAR *filename,
        /* [in] */ __RPC__in const WCHAR *searchPath,
        /* [in] */ __RPC__in_opt IStream *pIStream);

    virtual HRESULT STDMETHODCALLTYPE UpdateSymbolStore(
        /* [in] */ __RPC__in const WCHAR *filename,
        /* [in] */ __RPC__in_opt IStream *pIStream);

    virtual HRESULT STDMETHODCALLTYPE ReplaceSymbolStore(
        /* [in] */ __RPC__in const WCHAR *filename,
        /* [in] */ __RPC__in_opt IStream *pIStream);

    virtual HRESULT STDMETHODCALLTYPE GetSymbolStoreFileName(
        /* [in] */ ULONG32 cchName,
        /* [out] */ __RPC__out ULONG32 *pcchName,
        /* [length_is][size_is][out] */ __RPC__out_ecount_part(cchName, *pcchName) WCHAR szName[]);

    virtual HRESULT STDMETHODCALLTYPE GetMethodsFromDocumentPosition(
        /* [in] */ __RPC__in_opt ISymUnmanagedDocument *document,
        /* [in] */ ULONG32 line,
        /* [in] */ ULONG32 column,
        /* [in] */ ULONG32 cMethod,
        /* [out] */ __RPC__out ULONG32 *pcMethod,
        /* [length_is][size_is][out] */ __RPC__out_ecount_part(cMethod, *pcMethod) ISymUnmanagedMethod *pRetVal[]);

    virtual HRESULT STDMETHODCALLTYPE GetDocumentVersion(
        /* [in] */ __RPC__in_opt ISymUnmanagedDocument *pDoc,
        /* [out] */ __RPC__out int *version,
        /* [out] */ __RPC__out BOOL *pbCurrent);

    virtual HRESULT STDMETHODCALLTYPE GetMethodVersion(
        /* [in] */ __RPC__in_opt ISymUnmanagedMethod *pMethod,
        /* [out] */ __RPC__out int *version);

public: // IUnknown
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject)
    {
        return DoQueryInterface(riid, ppvObject, static_cast<ISymUnmanagedReader *>(this));
    }
    virtual ULONG STDMETHODCALLTYPE AddRef(void)
    {
        return DoAddRef();
    }
    virtual ULONG STDMETHODCALLTYPE Release(void)
    {
        return DoRelease();
    }
};

#endif // _PPDB_CORSYM_CORSYM_HPP_