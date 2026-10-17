/* HSTMATCH module=hstp_trans_main.prx start=0x001b179c end=0x001b17f0 symbol=FUN_001b179c lang=c99 */
/* Clone of src/eboot/FUN_001a41d0.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted dispatch condition; exact match verified; names and types await human review. */
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

extern void FUN_00177b5c();

void FUN_001b179c(int param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_00177b5c(**(undefined4 **)(*(int *)(param_1 + 0x378) + *(int *)(param_1 + 0x2c4) * 4));
  }
  else {
    *(undefined4 *)(param_1 + 0x2c0) = *(undefined4 *)(param_1 + 0x2cc);
    *(undefined4 *)(param_1 + 0x2c4) = *(undefined4 *)(param_1 + 0x2d0);
    *(undefined4 *)(param_1 + 0x2c8) = *(undefined4 *)(param_1 + 0x2d4);
  }
  return;
}
