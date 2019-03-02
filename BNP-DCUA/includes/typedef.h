#ifndef CSS_H
#define CSS_H

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************
* INCLUDES
*/
/*****************************************************************************
* DEFINES
*/
/* Version information */
#ifndef NULL
#define NULL ((void *)0) /* Used for pointers */
#endif
#ifndef TRUE
#define TRUE (0==0) /* Boolean True */
#endif
#ifndef FALSE
#define FALSE (0!=0) /* Boolean False */
#endif
#ifndef NOT
#define NOT !
#endif
#ifndef AND
#define AND &&
#endif
#ifndef OR
#define OR ||
#endif
#ifndef OK
#define OK 0
#endif
#ifndef ERROR
#define ERROR (-1)
#endif

#ifndef INVALID
#define INVALID 1
#endif
#ifndef FAST
#define FAST register
#endif
#ifndef IMPORT
#define IMPORT extern
#endif
#ifndef LOCAL
#define LOCAL static
#endif
/* OS member header identification */
#define MAGIC_WORD "AS-1000"
#define MAGIC_WORD_SIMON "AS-1000"
#define MAGIC_WORD_RTS "AS-1100"
#define RESERVED_BC 0x0 /* Bootcode Jumptable */
#define SUBPROJECT_BC 0x3 /* Bootcode Jumptable */
#define JUMP_TABLE_OFFSET 0x10
#define SERVICE_AE (JUMP_TABLE_OFFSET + 1)
#define SERVICE_DR (JUMP_TABLE_OFFSET + 2)
#define SERVICE_EH (JUMP_TABLE_OFFSET + 3)
#define SERVICE_MON (JUMP_TABLE_OFFSET + 4)
#define SERVICE_MT (JUMP_TABLE_OFFSET + 5)
#define SERVICE_TNM (JUMP_TABLE_OFFSET + 6)
#define SERVICE_OS (JUMP_TABLE_OFFSET + 7)
#define SERVICE_PS (JUMP_TABLE_OFFSET + 8)
#define SERVICE_TCN (JUMP_TABLE_OFFSET + 9)
#define SERVICE_SE (JUMP_TABLE_OFFSET + 10)
#define SERVICE_DM (JUMP_TABLE_OFFSET + 11)
#define SERVICE_PIL (JUMP_TABLE_OFFSET + 12)
#define SERVICE_LED (JUMP_TABLE_OFFSET + 13)
#define SERVICE_AS (JUMP_TABLE_OFFSET + 14)
#define SERVICE_ANSI (JUMP_TABLE_OFFSET + 15)
#define SERVICE_TS (JUMP_TABLE_OFFSET + 16)
#define SERVICE_IP (JUMP_TABLE_OFFSET + 17)
#define SERVICE_EE (JUMP_TABLE_OFFSET + 20)
#define SERVICE_HI (JUMP_TABLE_OFFSET + 21)
#define SERVICE_DSP (JUMP_TABLE_OFFSET + 22)
#define SERVICE_FPGA (JUMP_TABLE_OFFSET + 23)
#define SERVICE_SPI (JUMP_TABLE_OFFSET + 24)
#define SERVICE_VCU (JUMP_TABLE_OFFSET + 30)
#define SERVICE_VCUL (JUMP_TABLE_OFFSET + 31)

#define SERVICE_COMC (JUMP_TABLE_OFFSET + 32)
#define SERVICE_VCU6U (JUMP_TABLE_OFFSET + 33)
#define SERVICE_ICON (JUMP_TABLE_OFFSET + 34)
#define SERVICE_DCU (JUMP_TABLE_OFFSET + 35)
#define SERVICE_DCU_IO (JUMP_TABLE_OFFSET + 36)
#define SERVICE_VCU_LITE (JUMP_TABLE_OFFSET + 37)
/* Define location for indirect call entry point */
#define DISPLC 2
#define BC_PRV_ADR_TABLE (JMP_TABLE_BASE + (RESERVED_BC << DISPLC))
#define BC_ADR_TABLE (JMP_TABLE_BASE + (SUBPROJECT_BC << DISPLC))
#define AE_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_AE << DISPLC))
#define DR_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_DR << DISPLC))
#define EH_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_EH << DISPLC))
#define MON_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_MON << DISPLC))
#define MT_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_MT << DISPLC))
#define TNM_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_TNM << DISPLC))
#define OS_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_OS << DISPLC))
#define PS_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_PS << DISPLC))
#define TCN_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_TCN << DISPLC))
#define SE_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_SE << DISPLC))
#define DM_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_DM << DISPLC))
#define PIL_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_PIL << DISPLC))
#define LED_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_LED << DISPLC))
#define AS_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_AS << DISPLC))
#define ANSI_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_ANSI << DISPLC))
#define TS_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_TS << DISPLC))
#define SV_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_SV << DISPLC))
#define IP_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_IP << DISPLC))
#define EE_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_EE << DISPLC))
#define HI_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_HI << DISPLC))
#define DSP_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_DSP << DISPLC))
#define FPGA_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_FPGA << DISPLC))
#define SPI_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_SPI << DISPLC))
#define VCU_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_VCU << DISPLC))
#define VCUL_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_VCUL << DISPLC))
#define VCU_LITE_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_VCU_LITE << DISPLC))
#define COMC_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_COMC << DISPLC))
#define VCU6U_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_VCU6U << DISPLC))
#define ICON_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_ICON << DISPLC))
#define DCU_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_DCU << DISPLC))
#define DCU_IO_ADR_TABLE (JMP_TABLE_BASE + (SERVICE_DCU_IO << DISPLC))
/* Reset reasons */
#define RESET_POWER_UP 0
#define RESET_RUN 1
#define RESET_IDLE 2
#define RESET_DOWNLOAD 3

#define RESET_ERROR_STDL 4
#define RESET_ERROR 5
#define RESET_TEST 6
#define RESET_WATCHDOG 7
#define RESET_DOUBLEBUSFAULT 8
#define RESET_LOSSOFCLOCK 9
#define RESET_LOCAL 10
/* led bits used with function bc_led_set */
#define LED_MMI_FLT ((UINT16)0x0001) /* mmi fault indicator LED */
#define LED_ER ((UINT16)0x0002) /* red error LED */
#define LED_WA ((UINT16)0x0004) /* yellow warning LED */
#define LED_MVB ((UINT16)0x0008) /* green MVB LED */
#define LED_OK ((UINT16)0x0010) /* green system LED */
/* Hardware mode switch, defines boot behaviour */
#define BOOT_MODE_0 0
#define BOOT_MODE_1 1
#define BOOT_MODE_2 2
#define BOOT_MODE_3 3
/* network interface type */
#define NETIF_NONE 0 /* no network interface available */
#define NETIF_M9_LN 1 /* M9 Module (LANCE chip) */
#define NETIF_ECI_QU 2 /* PBI Extended Communication IF (68EN360 QUICC) */
#define NETIF_SER_SL 3 /* Serial line (SLIP) */
/*****************************************************************************
* TYPEDEFS
*/
/* Basic types used for all derived types */
#ifndef __INCvxTypesOldh
#ifdef O_16BIT /* Support for 16bit compilers */
typedef char INT8;
typedef short INT16;
typedef long INT32;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned long UINT32;
typedef unsigned char UCHAR;
typedef unsigned short USHORT;
typedef unsigned int UINT;
typedef unsigned long ULONG;

typedef long BOOL;
typedef long STATUS;
typedef long ARGINT;
typedef void VOID;
#ifdef __cplusplus
typedef long (*FUNCPTR) (...); /* ptr to function returning int */
typedef void (*VOIDFUNCPTR) (...); /* ptr to function returning void */
typedef double (*DBLFUNCPTR) (...); /* ptr to function returning double*/
typedef float (*FLTFUNCPTR) (...); /* ptr to function returning float */
#else
typedef int (*FUNCPTR) (); /* ptr to function returning int */
typedef void (*VOIDFUNCPTR) (); /* ptr to function returning void */
typedef double (*DBLFUNCPTR) (); /* ptr to function returning double*/
typedef float (*FLTFUNCPTR) (); /* ptr to function returning float */
#endif /* _cplusplus */
typedef unsigned char BYTE;
typedef unsigned char CHAR;
typedef unsigned short WORD;
typedef unsigned long DWORD;
#else
typedef char INT8;
typedef short INT16;
typedef int INT32;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned char UCHAR;
typedef unsigned short USHORT;
typedef unsigned int UINT;
typedef unsigned long ULONG;
typedef int BOOL;
typedef int STATUS;
typedef int ARGINT;
typedef void VOID;
#ifdef __cplusplus
typedef int (*FUNCPTR) (...); /* ptr to function returning int */
typedef void (*VOIDFUNCPTR) (...); /* ptr to function returning void */
typedef double (*DBLFUNCPTR) (...); /* ptr to function returning double*/
typedef float (*FLTFUNCPTR) (...); /* ptr to function returning float */

#else
typedef int (*FUNCPTR) (); /* ptr to function returning int */
typedef void (*VOIDFUNCPTR) (); /* ptr to function returning void */
typedef double (*DBLFUNCPTR) (); /* ptr to function returning double*/
typedef float (*FLTFUNCPTR) (); /* ptr to function returning float */
#endif /* _cplusplus */
typedef unsigned char BYTE;
typedef unsigned char CHAR;
typedef unsigned short WORD;
typedef unsigned int DWORD;
#endif /* O_16BIT */
#else
typedef unsigned char BYTE;
typedef unsigned char CHAR;
typedef unsigned short WORD;
typedef unsigned int DWORD;
#endif /* __INCvxTypesOldh */
/* version info */
typedef struct STR_VERSION_INFO
{
BYTE ver;
BYTE rel;
BYTE upd;
BYTE evo;
} VERSION_INFO;
/* DLU member header */
/* Each DLU text segment must start with an instance of VM_HEADER */
typedef struct STR_VM_HEADER
{
DWORD checksum;
DWORD crc32;
DWORD size;
DWORD p_code_start;
CHAR magic_word[8];
VERSION_INFO version;
CHAR name[16];
DWORD date;
DWORD type;
CHAR filename[32];
CHAR product_name[16];
CHAR comment[120];
VERSION_INFO tool_version;
CHAR tool_name[16];
BYTE padding[16];
} VM_HEADER;

#ifdef __cplusplus
}
#endif

#endif /* CSS_H */

#ifndef TYPEDEF_H
#define TYPEDEF_H
//#ifdef NEJNEJNEJ
typedef struct OS_STR_TIMEDATE48
{
UINT32 seconds;
UINT16 ticks;
} OS_TIMEDATE48;
//#endif
#endif

#ifndef _MITRACLIB_H
#define _MITRACLIB_H
/*---------------------------------------------------------------------------
Includes
-----------------------------------------------------------------------------*/
#ifndef TARGET_SIM_DLL
/* #include "rts_api.h" */
#endif
/*---------------------------------------------------------------------------
Typedefs
-----------------------------------------------------------------------------*/
typedef INT16 CC_ANALOG;
typedef UINT8 CC_BCD4;
typedef INT16 CC_BIFRACT200;
typedef UINT16 CC_BITSET256[16];
typedef UINT8 CC_BOOL;
typedef UINT8 CC_BOOLEAN2;
typedef BYTE CC_BYTE;
typedef UINT32 CC_DATE;
typedef struct dt {UINT32 date; UINT16 ms;} CC_DATE_AND_TIME;
typedef INT32 CC_DINT;
typedef DWORD CC_DWORD;
typedef UINT8 CC_ENUM4;
typedef INT32 CC_FIXED;
typedef INT16 CC_INT;
typedef float CC_REAL;
typedef INT8 CC_SINT;
typedef char CC_STRING[81];
typedef INT32 CC_TIME;
typedef OS_TIMEDATE48 CC_TIMEDATE48;
typedef INT32 CC_TIME_OF_DAY;
typedef UINT32 CC_UDINT;
typedef UINT16 CC_UINT;
typedef UINT16 CC_UNIFRACT;
typedef UINT8 CC_USINT;
typedef WORD CC_WORD;
/*---------------------------------------------------------------------------
Floating point library prototypes
-----------------------------------------------------------------------------*/
#ifndef __POWER_PC__
extern CC_REAL add_REAL(CC_REAL a, CC_REAL b); /* return a + b */
extern CC_REAL sub_REAL(CC_REAL a, CC_REAL b); /* return a - b */
extern CC_REAL mul_REAL(CC_REAL a, CC_REAL b); /* return a * b */
extern CC_REAL div_REAL(CC_REAL a, CC_REAL b); /* return a / b */
extern CC_REAL neg_REAL(CC_REAL a); /* return - a */
extern CC_BOOL eq_REAL(CC_REAL a, CC_REAL b); /* return a == b */
extern CC_BOOL ne_REAL(CC_REAL a, CC_REAL b); /* return a != b */
extern CC_BOOL lt_REAL(CC_REAL a, CC_REAL b); /* return a < b */
extern CC_BOOL le_REAL(CC_REAL a, CC_REAL b); /* return a <= b */
extern CC_BOOL gt_REAL(CC_REAL a, CC_REAL b); /* return a > b */
extern CC_BOOL ge_REAL(CC_REAL a, CC_REAL b); /* return a >= b */
extern CC_REAL abs_REAL(CC_REAL a);
extern CC_REAL sin_REAL(CC_REAL a);
extern CC_REAL cos_REAL(CC_REAL a);
extern CC_REAL tan_REAL(CC_REAL a);
extern CC_REAL asin_REAL(CC_REAL a);
extern CC_REAL acos_REAL(CC_REAL a);
extern CC_REAL atan_REAL(CC_REAL a);
extern CC_REAL sqrt_REAL(CC_REAL a);
extern CC_REAL exp_REAL(CC_REAL a);
extern CC_REAL ln_REAL(CC_REAL a);
extern CC_REAL log_REAL(CC_REAL a);
extern CC_REAL min_REAL(CC_REAL a, CC_REAL b);
extern CC_REAL max_REAL(CC_REAL a, CC_REAL b);
extern CC_REAL BOOL_to_REAL(CC_BOOL a);
extern CC_REAL DINT_to_REAL(CC_DINT a);
extern CC_REAL INT_to_REAL(CC_INT a);
extern CC_REAL FIXED_to_REAL(CC_FIXED a);
extern CC_REAL SINT_to_REAL(CC_SINT a);
extern CC_ANALOG REAL_to_ANALOG(CC_REAL a); /* round to nearest */
extern CC_DINT REAL_to_DINT(CC_REAL a); /* round to nearest */
extern CC_FIXED REAL_to_FIXED(CC_REAL a); /* round to nearest */
extern CC_INT REAL_to_INT(CC_REAL a); /* round to nearest */
extern CC_SINT REAL_to_SINT(CC_REAL a); /* round to nearest */
extern CC_DINT trunc_DINT(CC_REAL a); /* truncate to zero */
extern CC_INT trunc_INT(CC_REAL a); /* truncate to zero */
extern CC_SINT trunc_SINT(CC_REAL a); /* truncate to zero */
extern CC_REAL expt_REAL(CC_REAL a, CC_REAL b); /* return a ** b */
extern CC_REAL expt_DINT(CC_REAL a, CC_DINT b); /* return a ** b */
extern CC_REAL expt_UDINT(CC_REAL a, CC_UDINT b); /* return a ** b */
#endif
/*---------------------------------------------------------------------------
IEC 1131 support functions
-----------------------------------------------------------------------------*/
void BATTR (CC_INT* errorCode, CC_UINT* voltage);
CC_UDINT ELAPSED (void);

CC_UINT LARST (void);
CC_WORD MVB_ADDRESS(void);
CC_WORD MVB_STATUS (void);
void RESET (CC_BOOL trigger);
void RTC (CC_BOOL enable, CC_UDINT pdt, CC_BOOL* q, CC_UDINT* et);
void SEMA (CC_BOOL claim, CC_BOOL release, CC_BOOL* x, CC_BOOL* busy);
void SHUTD (CC_BOOL trigger);
void STALL (CC_BOOL trigger, CC_BOOL* previous);
void TEMP (CC_INT* error, CC_UINT* countDown, CC_INT* temperature);
/*---------------------------------------------------------------------------
DCU support functions
-----------------------------------------------------------------------------*/
void Z_DCU_IO_READ (CC_USINT* data, CC_INT* error);
void Z_DCU_IO_WRITE (CC_USINT data , CC_USINT* data_rb, CC_INT* error);
void Z_DCU_IRQ5_FLAG (CC_UINT* powf, CC_INT* irq5_flag, CC_INT* error);
void Z_DCU_READ_DSP_WD_FLAG (CC_INT* wd_flag , CC_INT* error);
void Z_DCU_READ_DSP_WD_FLAG (CC_INT* wd_flag, CC_INT* error);
void Z_DCU_READ_LINE_TRIP_FB (CC_INT* line_trip_fb , CC_INT* error);
void Z_DCU_READ_OPTO_EN (CC_INT* opto_en_fb , CC_INT* error);
void Z_DCU_READ_OUTPUT_EN (CC_INT* output_en_fb , CC_INT* error);
void Z_DCU_READ_RESET_IND (CC_INT* reset_ind , CC_INT* error);
void Z_DCU_READ_SPEED_SUP_FLAG (CC_INT* speed_flag , CC_INT* error);
void Z_DCU_READ_TRAC_SAFE (CC_INT* trac_safe_en, CC_INT* error);
void Z_DCU_READ_VERSION_ID (CC_USINT* map_ID, CC_USINT* map_detect, CC_USINT* exp_ID,
CC_USINT* opto_ID , CC_USINT* base_ID, CC_INT* error);
void Z_DCU_RESET_STALL_ALARM (CC_INT* error);
void Z_DCU_SELECT_PWM (CC_USINT clock_source , CC_INT* error);
void Z_DCU_SET_5V_OVP (CC_INT activ , CC_INT* error);
void Z_DCU_SET_EXT_BLOCK (CC_INT block , CC_INT* error);
void Z_DCU_SET_HIGHTEST (CC_INT activ , CC_INT* error);
void Z_DCU_SET_LINE_TRIP_EN (CC_INT enable , CC_INT* error);
void Z_DCU_SET_OUTPUT_EN (CC_INT enable , CC_INT* error);
void Z_DCU_DSP_APPLICATION (CC_UINT start, CC_INT* error);
void Z_DCU_DSP_LOAD (CC_INT* error);
CC_INT Z_DCU_DSP_PUT_DATA (CC_INT* data);
CC_INT Z_DCU_DSP_READ_DATA (CC_INT* data);
void Z_DCU_DSP_READ_ERROR_WORDS (CC_UINT* error_word, CC_INT* error_flag, CC_INT* error);
void Z_DCU_DSP_READ_SV_WORD (CC_UDINT* super_word, CC_INT* error);
void Z_DCU_DSP_WRITE_SV_WORD (CC_UDINT super_word, CC_INT* error);
void Z_DCU_FPGA_LOAD (CC_INT* error);
void Z_DCU_READ_BATTERY_VOLTAGE (CC_UINT channel, CC_INT* voltage, CC_INT* error);
void Z_DCU_READ_ON_BOARD_TEMP (CC_INT* temp, CC_INT* error);
void Z_DCU_READ_TEMP (CC_UINT channel, CC_INT* temp, CC_INT* error);
void Z_DCU_SET_TRIP_LEVEL (CC_UINT channel, CC_INT trip_level, CC_INT* error);
/*---------------------------------------------------------------------------
String handling functions
-----------------------------------------------------------------------------*/
#ifndef __POWER_PC__
void SFB0019(char* dst, CC_INT len, char* src); /* LEFT */

void SFB0020(char* dst, CC_INT len, char* src); /* RIGHT */
void SFB0021(char* dst, CC_INT pos, CC_INT len, char* src); /* MID */
void SFB0022(char* dst, char* src2, char* src1); /* CONCAT */
void SFB0023(char* dst, CC_INT pos, char* ins, char* src); /* INSERT */
void SFB0024(char* dst, CC_INT pos, CC_INT len, char* src); /* DELETE */
void SFB0025(char* dst, CC_INT pos, CC_INT len, char* ins, char* src); /* REPLACE */
CC_INT SFB0026(char* ins, char* src); /* FIND */
void SFB0027(char* dst, char* src); /* MOVE */
CC_INT SFB0030(char* src); /* LEN */
CC_BOOL EQ_STRING(char* src2, char* src1);
CC_BOOL GE_STRING(char* src2, char* src1);
CC_BOOL GT_STRING(char* src2, char* src1);
CC_BOOL LE_STRING(char* src2, char* src1);
CC_BOOL LT_STRING(char* src2, char* src1);
CC_BOOL NE_STRING(char* src2, char* src1);
#endif
/*--------------------------------------------------------------------------*/
#endif /* _MITRACLIB_H */

#ifndef MWT_TYPES_H
#define MWT_TYPES_H
typedef CC_ANALOG MWT_ANALOG;
typedef CC_BCD4 MWT_BCD4;
typedef CC_BIFRACT200 MWT_BIFRACT200;
typedef CC_BOOL MWT_BOOL;
typedef CC_BOOLEAN2 MWT_BOOLEAN2;
typedef CC_BYTE MWT_BYTE;
typedef CC_DATE MWT_DATE;
typedef CC_DATE_AND_TIME MWT_DATE_AND_TIME;
typedef CC_DINT MWT_DINT;
typedef CC_DWORD MWT_DWORD;
typedef CC_ENUM4 MWT_ENUM4;
typedef CC_FIXED MWT_FIXED;
typedef CC_INT MWT_INT;
typedef CC_REAL MWT_REAL;
typedef CC_SINT MWT_SINT;
typedef CC_STRING MWT_STRING;
typedef CC_TIME MWT_TIME;
typedef CC_TIME_OF_DAY MWT_TIME_OF_DAY;
typedef CC_TIMEDATE48 MWT_TIMEDATE48;
typedef CC_UDINT MWT_UDINT;
typedef CC_UINT MWT_UINT;
typedef CC_UNIFRACT MWT_UNIFRACT;
typedef CC_USINT MWT_USINT;
typedef CC_WORD MWT_WORD;
#endif /* MWT_TYPES_H */

/*typedef float FLOAT32 ;*/
/*typedef void UNTYPED ;*/
typedef INT16 INT ;
