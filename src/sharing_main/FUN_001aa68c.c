/* HSTMATCH module=hstp_trans_main.prx start=0x001aa68c end=0x001aa6c8 symbol=FUN_001aa68c lang=c99 */
/* Clone of src/eboot/FUN_0019d1b8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001a871c();

void FUN_001aa68c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  if (*(int *)(param_1 + 0x90) != 0) {
    FUN_001a871c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
  }
  return;
}
