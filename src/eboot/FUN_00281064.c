/* HSTMATCH module=EBOOT.BIN start=0x00281064 end=0x00281090 symbol=FUN_00281064 lang=c99 */
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

extern undefined4 DAT_00338ac4;
extern void FUN_000bd704();

void FUN_00281064(void)
{
  if (DAT_00338ac4 != 0) {
    FUN_000bd704(DAT_00338ac4,0xffffffff);
  }
  return;
}
