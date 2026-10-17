/* HSTMATCH module=EBOOT.BIN start=0x001e5df0 end=0x001e5e3c symbol=FUN_001e5df0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained a separate advanced cursor for the indexed calls; exact match verified; names and types await human review. */
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

extern void FUN_00102c54();

void FUN_001e5df0(int param_1)
{
  int iVar1;
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: kept the advanced object cursor as the helper argument; exact match verified; names and types await human review. */
  int base;

  iVar1 = 0;
  base = param_1;
  do {
    *(undefined4 *)(*(int *)(base + 0x1d6c) + 0x60) = 0;
    FUN_00102c54(*(undefined4 *)(base + 0x1d6c));
    iVar1 = iVar1 + 1;
    base = base + 4;
  } while (iVar1 < 5);
  return;
}
