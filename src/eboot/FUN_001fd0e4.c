/* HSTMATCH module=EBOOT.BIN start=0x001fd0e4 end=0x001fd110 symbol=FUN_001fd0e4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
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

extern undefined4 DAT_0034a13c;
extern void FUN_001fdb80();

void FUN_001fd0e4(void)
{
  if (DAT_0034a13c != 0) {
    FUN_001fdb80(DAT_0034a13c);
  }
  return;
}
