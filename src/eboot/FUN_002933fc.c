/* HSTMATCH module=EBOOT.BIN start=0x002933fc end=0x0029343c symbol=FUN_002933fc lang=c99 */
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


undefined4 FUN_002933fc(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((*(uchar *)(param_1 + 0x4d) != '\0') && (*(uchar *)(param_1 + 0x40) == '\0')) &&
     (*(float *)(param_1 + 0x38) <= 31.0f)) {
    uVar1 = 1;
  }
  return uVar1;
}
