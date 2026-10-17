/* HSTMATCH module=EBOOT.BIN start=0x001ee224 end=0x001ee234 symbol=FUN_001ee224 lang=c99 */
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

extern undefined4 DAT_003386b0;
extern undefined4 FUN_001ef2e0();

void FUN_001ee224(void)
{
  FUN_001ef2e0(*(undefined4 *)(DAT_003386b0 + 0xa0));
  return;
}
