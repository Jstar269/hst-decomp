/* HSTMATCH module=EBOOT.BIN start=0x00091bc8 end=0x00091c48 symbol=FUN_00091bc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: loop form and local declaration order; exact match verified; names and types await human review. */
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

extern undefined DAT_002beb30;
extern void FUN_000006e8();
extern void FUN_00091af4();
extern void FUN_00092c38();
extern void FUN_00092dc8();
extern void FUN_0006e024();

void FUN_00091bc8(int param_1)
{
  int iVar2;
  undefined4 *puVar1;
  
  FUN_00092dc8();
  iVar2 = 5;
  puVar1 = (unsigned int *)(&DAT_002beb30);
  for (; iVar2 >= 0; iVar2--, puVar1--) {
    FUN_00092c38(param_1,*puVar1);
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    FUN_000006e8(*(int *)(param_1 + 0x24),FUN_0006e024);
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  FUN_00091af4(param_1);
  return;
}
