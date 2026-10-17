/* HSTMATCH module=EBOOT.BIN start=0x002ad9e8 end=0x002ada5c symbol=FUN_002ad9e8 lang=c99 */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined DAT_0034b4f0;
extern undefined4 DAT_0034b590;
extern int FUN_0016bb88();
extern void FUN_001bf9f0();

void FUN_002ad9e8(void)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  if (0 < DAT_0034b590) {
    puVar3 = (undefined4 *)&DAT_0034b4f0;
    do {
      uVar1 = FUN_0016bb88();
      FUN_001bf9f0(uVar1,*puVar3,4);
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < DAT_0034b590);
  }
  DAT_0034b590 = 0;
  return;
}
