/* HSTMATCH module=EBOOT.BIN start=0x001526e4 end=0x00152768 symbol=FUN_001526e4 lang=c99 data=0x002dc674 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is unsigned char (lbu) and the if/else tests iVar1 >= 10000 first; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc674-0x002dc68b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern undefined4 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd440();
extern void FUN_001cd490();

undefined4 FUN_001526e4(int param_1,undefined4 param_2)
{
  int iVar1;
  
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("ChangeCamera [%d, %d]\n",*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(param_1 + 0xc));
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 >= 10000) {
    FUN_001cd440(DAT_0034a114,iVar1 + -10000,*(undefined4 *)(param_1 + 0xc));
  }
  else {
    FUN_001cd490(DAT_0034a114,iVar1,*(undefined4 *)(param_1 + 0xc));
  }
  return 0;
}
