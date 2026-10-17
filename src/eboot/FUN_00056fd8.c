/* HSTMATCH module=EBOOT.BIN start=0x00056fd8 end=0x00057034 symbol=FUN_00056fd8 lang=c99 */
/* Clone of src/sharing_main/FUN_00057c2c.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
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
extern undefined4 * FUN_00056110();
extern void FUN_0005708c();
extern void FUN_0005734c(int);

void FUN_00056fd8(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 uVar2;
  
  FUN_0005734c(param_1);
  iVar1 = FUN_00000bcc(0x10);
  if (iVar1 != 0) {
    iVar1 = (int)FUN_00056110(iVar1,param_2,0);
  }
  *(undefined4 *)(param_1 + 0x168) = iVar1;
  FUN_0005708c(param_1);
  return;
}
