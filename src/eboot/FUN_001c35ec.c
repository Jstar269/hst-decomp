/* HSTMATCH module=EBOOT.BIN start=0x001c35ec end=0x001c364c symbol=FUN_001c35ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_00226128 as int instead of a byte result; exact match verified; names and types await human review. */
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

extern undefined4 DAT_0034a2e0;
extern void FUN_001cd88c();
extern void FUN_002260e0();
extern undefined4 FUN_00226118();
extern int FUN_00226128();

void FUN_001c35ec(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00226128(DAT_0034a2e0);
  if (iVar1 != 0) {
    uVar2 = FUN_00226118(DAT_0034a2e0);
    *(undefined4 *)(param_1 + 0xf4) = uVar2;
    FUN_002260e0(DAT_0034a2e0);
    FUN_001cd88c(param_1,0,1);
  }
  return;
}
