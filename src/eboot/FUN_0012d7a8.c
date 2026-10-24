/* HSTMATCH module=EBOOT.BIN start=0x0012d7a8 end=0x0012d808 symbol=FUN_0012d7a8 lang=c99 */
/* LobbyStage_GetSeCsvPath: data/lobby/<name>/setting/lNN_rNN_se.csv; see docs/DATA-TABLES.md */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
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

extern char DAT_002dad54[];
extern void FUN_000143b0();
extern int FUN_0006517c();

void FUN_0012d7a8(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  uVar1 = FUN_0006517c(*(undefined4 *)(param_1 + 0x1398),*(undefined4 *)(param_1 + 0x1390),0);
  FUN_000143b0(param_2,DAT_002dad54,uVar1,
               *(int *)(param_1 + 0x1390) + 1,*(int *)(param_1 + 0x1394) + 1);
  return;
}
