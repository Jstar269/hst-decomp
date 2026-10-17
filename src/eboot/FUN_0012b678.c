/* HSTMATCH module=EBOOT.BIN start=0x0012b678 end=0x0012b6e8 symbol=FUN_0012b678 lang=c99 */
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

extern void FUN_0012a254();
extern undefined4 FUN_0012c364();
extern undefined4 FUN_0012c5ac();

void FUN_0012b678(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)
{
  uchar cVar1;
  undefined1 uVar2;
  
  cVar1 = FUN_0012c364(param_1 + 0x370);
  if (cVar1 != '\0') {
    uVar2 = FUN_0012c5ac(param_1 + 0x370);
    *(undefined1 *)(param_1 + 0x410) = uVar2;
    *(undefined1 *)(param_1 + 0x32c) = param_4;
    if (*(uchar *)(param_1 + 0x410) == '\0') {
      FUN_0012a254(param_1,0xc,0xffffffff,0);
    }
  }
  return;
}
