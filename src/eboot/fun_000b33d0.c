/* HSTMATCH module=EBOOT.BIN start=0x000b33d0 end=0x000b342c symbol=FUN_000b33d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: separated the inner pointer from its loaded value and kept the nested positive range checks; exact match verified; names and types await human review. */
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

extern int FUN_00093b00();

int FUN_000b33d0(int param_1)
{
  int outer = *(int *)(param_1 + 0x5bc);
  int inner = *(int *)(outer + 0x58);
  int value;
  if (inner != 0) value = *(int *)(inner + 0xf0);
  else value = -1;
  if (value >= 5) {
    if (value < 9) {
      if (FUN_00093b00(outer,0) == 0) return 1;
    }
  }
  return 0;
}
