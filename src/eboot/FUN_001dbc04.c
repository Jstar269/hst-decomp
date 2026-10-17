/* HSTMATCH module=EBOOT.BIN start=0x001dbc04 end=0x001dbc40 symbol=FUN_001dbc04 lang=c99 */
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

extern undefined4 DAT_00338714;
extern void FUN_0005f1e8();

void FUN_001dbc04(int param_1)
{
  if ((*(int *)(param_1 + 0x3c) != 0) && (*(uchar *)(param_1 + 0xcc) != '\0')) {
    FUN_0005f1e8(*(int *)(param_1 + 0x3c),DAT_00338714);
  }
  return;
}
