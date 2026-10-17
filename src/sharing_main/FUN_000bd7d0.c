/* HSTMATCH module=hstp_trans_main.prx start=0x000bd7d0 end=0x000bd848 symbol=FUN_000bd7d0 lang=c99 */
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

extern char DAT_0037b420[];
extern char DAT_0037b464[];
extern char DAT_0037b4a4[];
extern char DAT_0037b4e8[];
extern void FUN_000bd6f0();
extern int FUN_002c79b8();

undefined4 FUN_000bd7d0(void)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_002c79b8(0x100);
  if (iVar1 < 0) {
    FUN_000bd6f0(DAT_0037b420,iVar1);
    uVar2 = 0;
  }
  else {
    FUN_000bd6f0(DAT_0037b464);
    iVar1 = FUN_002c79b8(0x101);
    if (iVar1 < 0) {
      FUN_000bd6f0(DAT_0037b4a4,iVar1);
      uVar2 = 0;
    }
    else {
      FUN_000bd6f0(DAT_0037b4e8);
      uVar2 = 1;
    }
  }
  return uVar2;
}
