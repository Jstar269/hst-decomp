/* HSTMATCH module=EBOOT.BIN start=0x00151688 end=0x0015171c symbol=FUN_00151688 lang=c99 data=0x002dc508 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: DAT_003402f0 is unsigned char (lbu), local declaration order uVar4, uVar3, uVar2 for the saved-register assignment; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc508-0x002dc522) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern unsigned char DAT_003402f0;
extern int FUN_0014c384();
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern bool FUN_0022baec();

undefined4 FUN_00151688(undefined4 param_1,undefined4 *param_2)
{
  undefined4 uVar4;
  undefined4 uVar3;
  undefined4 uVar2;
  undefined4 *puVar1;
  
  uVar3 = *(undefined4 *)(param_2[3] + 0x34);
  uVar2 = *(undefined4 *)(param_2[3] + 0x38);
  puVar1 = (undefined4 *)FUN_0014c384(*param_2,8);
  uVar4 = *puVar1;
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("CmdCheckTalkProc(%d, %d)\n",uVar3,uVar4);
  }
  FUN_0022baec(uVar3,uVar2,uVar4);
  return 0;
}
