/* HSTMATCH module=EBOOT.BIN start=0x002ad8cc end=0x002ad938 symbol=FUN_002ad8cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed the three accepted values in retail test order with a switch; exact match verified; names and types await human review. */
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

extern undefined4 DAT_0034a678;
extern int FUN_0016bb88();
extern void FUN_002ad758();

void FUN_002ad8cc(void)
{
  undefined4 uVar1;
  int uVar2;
  
  uVar2 = 0;
  switch (DAT_0034a678) {
  case 0x14:
  case 0x47:
  case 0x48:
    uVar2 = 1;
    break;
  default:
    break;
  }
  uVar1 = FUN_0016bb88();
  FUN_002ad758(uVar2,uVar1,0);
  return;
}
