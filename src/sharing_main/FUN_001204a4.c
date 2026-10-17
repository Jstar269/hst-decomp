/* HSTMATCH module=hstp_trans_main.prx start=0x001204a4 end=0x001204dc symbol=FUN_001204a4 lang=c99 */
/* Clone of src/eboot/FUN_00115588.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_00108aec();

void FUN_001204a4(int param_1)
{
  if (((*(uint *)(param_1 + 0x6c) & 8) == 0) || (*(int *)(param_1 + 0x88) < 1)) {
    FUN_00108aec();
  }
  return;
}
