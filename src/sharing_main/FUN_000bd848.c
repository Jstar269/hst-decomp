/* HSTMATCH module=hstp_trans_main.prx start=0x000bd848 end=0x000bd8c0 symbol=FUN_000bd848 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern char DAT_0037b524[];
extern char DAT_0037b568[];
extern char DAT_0037b5a8[];
extern char DAT_0037b5ec[];
extern void FUN_000bd6f0();
extern int FUN_002c7a60();

undefined4 FUN_000bd848(void)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_002c7a60(0x100);
  if (iVar1 < 0) {
    FUN_000bd6f0(DAT_0037b524,iVar1);
    uVar2 = 0;
  }
  else {
    FUN_000bd6f0(DAT_0037b568);
    iVar1 = FUN_002c7a60(0x101);
    if (iVar1 < 0) {
      FUN_000bd6f0(DAT_0037b5a8,iVar1);
      uVar2 = 0;
    }
    else {
      FUN_000bd6f0(DAT_0037b5ec);
      uVar2 = 1;
    }
  }
  return uVar2;
}
