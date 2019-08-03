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

#include <cassert>
#include "CorSym.hpp"

template<>
bool IsIID<ISymUnmanagedReader *>(REFIID riid)
{
    return ::memcmp(&IID_ISymUnmanagedReader, &riid, sizeof(IID_ISymUnmanagedReader)) == 0;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetDocument(
    /* [in] */ __RPC__in WCHAR *url,
    /* [in] */ GUID language,
    /* [in] */ GUID languageVendor,
    /* [in] */ GUID documentType,
    /* [retval][out] */ __RPC__deref_out_opt ISymUnmanagedDocument **pRetVal)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetDocuments(
    /* [in] */ ULONG32 cDocs,
    /* [out] */ __RPC__out ULONG32 *pcDocs,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(cDocs, *pcDocs) ISymUnmanagedDocument *pDocs[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetUserEntryPoint(
    /* [retval][out] */ __RPC__out mdMethodDef *pToken)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetMethod(
    /* [in] */ mdMethodDef token,
    /* [retval][out] */ __RPC__deref_out_opt ISymUnmanagedMethod **pRetVal)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetMethodByVersion(
    /* [in] */ mdMethodDef token,
    /* [in] */ int version,
    /* [retval][out] */ __RPC__deref_out_opt ISymUnmanagedMethod **pRetVal)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetVariables(
    /* [in] */ mdToken parent,
    /* [in] */ ULONG32 cVars,
    /* [out] */ __RPC__out ULONG32 *pcVars,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(cVars, *pcVars) ISymUnmanagedVariable *pVars[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetGlobalVariables(
    /* [in] */ ULONG32 cVars,
    /* [out] */ __RPC__out ULONG32 *pcVars,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(cVars, *pcVars) ISymUnmanagedVariable *pVars[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetMethodFromDocumentPosition(
    /* [in] */ __RPC__in_opt ISymUnmanagedDocument *document,
    /* [in] */ ULONG32 line,
    /* [in] */ ULONG32 column,
    /* [retval][out] */ __RPC__deref_out_opt ISymUnmanagedMethod **pRetVal)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetSymAttribute(
    /* [in] */ mdToken parent,
    /* [in] */ __RPC__in WCHAR *name,
    /* [in] */ ULONG32 cBuffer,
    /* [out] */ __RPC__out ULONG32 *pcBuffer,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(cBuffer, *pcBuffer) BYTE buffer[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetNamespaces(
    /* [in] */ ULONG32 cNameSpaces,
    /* [out] */ __RPC__out ULONG32 *pcNameSpaces,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(cNameSpaces, *pcNameSpaces) ISymUnmanagedNamespace *namespaces[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::Initialize(
    /* [in] */ __RPC__in_opt IUnknown *importer,
    /* [in] */ __RPC__in const WCHAR *filename,
    /* [in] */ __RPC__in const WCHAR *searchPath,
    /* [in] */ __RPC__in_opt IStream *pIStream)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::UpdateSymbolStore(
    /* [in] */ __RPC__in const WCHAR *filename,
    /* [in] */ __RPC__in_opt IStream *pIStream)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::ReplaceSymbolStore(
    /* [in] */ __RPC__in const WCHAR *filename,
    /* [in] */ __RPC__in_opt IStream *pIStream)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetSymbolStoreFileName(
    /* [in] */ ULONG32 cchName,
    /* [out] */ __RPC__out ULONG32 *pcchName,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(cchName, *pcchName) WCHAR szName[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetMethodsFromDocumentPosition(
    /* [in] */ __RPC__in_opt ISymUnmanagedDocument *document,
    /* [in] */ ULONG32 line,
    /* [in] */ ULONG32 column,
    /* [in] */ ULONG32 cMethod,
    /* [out] */ __RPC__out ULONG32 *pcMethod,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(cMethod, *pcMethod) ISymUnmanagedMethod *pRetVal[])
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetDocumentVersion(
    /* [in] */ __RPC__in_opt ISymUnmanagedDocument *pDoc,
    /* [out] */ __RPC__out int *version,
    /* [out] */ __RPC__out BOOL *pbCurrent)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SymUnmanagedReader::GetMethodVersion(
    /* [in] */ __RPC__in_opt ISymUnmanagedMethod *pMethod,
    /* [out] */ __RPC__out int *version)
{
    return E_NOTIMPL;
}
