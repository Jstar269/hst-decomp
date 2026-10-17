/* HSTMATCH module=EBOOT.BIN start=0x001c38c0 end=0x001c38e0 symbol=FUN_001c38c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
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


void FUN_001c38c0(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x61) = param_2;
  if (*(uchar *)(param_1 + 0x61) != '\0') {
    *(undefined1 *)(param_1 + 0x62) = 1;
  }
  return;
}
