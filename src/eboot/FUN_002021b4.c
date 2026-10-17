/* HSTMATCH module=EBOOT.BIN start=0x002021b4 end=0x002021d4 symbol=FUN_002021b4 lang=c99 */
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


void FUN_002021b4(float param_1,uchar *param_2)
{
  if (*param_2 != '\0') {
    *(float *)(param_2 + 0x14) = *(float *)(param_2 + 0x14) + param_1;
  }
  return;
}
