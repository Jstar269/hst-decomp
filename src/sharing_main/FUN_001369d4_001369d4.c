/* HSTMATCH module=hstp_trans_main.prx start=0x001369d4 end=0x00136ae4 symbol=FUN_001369d4 lang=c99 */
/* Clone of src/eboot/FUN_0012b568_0012b568.c (hstclone.py tag u3r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern int DAT_003e47f0;
extern int DAT_003e47f4;
extern int FUN_00136b98(int,undefined4,int);

undefined4 FUN_001369d4(int param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int uVar5;
  undefined4 uVar4;
  
  iVar1 = FUN_00136b98(param_1,*(undefined4 *)(param_1 + 0x35c),0);
  iVar3 = *(int *)(param_1 + 0x334);
  uVar5 = *(uint *)(param_1 + 0x354);
  uVar4 = 0xffffffff;
  if (iVar3 >= 0 && iVar3 <= DAT_003e47f4) {
    uVar2 = iVar3 - DAT_003e47f0;
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
