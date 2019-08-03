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

//
// Used as a minimum stubbed implementation
//

#ifndef _PPDB_INC_INTERNAL_RPC_H_
#define _PPDB_INC_INTERNAL_RPC_H_

#define __RPC__in
#define __RPC__in_ecount_full(a) 
#define __RPC__in_xcount(a) 
#define __RPC__in_opt

#define __RPC__out
#define __RPC__out_ecount_part(a,b) 
#define __RPC__deref_out_ecount_full_opt(a) 
#define __RPC__deref_out_opt

#define __RPC__inout
#define __RPC__inout_xcount(a) 

#define __RPC_USER

using RPC_IF_HANDLE = void *;

#endif // _PPDB_INC_INTERNAL_RPC_H_