/* HSTMATCH module=EBOOT.BIN start=0x0009044c end=0x000904dc symbol=FUN_0009044c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003386b0;
extern undefined4 DAT_00340284;
extern int FUN_000904dc();
extern void FUN_000b1610();

void FUN_0009044c(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_003386b0 + 0x3c);
  if (((iVar2 == 4) || (iVar2 == 5)) ||
     ((iVar2 == 7 && (*(uchar *)(*(int *)(DAT_00340284 + 0x80) + 0x78) == '\0')))) {
    uVar1 = FUN_000904dc(param_1);
    FUN_000b1610(uVar1,param_2,*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(param_1 + 0x23c));
  }
  return;
}
