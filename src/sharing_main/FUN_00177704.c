/* HSTMATCH module=hstp_trans_main.prx start=0x00177704 end=0x00177714 symbol=FUN_00177704 lang=c99 */
/* Clone of src/eboot/FUN_0016b540.c (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_003eb046;

bool FUN_00177704(void)
{
  return DAT_003eb046 != '\0';
}
