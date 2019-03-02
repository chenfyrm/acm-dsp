#include "C_ToUNXTime.h"
#include "os_api.h"
#include "css.h"
/************************************************************************
Abstract: This function converts time in Y-M-D h:m:s format to UNIX time.
That is the number of seconds since 1970-01-01 00:00:00.
************************************************************************/
void C_ToUNXTime(TYPE_C_TOUNXTIME_IF *interface)
{
OS_STR_TIME_POSIX unix_time;
OS_STR_TIME_ANSI ansi_time;
UINT32 msb_temp;
MWT_TIMEDATE48 t;
UINT16* p;
t = interface->Time;
p = (UINT16*)&t;
ansi_time.tm_year = ((*p & 0xff00)>>8) + 100;
ansi_time.tm_mon = (*p & 0x00ff) - 1;
p++;
ansi_time.tm_mday = (*p & 0xff00)>>8;
ansi_time.tm_hour = (*p & 0x00ff);
p++;
ansi_time.tm_min = (*p & 0xff00)>>8;
ansi_time.tm_sec = (*p & 0x00ff);
/************************************************************************
mon_broadcast_printf("%d-%d-%d %d:%d:%d\n",ansi_time.tm_year,ansi_time.tm_mon,ansi_time.tm_mday,ansi_time.tm_hour,ansi_time.tm_min,ansi_time.tm_sec);
************************************************************************/
os_c_mktime(&ansi_time, &unix_time.sec);
interface->C_X_ToUnixLsb = (UINT16)(unix_time.sec & 0xffff);
msb_temp = unix_time.sec & 0xffff0000;
interface->C_X_ToUnixMsb = (UINT16)(msb_temp >> 16);
}
