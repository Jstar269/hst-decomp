/* HSTMATCH module=EBOOT.BIN start=0x00052b4c end=0x00052bf4 symbol=FUN_00052b4c lang=c99 */
/* Clone of src/sharing_main/FUN_0005360c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_002bc410;
extern undefined4 DAT_0032b17c;
extern uint * FUN_00036ca8();
extern uint * FUN_000372fc();
extern undefined4 * FUN_00052ac8();

void FUN_00052b4c(int param_1)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = (unsigned int)(FUN_00036ca8(*(undefined4 *)(param_1 + 0x28),DAT_0032b17c));
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  puVar2 = (undefined4 *)FUN_000372fc(uVar1,DAT_0032b17c);
  *(undefined4 **)(param_1 + 0x28) = puVar2;
  *puVar2 = 0x17000000;
  iVar3 = *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = iVar3 + 4;
  *(uint *)(iVar3 + 4) = *(int *)(param_1 + 4) < 0 ^ 1 | 0x1e000000;
  iVar3 = *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = iVar3 + 4;
  *(undefined4 *)(iVar3 + 4) = 0xc0000301;
  iVar3 = *(int *)(param_1 + 0x28) + 4;
  *(int *)(param_1 + 0x28) = iVar3;
  uVar1 = (unsigned int)(FUN_00052ac8(iVar3,&DAT_002bc410));
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  return;
}
