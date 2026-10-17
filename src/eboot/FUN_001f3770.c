/* HSTMATCH module=EBOOT.BIN start=0x001f3770 end=0x001f37e4 symbol=FUN_001f3770 lang=c99 */
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

extern void FUN_001e2668();
extern undefined4 FUN_001f3144();
extern void FUN_001f94b8();
extern void FUN_001fb928();

void FUN_001f3770(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001f3144(param_1,*(undefined4 *)(param_1 + 0x40),0);
  if (iVar1 == 0x14) {
    FUN_001f94b8(param_1);
  }
  else {
    if (iVar1 == 0xb) {
      FUN_001e2668(*(undefined4 *)(param_1 + 0x510));
    }
    FUN_001fb928(param_1 + 0x3c,iVar1,1);
  }
  return;
}
