/* HSTMATCH module=EBOOT.BIN start=0x000b3390 end=0x000b33d0 symbol=FUN_000b3390 lang=c99 */
/* Clone of src/sharing_main/FUN_000b65a8.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v2) corrected by hand: kept the inner pointer separate from the integer status and used shared ret0 and ret1 labels; exact match verified; names and types await human review. */
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
typedef float undefined4;


int FUN_000b3390(int param_1)
{
  int inner;
  int value;
  int result;

  inner = *(int *)(*(int *)(param_1 + 0x5bc) + 0x58);
  if (inner != 0) {
    value = *(int *)(inner + 0xf0);
  }
  else {
    value = -1;
  }
  if (value < 0x37) goto ret0;
  if (value >= 0x44) goto ret0;
  goto ret1;
ret1:
  return 1;
ret0:
  return 0;
}
