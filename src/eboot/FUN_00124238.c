/* HSTMATCH module=EBOOT.BIN start=0x00124238 end=0x00124268 symbol=FUN_00124238 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern void FUN_001240fc();

void FUN_00124238(int param_1)
{
  FUN_001240fc(param_1,1,0);
  *(undefined4 *)(param_1 + 0x68) = 0;
  return;
}
