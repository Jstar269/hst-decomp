/* HSTMATCH module=EBOOT.BIN start=0x00254114 end=0x0025418c symbol=FUN_00254114 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared the helper integer argument and ordered the counter before the table cursor; exact match verified; names and types await human review. */
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

extern undefined4 DAT_0034a79c;
extern undefined DAT_0034b340;
extern void FUN_000006e8();
extern void FUN_00092ff8(int);
extern void FUN_00055e48();

void FUN_00254114(void)
{
  int iVar2;
  int *piVar1;
  
  iVar2 = 0;
  piVar1 = (int *)&DAT_0034b340;
  do {
    if (*piVar1 != 0) {
      FUN_00092ff8(*piVar1);
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 1;
  } while (iVar2 < 4);
  if (DAT_0034a79c != 0) {
    FUN_000006e8(DAT_0034a79c,FUN_00055e48);
    DAT_0034a79c = 0;
  }
  return;
}
