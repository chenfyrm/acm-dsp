/*
*============================================================================
**
FILE NAME: dspBinFile.h (SymbFile.h)
*
*----------------------------------------------------------------------------
**
DESCRIPTION: Header file for symbol info file
*
*----------------------------------------------------------------------------
**
AUTHOR: Anders Elgcrona/Elgcrona Teknik AB
*
*----------------------------------------------------------------------------
**
DATE: 2005-01-17
*
*----------------------------------------------------------------------------
**
REVISION: 0.4
*
*----------------------------------------------------------------------------
**
HCTOOLS VER: 1.0.1.0
*
*----------------------------------------------------------------------------
**
COPYRIGHT Bombardier Inc., 2005
**
This document must not be copied without our written
* permission, and the contents thereof must not be
* imparted to a third party nor be used for any
* unauthorized purpose.
* Contravention will be prosecuted.
*
*============================================================================
*/
/*
*============================================================================
**
INCLUDE FILES
*
*============================================================================
*/
/*
*============================================================================
**
MACRO DEFINES
*
*============================================================================
*/
#define SYMB_FILE_VERSION 1
#define TYPES_TAB_NO 0
#define ELEMENTS_TAB_NO 1
#define SYMBOLS_TAB_NO 2
#define STRINGS_TAB_NO 3
#define COMAREA_ENTRIES 26 /* no of entries in ComArea */
#define CA_MCU2DSP_IX 1 /* index for signalbuffer from MCU to DSP */
#define CA_DSP2MCU0_IX 2 /* index for signalbuffer 0 from DSP to MCU */
#define CA_DSP2MCU1_IX 3 /* index for signalbuffer 1 from DSP to MCU */
#define CA_SIGBUF_IX 4 /* index pointing out the current DSP2MCU-buffer */
#define CA_MCUPAR2DSP_IX 5 /* index for parameter buffer from MCU to DSP */
#define CA_LOGSTR_IX 6 /* index for sw/hw log struct */
/*
*============================================================================
**
TYPE DEFINITIONS
*
*============================================================================
*/
/*
The following segment describes the layout of the binary file containing
the load data for the DSP.
The different structures applied in the layout are defined in this file.
size in bytes
+----------------+
32 | File header | version, no of tables, and total size of file
+----------------+
32 | Table header | no of symbol info, load data info, config data info, and com area tables
+----------------+
12 | Symbol info | offset within file to raw data, no of elements, and size of table
| table 1 |
+----------------+
: :
+----------------+
12 | Symbol info |
| table n |
+----------------+
12 | Comm buffer | address in dsp and size of area
| area 1 |
+----------------+
: :
+----------------+
12 | Comm buffer |
| area 26 |
+----------------+
12 | Config data | offset within file to raw data, and size of table
| info table 1 |
+----------------+
: :
+----------------+
12 | Config data |
| info table n |
+----------------+
12 | Load data info | offset within file to raw data, target address, and size of table
| table 1 |
+----------------+
: :
+----------------+
12 | Load data info |
| table n |
+----------------+
: :
: :
: Raw data :
: :
: :
+----------------+
The raw data containing configuration data consists of a target address and the
corresponding data to store there.
*/
typedef struct
{
UINT32 versionNo;
UINT32 noTables;
UINT32 totFileSize;
UINT32 reserved[5];
} FILE_HEADER;
typedef struct
{
UINT32 noSymbInfoTables;
UINT32 noLoadDataTables;
UINT32 noConfigDataTables;
UINT32 noComAreaTables;
UINT32 reserved[4];
} TABLE_HEADER;
typedef struct
{
UINT32 dataOffset;
UINT32 noElements;
UINT32 totSize;
} SYMB_INFO_TABLE;
typedef struct
{
UINT32 dataOffset;
UINT32 loadAddress;
UINT32 totSize;
} LOAD_DATA_TABLE;
typedef struct
{
UINT32 dataOffset;
UINT32 reserved;
UINT32 totSize;
} CONFIG_DATA_TABLE;
typedef struct
{
UINT32 dataOffset;
UINT32 noElements;
UINT32 totSize;
} COM_AREA_TABLE;
typedef struct
{
UINT32 address;
UINT32 data;
} CONFIG_DATA_STRUCT;
typedef struct
{
UINT32 address;
UINT32 size;
} COM_AREA_STRUCT;
/*
*============================================================================
**
END OF FILE
*
*============================================================================
*/
