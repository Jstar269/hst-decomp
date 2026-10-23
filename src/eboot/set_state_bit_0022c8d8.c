/* HSTMATCH module=EBOOT.BIN start=0x0022c8d8 end=0x0022c928 symbol=FUN_0022c8d8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: put the set-bit path in the true arm and clear in the else arm. */
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

extern undefined4 DAT_003415a8;

void FUN_0022c8d8(int param_1,int param_2)
{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = param_1 + 0x8d00 + DAT_003415a8;
    *(byte *)(iVar1 + 0x3500) = *(byte *)(iVar1 + 0x3500) | 4;
  } else {
    iVar1 = param_1 + 0x8d00 + DAT_003415a8;
    *(byte *)(iVar1 + 0x3500) = *(byte *)(iVar1 + 0x3500) & 0xfb;
  }
  return;
}
