/* HSTMATCH module=EBOOT.BIN start=0x0012b568 end=0x0012b678 symbol=FUN_0012b568 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored signed arithmetic and typed helper/global values; exact match verified; names and types await human review. */
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

extern int DAT_0033b4b0;
extern int DAT_0033b4b4;
extern int FUN_0012b72c(int,undefined4,int);

undefined4 FUN_0012b568(int param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int uVar5;
  undefined4 uVar4;
  
  iVar1 = FUN_0012b72c(param_1,*(undefined4 *)(param_1 + 0x35c),0);
  iVar3 = *(int *)(param_1 + 0x334);
  uVar5 = *(uint *)(param_1 + 0x354);
  uVar4 = 0xffffffff;
  if (iVar3 >= 0 && iVar3 <= DAT_0033b4b4) {
    uVar2 = iVar3 - DAT_0033b4b0;
    iVar1 = (int)uVar2 / 2;
    uVar5 = (int)uVar2 % 2;
  }
  if ((iVar1 == 0) && (uVar5 == 0)) {
    uVar4 = 7;
  }
  else if ((iVar1 == 0) && (uVar5 == 1)) {
    uVar4 = 4;
  }
  else if ((iVar1 == 3) && (uVar5 == 1)) {
    uVar4 = 10;
  }
  else if ((iVar1 == 4) && (uVar5 == 0)) {
    uVar4 = 4;
  }
  else if ((iVar1 == 5) && (uVar5 == 1)) {
    uVar4 = 0xd;
  }
  return uVar4;
}
