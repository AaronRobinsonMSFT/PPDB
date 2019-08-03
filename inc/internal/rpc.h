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