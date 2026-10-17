/* HSTMATCH module=hstp_trans_main.prx start=0x001a9c90 end=0x001a9cb4 symbol=FUN_001a9c90 lang=c99 */
/* Clone of src/eboot/FUN_0019cadc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_001a9c90(int param_1,undefined4 *param_2)
{
  *(undefined4 *)(param_1 + 0x1d0) = *param_2;
  *(undefined4 *)(param_1 + 0x1d4) = param_2[1];
  *(undefined4 *)(param_1 + 0x1d8) = param_2[2];
  *(undefined4 *)(param_1 + 0x1dc) = param_2[3];
  return;
}
