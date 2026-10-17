/* HSTMATCH module=EBOOT.BIN start=0x001d6264 end=0x001d6280 symbol=FUN_001d6264 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
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


void FUN_001d6264(int param_1,undefined4 *param_2)
{
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 8) = *param_2;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}
