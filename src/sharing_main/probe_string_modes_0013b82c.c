/* HSTMATCH module=hstp_trans_main.prx start=0x0013b82c end=0x0013b8bc symbol=FUN_0013b82c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: tested each string match as the nonzero path with one shared result; exact match verified; names and types await human review. */
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

extern char DAT_003822f0[];
extern char DAT_003822f8[];
extern char DAT_00382304[];
extern char * FUN_00014d64();

undefined4 FUN_0013b82c(undefined4 param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2 = 0;
  if (param_2 == 0) {
    uVar2 = 0;
  } else {
    iVar1 = (int)FUN_00014d64(param_2,DAT_003822f0);
    if (iVar1 != 0) {
      uVar2 = 0x32;
    } else {
      iVar1 = (int)FUN_00014d64(param_2,DAT_003822f8);
      if (iVar1 != 0) {
        uVar2 = 0x3c;
      } else {
        iVar1 = (int)FUN_00014d64(param_2,DAT_00382304);
        if (iVar1 != 0) uVar2 = 999;
      }
    }
  }
  return uVar2;
}
