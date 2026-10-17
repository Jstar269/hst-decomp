/* HSTMATCH module=EBOOT.BIN start=0x001ff5a4 end=0x001ff5d0 symbol=FUN_001ff5a4 lang=c99 */
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

extern undefined4 DAT_003386c8;
extern void FUN_00281090();

void FUN_001ff5a4(void)
{
  if (DAT_003386c8 != 0) {
    FUN_00281090(*(undefined4 *)(DAT_003386c8 + 0x40));
  }
  return;
}
