/* HSTMATCH module=EBOOT.BIN start=0x000ba48c end=0x000ba504 symbol=FUN_000ba48c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
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

extern char DAT_002d4b58[];
extern char DAT_002d4b9c[];
extern char DAT_002d4bdc[];
extern char DAT_002d4c20[];
extern void FUN_000ba3ac();
extern int FUN_002b7c18();

undefined4 FUN_000ba48c(void)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_002b7c18(0x100);
  if (iVar1 < 0) {
    FUN_000ba3ac(DAT_002d4b58,iVar1);
    uVar2 = 0;
  }
  else {
    FUN_000ba3ac(DAT_002d4b9c);
    iVar1 = FUN_002b7c18(0x101);
    if (iVar1 < 0) {
      FUN_000ba3ac(DAT_002d4bdc,iVar1);
      uVar2 = 0;
    }
    else {
      FUN_000ba3ac(DAT_002d4c20);
      uVar2 = 1;
    }
  }
  return uVar2;
}
