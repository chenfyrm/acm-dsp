/*****************************************************************************
* COPYRIGHT : (c) 2008 Bombardier Transportation BTPC
*****************************************************************************
**
MODULE : dummy_iptcom.c
**
ABSTRACT : Resource 'dummy_iptcom'
**
CREATOR : PPC/TEDT Heiko Barth
**
REMARKS : Dummy functions to resolve IPTCom dependencies.
*
****************************************************************************/
/*lint -e818 Pointer parameter '...' (line ...) could be declared
as pointing to const
Violating BOMBARDIER RULE 120
*/
/*lint -e912 Implicit binary conversion from int to unsigned int
Violating BOMBARDIER RULE 90 (R)
*/
/*lint -e915 Implicit conversion (return) unsigned int to int
Violating BOMBARDIER RULE 82 (M),84 (R),90 (R)
*/
/*lint -e921 cast from int to unsigned int
Violating BOMBARDIER RULE 88 (R)
*/
/*lint -e957 Function '...' defined without a prototype in scope
Violating BOMBARDIER RULE 112 (M)
*/
/*lint -e961 Violates MISRA Advisory Rule 18,
Numerical constant requires suffix
Violating BOMBARDIER RULE
M18:59;M40:79;M44:85;M47:77,89;M55:96,97;M63:103;M92:153
*/
/*lint -e970 Use of modifier or type '...' outside of a typedef
Violating BOMBARDIER Rule 53 (M)
*/
/*lint -e971 Use of 'char' without 'signed' or 'unsigned'
Violating BOMBARDIER Rule 54 (M)
*/
/*! \name Basic Data Types, e.g. from the CSS API (css.h).
*/
/*{*/
/* Basic types, for 32bit compilers */
typedef unsigned char BYTE;
typedef unsigned short UINT16;
typedef unsigned int UINT32;

/*}*/
/*! \name IPTCom Common API (iptcom.h).
*/
/*{*/
/* Error code: type definitions */
#define TYPE_WARNING 0x40000000
#define TYPE_ERROR 0x80000000
#define TYPE_EXCEPTION 0xc0000000
/* Error code: IPTCom function definitions */
#define ERR_IPTVCOM 0x00030000
#define IPTCOM_COINST 0
#define IPTCOM_COID 3
#define ERR_TDCCOM 0x00040000
/* Error code: global/local definitions */
#define ERR_LOCAL 0x00008000
/* Error codes */
#define IPT_OK 0 /* General OK value */
#define IPT_ERROR (TYPE_EXCEPTION | ERR_IPTVCOM | ERR_LOCAL | 0x65) /* General error value */
/*}*/
/*! \name IPTCom Message Data API (mdcom.h).
*/
/*{*/
#define MD_URILEN 101
/* Return codes from methods */
#define MD_QUEUE_EMPTY 0 /* Queue is currently empty */
#define MD_QUEUE_NOT_EMPTY 1 /* Queue is currently empty */
typedef UINT32 MD_QUEUE;
typedef struct
{
UINT32 comId; /* ComID */
UINT16 msgType; /* Message type, MD_MSGTYPE_* */
void *pCallerRef; /* Caller reference */
UINT32 sessionId; /* Session identification */
UINT32 srcIpAddr; /* Source IP address */
int resultCode; /* Communication result code */
int noOfResponses; /* Number of responses */
UINT16 userStatus; /* User status from response msg */
UINT32 responseTimeout; /* Timeout for receiving response msg after sending of a request msg */
UINT32 topoCnt; /* Topo count value of received messages */
char destURI[MD_URILEN+1]; /* Destination URI string */
char srcURI[MD_URILEN+1]; /* Source URI string */
} MSG_INFO;
/* Function pointer to application receive function */
typedef void (*IPT_REC_FUNCPTR) (const MSG_INFO *pMsgInfo,
const char *pData,
UINT32 dataLength);
int MDComAPI_addUriListenerF( IPT_REC_FUNCPTR func,
const void *pCallerRef,
const char *pDestURI);
int MDComAPI_freeBuf( char *pBuf);
int MDComAPI_putResponseMsg( UINT32 comId,
UINT16 userStatus,
const char *pData,
UINT32 dataLength,
UINT32 sessionID,
UINT32 topoCnt,
UINT32 destIpAddr,
const char *pDestURI,
const char *pSrcURI);
int MDComAPI_putRequestMsgF( UINT32 comId,
const char *pData,
UINT32 DataLength,
UINT16 NoOfResponses,
UINT32 ResponseTimeout,
IPT_REC_FUNCPTR func,
const void *pCallerRef,
UINT32 topoCnt,
const char *pDestURI,
const char *pSrcURI);
int MDComAPI_getMsg(MD_QUEUE queue,
MSG_INFO *pMsgInfo,
char **ppData,
UINT32 *pDataLength,
int timeOut);
int MDComAPI_addUriListenerQ(MD_QUEUE listenerQueueId,
const void *pCallerRef,
const char *pDestURI);
int MDComAPI_putRequestMsgQ(UINT32 comId,
const char *pData,
UINT32 DataLength,
UINT16 NoOfResponses,
UINT32 ResponseTimeout,
MD_QUEUE CallerQueue,
const void *pCallerRef,
UINT32 topoCnt,
const char *pDestURI,
const char *pSrcURI);
/*}*/
/*! \name IPTCom Process Data API (mdcom.h).
*/
/*{*/
typedef UINT32 PD_HANDLE;
PD_HANDLE PDComAPI_subscribe( UINT32 schedGrp,
UINT32 comId,
const char *source);
PD_HANDLE PDComAPI_publish( UINT32 schedGrp,
UINT32 comId,
const char *dest);
int PDComAPI_getWStatus( PD_HANDLE handle,
BYTE *pBuffer,
UINT16 bufferSize,
int *pInValid);
int PDComAPI_get( PD_HANDLE handle,
BYTE *pBuffer,
UINT16 bufferSize);
void PDComAPI_put( PD_HANDLE handle,
const BYTE *pBuffer);
void PDComAPI_unsubscribe( PD_HANDLE *pHandle);
void PDComAPI_unpublish( PD_HANDLE *pHandle);
void PDComAPI_sink( UINT32 schedGrp);
void PDComAPI_source( UINT32 schedGrp);
/*}*/
/*! \name IPTCom Virtual Operating System API (vos.h).
*/
/*{*/
UINT32 IPTVosGetUniqueNumber(void);
/*}*/
int MDComAPI_addUriListenerF( IPT_REC_FUNCPTR func,
const void *pCallerRef,
const char *pDestURI)
{
return IPT_OK;
}
int MDComAPI_freeBuf(char *pBuf)
{
return IPT_OK;
}
int MDComAPI_putResponseMsg( UINT32 comId,
UINT16 userStatus,
const char *pData,
UINT32 dataLength,
UINT32 sessionID,
UINT32 topoCnt,
UINT32 destIpAddr,
const char *pDestURI,
const char *pSrcURI)
{
return IPT_ERROR;
}
int MDComAPI_putRequestMsgF( UINT32 comId,
const char *pData,
UINT32 DataLength,
UINT16 NoOfResponses,
UINT32 ResponseTimeout,
IPT_REC_FUNCPTR func,
const void *pCallerRef,
UINT32 topoCnt,
const char *pDestURI,
const char *pSrcURI)
{
return IPT_ERROR;
}
int MDComAPI_getMsg(MD_QUEUE queue,
MSG_INFO *pMsgInfo,
char **ppData,
UINT32 *pDataLength,
int timeOut)
{
return MD_QUEUE_EMPTY;
}
int MDComAPI_addUriListenerQ(MD_QUEUE listenerQueueId,
const void *pCallerRef,
const char *pDestURI)
{
return IPT_OK;
}
int MDComAPI_putRequestMsgQ(UINT32 comId,
const char *pData,
UINT32 DataLength,
UINT16 NoOfResponses,
UINT32 ResponseTimeout,
MD_QUEUE CallerQueue,
const void *pCallerRef,
UINT32 topoCnt,
const char *pDestURI,
const char *pSrcURI)
{
return IPT_ERROR;
}
MD_QUEUE MDComAPI_createQueue(int noOfMsg)
{
static MD_QUEUE queue = ((MD_QUEUE)0);
return ++queue;
}
PD_HANDLE PDComAPI_subscribe(UINT32 schedGrp, UINT32 comId, const char *source)
{
static PD_HANDLE handle = ((PD_HANDLE)0);
return ++handle;
}
PD_HANDLE PDComAPI_publish(UINT32 schedGrp, UINT32 comId, const char *dest)
{
static PD_HANDLE handle = ((PD_HANDLE)0);
return ++handle;
}
int PDComAPI_getWStatus(PD_HANDLE handle, BYTE *pBuffer, UINT16 bufferSize,
int *pInValid)
{
if(pInValid)
{
(*pInValid) = 2;
}
return IPT_OK;
}
int PDComAPI_get(PD_HANDLE handle, BYTE *pBuffer, UINT16 bufferSize)
{
int invalid = 2;
return PDComAPI_getWStatus(handle, pBuffer, bufferSize, &invalid);
}
void PDComAPI_put(PD_HANDLE handle, const BYTE *pBuffer)
{}
void PDComAPI_unsubscribe(PD_HANDLE *pHandle)
{
if(pHandle)
{
(*pHandle) = 0;
}
}
void PDComAPI_unpublish(PD_HANDLE *pHandle)
{
if(pHandle)
{
(*pHandle) = 0;
}
}
void PDComAPI_sink(UINT32 schedGrp)
{}
void PDComAPI_source(UINT32 schedGrp)
{}
UINT32 IPTVosGetUniqueNumber( void)
{
static UINT32 n = 0;
return ++n;
}
/* Module interface dummy function */
void dummy_iptcom(void);
void dummy_iptcom(void)
{}
/*! \file
\brief Dummy functions to resolve IPTCom dependencies.
\author Heiko Barth (Bombardier Transportation PPC/TEDT)
*/
