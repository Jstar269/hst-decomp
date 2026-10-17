/* HSTMATCH module=hstp_trans_main.prx start=0x001f8dac end=0x001f8dbc symbol=FUN_001f8dac lang=c99 */
/* Clone of src/eboot/FUN_001eab08.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


bool FUN_001f8dac(int *param_1)
{
  return *(int *)(*param_1 + 0x3e4) != 0;
}
