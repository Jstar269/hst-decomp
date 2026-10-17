/* HSTMATCH module=EBOOT.BIN start=0x000eecf0 end=0x000eed4c symbol=FUN_000eecf0 lang=c99 */
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

extern undefined4 DAT_003386b0;
extern void FUN_000ffb3c();
extern void FUN_00103128();

void FUN_000eecf0(int param_1)
{
  undefined1 uVar1;
  
  if (*(uchar *)(param_1 + 0x54) == '\0') {
    uVar1 = *(undefined1 *)(DAT_003386b0 + 0x4c);
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0x5c),uVar1);
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0x60),uVar1);
    FUN_00103128(param_1);
  }
  return;
}
