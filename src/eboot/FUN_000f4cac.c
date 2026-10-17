/* HSTMATCH module=EBOOT.BIN start=0x000f4cac end=0x000f4cf0 symbol=FUN_000f4cac lang=c99 */
/* Clone of src/sharing_main/FUN_000fa3a0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_000f4cac(int param_1)
{
  undefined4 uVar2;
  int iVar1;
  
  uVar2 = *(undefined4 *)(*(int *)(0x168 + param_1) + 0x24);
  iVar1 = *(int *)(param_1 + 0x160);
  *(undefined4 *)(iVar1 + 0x24) = uVar2;
  *(undefined4 *)(iVar1 + 0x28) = uVar2;
  *(undefined4 *)(param_1 + 0x208) = *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x24);
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x16c) + 0x24);
  iVar1 = *(int *)(0x164 + param_1);
  *(undefined4 *)(iVar1 + 0x24) = uVar2;
  *(undefined4 *)(iVar1 + 0x28) = uVar2;
  *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(*(int *)(param_1 + 0x16c) + 0x24);
  return;
}
