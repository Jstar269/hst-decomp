/* HSTMATCH module=EBOOT.BIN start=0x002904d4 end=0x002905bc symbol=FUN_002904d4 lang=c99 data=0x002ff550 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256b); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ff550-0x002ff56a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern char DAT_002ff534[];
extern char DAT_002ff56c[];
extern uint * FUN_000149a8();
extern undefined1 * FUN_00022d7c();
extern void FUN_0028fb44();
extern int FUN_002b7988();

undefined4 FUN_002904d4(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  int iVar2;
  int local_4;
  
  if (*(uchar *)(param_1 + 0x28) == '\0') {
    FUN_0028fb44(DAT_002ff534);
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x8c) = 1;
    FUN_000149a8(param_1 + 0x94);
    *(undefined4 *)(param_1 + 0x90) = param_3;
    FUN_00022d7c(*(undefined4 *)(param_1 + 0x2c),0,0x88000);
    iVar2 = FUN_002b7988(*(undefined4 *)(param_1 + 0x88),param_1 + 0x8c,0x48,0,&local_4);
    if (iVar2 == -0x7ffdfe4d) {
      FUN_0028fb44("Play(): request is full.\n");
    }
    else if ((iVar2 != 0) || (local_4 != 0x48)) {
      FUN_0028fb44(DAT_002ff56c,iVar2,local_4);
      return 0;
    }
    uVar1 = 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  return uVar1;
}
