/* HSTMATCH module=EBOOT.BIN start=0x001fb4fc end=0x001fb524 symbol=FUN_001fb4fc lang=c99 */
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

extern undefined DAT_003418bc;

bool FUN_001fb4fc(int param_1)
{
  return (&DAT_003418bc)[*(int *)(param_1 + 0x3cc) * 0x120] != '\0';
}
