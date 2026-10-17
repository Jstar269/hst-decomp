/* HSTMATCH module=EBOOT.BIN start=0x000bd92c end=0x000bd97c symbol=FUN_000bd92c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v3) corrected by hand: made the indexed flag loop and count explicit; exact match verified; names and types await human review. */
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


undefined1 FUN_000bd92c(int param_1,int param_2)
{
  int count;
  int index;
  undefined1 result;
  if (param_2 < 0) {
    count = 0;
    index = 0;
    for (; index < 16; index++) {
      if (*(uchar *)(param_1 + index + 0x21c) != 0) count++;
    }
    result = *(int *)(param_1 + 400) == count;
  } else {
    result = *(undefined1 *)(param_2 + param_1 + 0x21c);
  }
  return result;
}
