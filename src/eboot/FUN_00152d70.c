/* HSTMATCH module=EBOOT.BIN start=0x00152d70 end=0x00152de0 symbol=FUN_00152d70 lang=c99 data=0x002dc700 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q3); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc700-0x002dc714) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined DAT_003402f0;
extern int FUN_0014c384();
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern code * FUN_0022cd60();

undefined4 FUN_00152d70(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("GetDifficulty [%d]\n",*(undefined4 *)(param_1 + 8));
  }
  uVar3 = *param_2;
  iVar1 = (int)(FUN_0022cd60());
  uVar4 = *(undefined4 *)(iVar1 + 0x138);
  puVar2 = (undefined4 *)FUN_0014c384(uVar3,*(undefined4 *)(param_1 + 8));
  *puVar2 = uVar4;
  return 0;
}
