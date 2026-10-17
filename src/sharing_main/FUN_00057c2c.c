/* HSTMATCH module=hstp_trans_main.prx start=0x00057c2c end=0x00057c88 symbol=FUN_00057c2c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed the initialization helper receiver, retained its result through the nonnull guard, and used one shared field store; exact match verified; names and types await human review. */
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

extern int FUN_00000bcc();
extern undefined4 * FUN_00056d24();
extern void FUN_00057ce0();
extern void FUN_00057fa0(int);

void FUN_00057c2c(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00057fa0(param_1);
  iVar1 = FUN_00000bcc(0x10);
  if (iVar1 != 0) {
    iVar1 = (int)FUN_00056d24(iVar1,param_2,0);
  }
  *(undefined4 *)(param_1 + 0x168) = iVar1;
  FUN_00057ce0(param_1);
  return;
}
