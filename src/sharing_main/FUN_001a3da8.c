/* HSTMATCH module=hstp_trans_main.prx start=0x001a3da8 end=0x001a3db4 symbol=FUN_001a3da8 lang=c99 */
/* Clone of src/eboot/FUN_00197458.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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
typedef float undefined4;


void FUN_001a3da8(undefined4 param_1,undefined4 param_2,int param_3)
{
  *(undefined4 *)(param_3 + 0x60) = param_1;
  *(undefined4 *)(param_3 + 100) = param_2;
  return;
}
