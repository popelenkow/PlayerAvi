/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Oct 04 09:50:10 2002
 */
/* Compiler settings for d:\EGOR\AVI_RW\GetAVIInfo\GetAVIInfo.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __GetAVIInfo_h__
#define __GetAVIInfo_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IGetAVIInfoOld_FWD_DEFINED__
#define __IGetAVIInfoOld_FWD_DEFINED__
typedef interface IGetAVIInfoOld IGetAVIInfoOld;
#endif 	/* __IGetAVIInfoOld_FWD_DEFINED__ */


#ifndef __IGetAVIInfo_FWD_DEFINED__
#define __IGetAVIInfo_FWD_DEFINED__
typedef interface IGetAVIInfo IGetAVIInfo;
#endif 	/* __IGetAVIInfo_FWD_DEFINED__ */


#ifndef __IGetAVIInfoArray_FWD_DEFINED__
#define __IGetAVIInfoArray_FWD_DEFINED__
typedef interface IGetAVIInfoArray IGetAVIInfoArray;
#endif 	/* __IGetAVIInfoArray_FWD_DEFINED__ */


#ifndef __GetAVIInfo_FWD_DEFINED__
#define __GetAVIInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class GetAVIInfo GetAVIInfo;
#else
typedef struct GetAVIInfo GetAVIInfo;
#endif /* __cplusplus */

#endif 	/* __GetAVIInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_GetAVIInfo_0000 */
/* [local] */ 

#pragma pack(1)
typedef /* [public][public][public] */ struct  __MIDL___MIDL_itf_GetAVIInfo_0000_0001
    {
    DWORD fccType;
    DWORD fr_flags;
    DWORD fr_pos;
    DWORD fr_size;
    }	IndexFileEntry;

#pragma pack()


extern RPC_IF_HANDLE __MIDL_itf_GetAVIInfo_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_GetAVIInfo_0000_v0_0_s_ifspec;

#ifndef __IGetAVIInfoOld_INTERFACE_DEFINED__
#define __IGetAVIInfoOld_INTERFACE_DEFINED__

/* interface IGetAVIInfoOld */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGetAVIInfoOld;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5F3B918F-FD8B-40f0-B1A7-0791EB6E5314")
    IGetAVIInfoOld : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR file_name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR __RPC_FAR *file_name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoStreamNumber( 
            /* [out] */ long __RPC_FAR *num) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioStreamNumber( 
            /* [out] */ long __RPC_FAR *num) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoStreamInfo( 
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
            /* [in] */ long size,
            /* [out] */ long __RPC_FAR *ln,
            /* [out] */ long __RPC_FAR *size_info,
            /* [out] */ long __RPC_FAR *size_infoex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioStreamInfo( 
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
            /* [in] */ long size,
            /* [out] */ long __RPC_FAR *ln,
            /* [out] */ long __RPC_FAR *size_info) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoFrameNumber( 
            /* [in] */ long index,
            /* [out] */ long __RPC_FAR *frame_count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioChunkNumber( 
            /* [in] */ long index,
            /* [out] */ long __RPC_FAR *chunk_count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoFrameInfo( 
            /* [in] */ long index,
            /* [in] */ long frame_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioChunkInfo( 
            /* [in] */ long index,
            /* [in] */ long chunk_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoFormatInfo( 
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioFormatInfo( 
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoExtFormatInfo( 
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioSampleInfo( 
            /* [in] */ long index,
            /* [in] */ UINT sample_number,
            /* [out] */ UINT __RPC_FAR *chunk_num,
            /* [out] */ UINT __RPC_FAR *offset) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMainHeader( 
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *buffer,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoFrameInfo2( 
            /* [in] */ long index,
            /* [in] */ long frame_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size,
            /* [out] */ ULONG __RPC_FAR *flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioChunkInfo2( 
            /* [in] */ long index,
            /* [in] */ long chunk_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size,
            /* [out] */ ULONG __RPC_FAR *flags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGetAVIInfoOldVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGetAVIInfoOld __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGetAVIInfoOld __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ BSTR file_name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *file_name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoStreamNumber )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *num);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioStreamNumber )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *num);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoStreamInfo )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
            /* [in] */ long size,
            /* [out] */ long __RPC_FAR *ln,
            /* [out] */ long __RPC_FAR *size_info,
            /* [out] */ long __RPC_FAR *size_infoex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioStreamInfo )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
            /* [in] */ long size,
            /* [out] */ long __RPC_FAR *ln,
            /* [out] */ long __RPC_FAR *size_info);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoFrameNumber )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [out] */ long __RPC_FAR *frame_count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioChunkNumber )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [out] */ long __RPC_FAR *chunk_count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoFrameInfo )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long frame_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioChunkInfo )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long chunk_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoFormatInfo )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioFormatInfo )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoExtFormatInfo )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioSampleInfo )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ UINT sample_number,
            /* [out] */ UINT __RPC_FAR *chunk_num,
            /* [out] */ UINT __RPC_FAR *offset);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMainHeader )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *buffer,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoFrameInfo2 )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long frame_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size,
            /* [out] */ ULONG __RPC_FAR *flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioChunkInfo2 )( 
            IGetAVIInfoOld __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long chunk_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size,
            /* [out] */ ULONG __RPC_FAR *flags);
        
        END_INTERFACE
    } IGetAVIInfoOldVtbl;

    interface IGetAVIInfoOld
    {
        CONST_VTBL struct IGetAVIInfoOldVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetAVIInfoOld_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGetAVIInfoOld_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGetAVIInfoOld_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGetAVIInfoOld_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IGetAVIInfoOld_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IGetAVIInfoOld_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IGetAVIInfoOld_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IGetAVIInfoOld_Load(This,file_name)	\
    (This)->lpVtbl -> Load(This,file_name)

#define IGetAVIInfoOld_GetName(This,file_name)	\
    (This)->lpVtbl -> GetName(This,file_name)

#define IGetAVIInfoOld_GetVideoStreamNumber(This,num)	\
    (This)->lpVtbl -> GetVideoStreamNumber(This,num)

#define IGetAVIInfoOld_GetAudioStreamNumber(This,num)	\
    (This)->lpVtbl -> GetAudioStreamNumber(This,num)

#define IGetAVIInfoOld_GetVideoStreamInfo(This,index,stream_header,size,ln,size_info,size_infoex)	\
    (This)->lpVtbl -> GetVideoStreamInfo(This,index,stream_header,size,ln,size_info,size_infoex)

#define IGetAVIInfoOld_GetAudioStreamInfo(This,index,stream_header,size,ln,size_info)	\
    (This)->lpVtbl -> GetAudioStreamInfo(This,index,stream_header,size,ln,size_info)

#define IGetAVIInfoOld_GetVideoFrameNumber(This,index,frame_count)	\
    (This)->lpVtbl -> GetVideoFrameNumber(This,index,frame_count)

#define IGetAVIInfoOld_GetAudioChunkNumber(This,index,chunk_count)	\
    (This)->lpVtbl -> GetAudioChunkNumber(This,index,chunk_count)

#define IGetAVIInfoOld_GetVideoFrameInfo(This,index,frame_number,hi_offset,low_offset,size)	\
    (This)->lpVtbl -> GetVideoFrameInfo(This,index,frame_number,hi_offset,low_offset,size)

#define IGetAVIInfoOld_GetAudioChunkInfo(This,index,chunk_number,hi_offset,low_offset,size)	\
    (This)->lpVtbl -> GetAudioChunkInfo(This,index,chunk_number,hi_offset,low_offset,size)

#define IGetAVIInfoOld_GetVideoFormatInfo(This,index,format_info,buf_size,copy_size)	\
    (This)->lpVtbl -> GetVideoFormatInfo(This,index,format_info,buf_size,copy_size)

#define IGetAVIInfoOld_GetAudioFormatInfo(This,index,format_info,buf_size,copy_size)	\
    (This)->lpVtbl -> GetAudioFormatInfo(This,index,format_info,buf_size,copy_size)

#define IGetAVIInfoOld_GetVideoExtFormatInfo(This,index,format_info,buf_size,copy_size)	\
    (This)->lpVtbl -> GetVideoExtFormatInfo(This,index,format_info,buf_size,copy_size)

#define IGetAVIInfoOld_GetAudioSampleInfo(This,index,sample_number,chunk_num,offset)	\
    (This)->lpVtbl -> GetAudioSampleInfo(This,index,sample_number,chunk_num,offset)

#define IGetAVIInfoOld_GetMainHeader(This,buffer,buf_size,copy_size)	\
    (This)->lpVtbl -> GetMainHeader(This,buffer,buf_size,copy_size)

#define IGetAVIInfoOld_GetVideoFrameInfo2(This,index,frame_number,hi_offset,low_offset,size,flags)	\
    (This)->lpVtbl -> GetVideoFrameInfo2(This,index,frame_number,hi_offset,low_offset,size,flags)

#define IGetAVIInfoOld_GetAudioChunkInfo2(This,index,chunk_number,hi_offset,low_offset,size,flags)	\
    (This)->lpVtbl -> GetAudioChunkInfo2(This,index,chunk_number,hi_offset,low_offset,size,flags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_Load_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ BSTR file_name);


void __RPC_STUB IGetAVIInfoOld_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetName_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *file_name);


void __RPC_STUB IGetAVIInfoOld_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetVideoStreamNumber_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *num);


void __RPC_STUB IGetAVIInfoOld_GetVideoStreamNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetAudioStreamNumber_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *num);


void __RPC_STUB IGetAVIInfoOld_GetAudioStreamNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetVideoStreamInfo_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
    /* [in] */ long size,
    /* [out] */ long __RPC_FAR *ln,
    /* [out] */ long __RPC_FAR *size_info,
    /* [out] */ long __RPC_FAR *size_infoex);


void __RPC_STUB IGetAVIInfoOld_GetVideoStreamInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetAudioStreamInfo_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
    /* [in] */ long size,
    /* [out] */ long __RPC_FAR *ln,
    /* [out] */ long __RPC_FAR *size_info);


void __RPC_STUB IGetAVIInfoOld_GetAudioStreamInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetVideoFrameNumber_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [out] */ long __RPC_FAR *frame_count);


void __RPC_STUB IGetAVIInfoOld_GetVideoFrameNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetAudioChunkNumber_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [out] */ long __RPC_FAR *chunk_count);


void __RPC_STUB IGetAVIInfoOld_GetAudioChunkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetVideoFrameInfo_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long frame_number,
    /* [out] */ long __RPC_FAR *hi_offset,
    /* [out] */ ULONG __RPC_FAR *low_offset,
    /* [out] */ ULONG __RPC_FAR *size);


void __RPC_STUB IGetAVIInfoOld_GetVideoFrameInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetAudioChunkInfo_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long chunk_number,
    /* [out] */ long __RPC_FAR *hi_offset,
    /* [out] */ ULONG __RPC_FAR *low_offset,
    /* [out] */ ULONG __RPC_FAR *size);


void __RPC_STUB IGetAVIInfoOld_GetAudioChunkInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetVideoFormatInfo_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
    /* [in] */ long buf_size,
    /* [out] */ long __RPC_FAR *copy_size);


void __RPC_STUB IGetAVIInfoOld_GetVideoFormatInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetAudioFormatInfo_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
    /* [in] */ long buf_size,
    /* [out] */ long __RPC_FAR *copy_size);


void __RPC_STUB IGetAVIInfoOld_GetAudioFormatInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetVideoExtFormatInfo_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
    /* [in] */ long buf_size,
    /* [out] */ long __RPC_FAR *copy_size);


void __RPC_STUB IGetAVIInfoOld_GetVideoExtFormatInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetAudioSampleInfo_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ UINT sample_number,
    /* [out] */ UINT __RPC_FAR *chunk_num,
    /* [out] */ UINT __RPC_FAR *offset);


void __RPC_STUB IGetAVIInfoOld_GetAudioSampleInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetMainHeader_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *buffer,
    /* [in] */ long buf_size,
    /* [out] */ long __RPC_FAR *copy_size);


void __RPC_STUB IGetAVIInfoOld_GetMainHeader_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetVideoFrameInfo2_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long frame_number,
    /* [out] */ long __RPC_FAR *hi_offset,
    /* [out] */ ULONG __RPC_FAR *low_offset,
    /* [out] */ ULONG __RPC_FAR *size,
    /* [out] */ ULONG __RPC_FAR *flags);


void __RPC_STUB IGetAVIInfoOld_GetVideoFrameInfo2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoOld_GetAudioChunkInfo2_Proxy( 
    IGetAVIInfoOld __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long chunk_number,
    /* [out] */ long __RPC_FAR *hi_offset,
    /* [out] */ ULONG __RPC_FAR *low_offset,
    /* [out] */ ULONG __RPC_FAR *size,
    /* [out] */ ULONG __RPC_FAR *flags);


void __RPC_STUB IGetAVIInfoOld_GetAudioChunkInfo2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGetAVIInfoOld_INTERFACE_DEFINED__ */


#ifndef __IGetAVIInfo_INTERFACE_DEFINED__
#define __IGetAVIInfo_INTERFACE_DEFINED__

/* interface IGetAVIInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGetAVIInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3CB22126-3A53-4309-838D-1580A2339C8E")
    IGetAVIInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR file_name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR __RPC_FAR *file_name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoStreamNumber( 
            /* [out] */ long __RPC_FAR *num) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioStreamNumber( 
            /* [out] */ long __RPC_FAR *num) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoStreamInfo( 
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
            /* [in] */ long size,
            /* [out] */ long __RPC_FAR *ln,
            /* [out] */ long __RPC_FAR *size_info,
            /* [out] */ long __RPC_FAR *size_infoex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioStreamInfo( 
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
            /* [in] */ long size,
            /* [out] */ long __RPC_FAR *ln,
            /* [out] */ long __RPC_FAR *size_info) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoFrameNumber( 
            /* [in] */ long index,
            /* [out] */ long __RPC_FAR *frame_count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioChunkNumber( 
            /* [in] */ long index,
            /* [out] */ long __RPC_FAR *chunk_count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoFrameInfo( 
            /* [in] */ long index,
            /* [in] */ long frame_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioChunkInfo( 
            /* [in] */ long index,
            /* [in] */ long chunk_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoFormatInfo( 
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioFormatInfo( 
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoExtFormatInfo( 
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioSampleInfo( 
            /* [in] */ long index,
            /* [in] */ UINT sample_number,
            /* [out] */ UINT __RPC_FAR *chunk_num,
            /* [out] */ UINT __RPC_FAR *offset) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMainHeader( 
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *buffer,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoFrameInfo2( 
            /* [in] */ long index,
            /* [in] */ long frame_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size,
            /* [out] */ ULONG __RPC_FAR *flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioChunkInfo2( 
            /* [in] */ long index,
            /* [in] */ long chunk_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size,
            /* [out] */ ULONG __RPC_FAR *flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FastLoad( 
            /* [in] */ BSTR file_name) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGetAVIInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGetAVIInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGetAVIInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ BSTR file_name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *file_name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoStreamNumber )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *num);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioStreamNumber )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *num);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoStreamInfo )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
            /* [in] */ long size,
            /* [out] */ long __RPC_FAR *ln,
            /* [out] */ long __RPC_FAR *size_info,
            /* [out] */ long __RPC_FAR *size_infoex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioStreamInfo )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
            /* [in] */ long size,
            /* [out] */ long __RPC_FAR *ln,
            /* [out] */ long __RPC_FAR *size_info);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoFrameNumber )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [out] */ long __RPC_FAR *frame_count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioChunkNumber )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [out] */ long __RPC_FAR *chunk_count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoFrameInfo )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long frame_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioChunkInfo )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long chunk_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoFormatInfo )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioFormatInfo )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoExtFormatInfo )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioSampleInfo )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ UINT sample_number,
            /* [out] */ UINT __RPC_FAR *chunk_num,
            /* [out] */ UINT __RPC_FAR *offset);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMainHeader )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [length_is][size_is][out] */ BYTE __RPC_FAR *buffer,
            /* [in] */ long buf_size,
            /* [out] */ long __RPC_FAR *copy_size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoFrameInfo2 )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long frame_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size,
            /* [out] */ ULONG __RPC_FAR *flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioChunkInfo2 )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long chunk_number,
            /* [out] */ long __RPC_FAR *hi_offset,
            /* [out] */ ULONG __RPC_FAR *low_offset,
            /* [out] */ ULONG __RPC_FAR *size,
            /* [out] */ ULONG __RPC_FAR *flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FastLoad )( 
            IGetAVIInfo __RPC_FAR * This,
            /* [in] */ BSTR file_name);
        
        END_INTERFACE
    } IGetAVIInfoVtbl;

    interface IGetAVIInfo
    {
        CONST_VTBL struct IGetAVIInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetAVIInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGetAVIInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGetAVIInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGetAVIInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IGetAVIInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IGetAVIInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IGetAVIInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IGetAVIInfo_Load(This,file_name)	\
    (This)->lpVtbl -> Load(This,file_name)

#define IGetAVIInfo_GetName(This,file_name)	\
    (This)->lpVtbl -> GetName(This,file_name)

#define IGetAVIInfo_GetVideoStreamNumber(This,num)	\
    (This)->lpVtbl -> GetVideoStreamNumber(This,num)

#define IGetAVIInfo_GetAudioStreamNumber(This,num)	\
    (This)->lpVtbl -> GetAudioStreamNumber(This,num)

#define IGetAVIInfo_GetVideoStreamInfo(This,index,stream_header,size,ln,size_info,size_infoex)	\
    (This)->lpVtbl -> GetVideoStreamInfo(This,index,stream_header,size,ln,size_info,size_infoex)

#define IGetAVIInfo_GetAudioStreamInfo(This,index,stream_header,size,ln,size_info)	\
    (This)->lpVtbl -> GetAudioStreamInfo(This,index,stream_header,size,ln,size_info)

#define IGetAVIInfo_GetVideoFrameNumber(This,index,frame_count)	\
    (This)->lpVtbl -> GetVideoFrameNumber(This,index,frame_count)

#define IGetAVIInfo_GetAudioChunkNumber(This,index,chunk_count)	\
    (This)->lpVtbl -> GetAudioChunkNumber(This,index,chunk_count)

#define IGetAVIInfo_GetVideoFrameInfo(This,index,frame_number,hi_offset,low_offset,size)	\
    (This)->lpVtbl -> GetVideoFrameInfo(This,index,frame_number,hi_offset,low_offset,size)

#define IGetAVIInfo_GetAudioChunkInfo(This,index,chunk_number,hi_offset,low_offset,size)	\
    (This)->lpVtbl -> GetAudioChunkInfo(This,index,chunk_number,hi_offset,low_offset,size)

#define IGetAVIInfo_GetVideoFormatInfo(This,index,format_info,buf_size,copy_size)	\
    (This)->lpVtbl -> GetVideoFormatInfo(This,index,format_info,buf_size,copy_size)

#define IGetAVIInfo_GetAudioFormatInfo(This,index,format_info,buf_size,copy_size)	\
    (This)->lpVtbl -> GetAudioFormatInfo(This,index,format_info,buf_size,copy_size)

#define IGetAVIInfo_GetVideoExtFormatInfo(This,index,format_info,buf_size,copy_size)	\
    (This)->lpVtbl -> GetVideoExtFormatInfo(This,index,format_info,buf_size,copy_size)

#define IGetAVIInfo_GetAudioSampleInfo(This,index,sample_number,chunk_num,offset)	\
    (This)->lpVtbl -> GetAudioSampleInfo(This,index,sample_number,chunk_num,offset)

#define IGetAVIInfo_GetMainHeader(This,buffer,buf_size,copy_size)	\
    (This)->lpVtbl -> GetMainHeader(This,buffer,buf_size,copy_size)

#define IGetAVIInfo_GetVideoFrameInfo2(This,index,frame_number,hi_offset,low_offset,size,flags)	\
    (This)->lpVtbl -> GetVideoFrameInfo2(This,index,frame_number,hi_offset,low_offset,size,flags)

#define IGetAVIInfo_GetAudioChunkInfo2(This,index,chunk_number,hi_offset,low_offset,size,flags)	\
    (This)->lpVtbl -> GetAudioChunkInfo2(This,index,chunk_number,hi_offset,low_offset,size,flags)

#define IGetAVIInfo_FastLoad(This,file_name)	\
    (This)->lpVtbl -> FastLoad(This,file_name)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_Load_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ BSTR file_name);


void __RPC_STUB IGetAVIInfo_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetName_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *file_name);


void __RPC_STUB IGetAVIInfo_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetVideoStreamNumber_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *num);


void __RPC_STUB IGetAVIInfo_GetVideoStreamNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetAudioStreamNumber_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *num);


void __RPC_STUB IGetAVIInfo_GetAudioStreamNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetVideoStreamInfo_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
    /* [in] */ long size,
    /* [out] */ long __RPC_FAR *ln,
    /* [out] */ long __RPC_FAR *size_info,
    /* [out] */ long __RPC_FAR *size_infoex);


void __RPC_STUB IGetAVIInfo_GetVideoStreamInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetAudioStreamInfo_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *stream_header,
    /* [in] */ long size,
    /* [out] */ long __RPC_FAR *ln,
    /* [out] */ long __RPC_FAR *size_info);


void __RPC_STUB IGetAVIInfo_GetAudioStreamInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetVideoFrameNumber_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [out] */ long __RPC_FAR *frame_count);


void __RPC_STUB IGetAVIInfo_GetVideoFrameNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetAudioChunkNumber_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [out] */ long __RPC_FAR *chunk_count);


void __RPC_STUB IGetAVIInfo_GetAudioChunkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetVideoFrameInfo_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long frame_number,
    /* [out] */ long __RPC_FAR *hi_offset,
    /* [out] */ ULONG __RPC_FAR *low_offset,
    /* [out] */ ULONG __RPC_FAR *size);


void __RPC_STUB IGetAVIInfo_GetVideoFrameInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetAudioChunkInfo_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long chunk_number,
    /* [out] */ long __RPC_FAR *hi_offset,
    /* [out] */ ULONG __RPC_FAR *low_offset,
    /* [out] */ ULONG __RPC_FAR *size);


void __RPC_STUB IGetAVIInfo_GetAudioChunkInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetVideoFormatInfo_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
    /* [in] */ long buf_size,
    /* [out] */ long __RPC_FAR *copy_size);


void __RPC_STUB IGetAVIInfo_GetVideoFormatInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetAudioFormatInfo_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
    /* [in] */ long buf_size,
    /* [out] */ long __RPC_FAR *copy_size);


void __RPC_STUB IGetAVIInfo_GetAudioFormatInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetVideoExtFormatInfo_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *format_info,
    /* [in] */ long buf_size,
    /* [out] */ long __RPC_FAR *copy_size);


void __RPC_STUB IGetAVIInfo_GetVideoExtFormatInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetAudioSampleInfo_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ UINT sample_number,
    /* [out] */ UINT __RPC_FAR *chunk_num,
    /* [out] */ UINT __RPC_FAR *offset);


void __RPC_STUB IGetAVIInfo_GetAudioSampleInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetMainHeader_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *buffer,
    /* [in] */ long buf_size,
    /* [out] */ long __RPC_FAR *copy_size);


void __RPC_STUB IGetAVIInfo_GetMainHeader_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetVideoFrameInfo2_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long frame_number,
    /* [out] */ long __RPC_FAR *hi_offset,
    /* [out] */ ULONG __RPC_FAR *low_offset,
    /* [out] */ ULONG __RPC_FAR *size,
    /* [out] */ ULONG __RPC_FAR *flags);


void __RPC_STUB IGetAVIInfo_GetVideoFrameInfo2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_GetAudioChunkInfo2_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long chunk_number,
    /* [out] */ long __RPC_FAR *hi_offset,
    /* [out] */ ULONG __RPC_FAR *low_offset,
    /* [out] */ ULONG __RPC_FAR *size,
    /* [out] */ ULONG __RPC_FAR *flags);


void __RPC_STUB IGetAVIInfo_GetAudioChunkInfo2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGetAVIInfo_FastLoad_Proxy( 
    IGetAVIInfo __RPC_FAR * This,
    /* [in] */ BSTR file_name);


void __RPC_STUB IGetAVIInfo_FastLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGetAVIInfo_INTERFACE_DEFINED__ */


#ifndef __IGetAVIInfoArray_INTERFACE_DEFINED__
#define __IGetAVIInfoArray_INTERFACE_DEFINED__

/* interface IGetAVIInfoArray */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGetAVIInfoArray;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2B663AC9-1532-4f32-8631-EDBF22440DF4")
    IGetAVIInfoArray : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVideoFramesInfo( 
            /* [in] */ long index,
            /* [in] */ long start_frame,
            /* [in] */ long frames_count,
            /* [size_is][out] */ IndexFileEntry __RPC_FAR *info,
            /* [size_is][out] */ long __RPC_FAR *hi_offset) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAudioChunksInfo( 
            /* [in] */ long index,
            /* [in] */ long start_chunk,
            /* [in] */ long chunks_count,
            /* [size_is][out] */ IndexFileEntry __RPC_FAR *info,
            /* [size_is][out] */ long __RPC_FAR *hi_offset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGetAVIInfoArrayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGetAVIInfoArray __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGetAVIInfoArray __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGetAVIInfoArray __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoFramesInfo )( 
            IGetAVIInfoArray __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long start_frame,
            /* [in] */ long frames_count,
            /* [size_is][out] */ IndexFileEntry __RPC_FAR *info,
            /* [size_is][out] */ long __RPC_FAR *hi_offset);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioChunksInfo )( 
            IGetAVIInfoArray __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long start_chunk,
            /* [in] */ long chunks_count,
            /* [size_is][out] */ IndexFileEntry __RPC_FAR *info,
            /* [size_is][out] */ long __RPC_FAR *hi_offset);
        
        END_INTERFACE
    } IGetAVIInfoArrayVtbl;

    interface IGetAVIInfoArray
    {
        CONST_VTBL struct IGetAVIInfoArrayVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetAVIInfoArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGetAVIInfoArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGetAVIInfoArray_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGetAVIInfoArray_GetVideoFramesInfo(This,index,start_frame,frames_count,info,hi_offset)	\
    (This)->lpVtbl -> GetVideoFramesInfo(This,index,start_frame,frames_count,info,hi_offset)

#define IGetAVIInfoArray_GetAudioChunksInfo(This,index,start_chunk,chunks_count,info,hi_offset)	\
    (This)->lpVtbl -> GetAudioChunksInfo(This,index,start_chunk,chunks_count,info,hi_offset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoArray_GetVideoFramesInfo_Proxy( 
    IGetAVIInfoArray __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long start_frame,
    /* [in] */ long frames_count,
    /* [size_is][out] */ IndexFileEntry __RPC_FAR *info,
    /* [size_is][out] */ long __RPC_FAR *hi_offset);


void __RPC_STUB IGetAVIInfoArray_GetVideoFramesInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IGetAVIInfoArray_GetAudioChunksInfo_Proxy( 
    IGetAVIInfoArray __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long start_chunk,
    /* [in] */ long chunks_count,
    /* [size_is][out] */ IndexFileEntry __RPC_FAR *info,
    /* [size_is][out] */ long __RPC_FAR *hi_offset);


void __RPC_STUB IGetAVIInfoArray_GetAudioChunksInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGetAVIInfoArray_INTERFACE_DEFINED__ */



#ifndef __GETAVIINFOLib_LIBRARY_DEFINED__
#define __GETAVIINFOLib_LIBRARY_DEFINED__

/* library GETAVIINFOLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_GETAVIINFOLib;

EXTERN_C const CLSID CLSID_GetAVIInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("568DF44F-DEAC-11D3-BBEE-0000B4908D28")
GetAVIInfo;
#endif
#endif /* __GETAVIINFOLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
