/* HSTMATCH module=EBOOT.BIN start=0x0029dfdc end=0x0029e024 symbol=FUN_0029dfdc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003415ac;
extern void FUN_000fe43c();
extern void FUN_00295cdc();
extern void FUN_0029ade8();
extern int FUN_0029e024();

void FUN_0029dfdc(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  FUN_0029e024();
  FUN_000fe43c(0);
  *(undefined4 *)(iVar1 + 0x28) = 0;
  FUN_0029ade8(iVar1,3);
  FUN_00295cdc(DAT_003415ac);
  return;
}
