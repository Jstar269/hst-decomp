/* HSTMATCH module=EBOOT.BIN start=0x001cd060 end=0x001cd0d8 symbol=FUN_001cd060 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used a signed status test and passed the third helper argument through the byte store; exact match verified; names and types await human review. */
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

extern int DAT_0034b590;
extern void FUN_001c2498();
extern void FUN_001cd88c();
extern void FUN_002ad938();

void FUN_001cd060(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  FUN_002ad938();
  if (DAT_0034b590 > 0) {
    iVar2 = *(int *)(param_1 + 0x15c);
    *(undefined4 *)(iVar2 + 0xe0) = 0;
    *(undefined1 *)(iVar2 + 0xe4) = 1;
    FUN_001cd88c(iVar2,7,1);
    FUN_001c2498(iVar2);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x15c);
    FUN_001cd88c(uVar1,0xb,1);
    FUN_001c2498(uVar1);
  }  return;
}
