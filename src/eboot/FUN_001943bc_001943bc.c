/* HSTMATCH module=EBOOT.BIN start=0x001943bc end=0x00194400 symbol=FUN_001943bc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00341730;
extern undefined4 DAT_0034173c;
extern undefined4 DAT_00341740;

undefined4 FUN_001943bc(void)
{
  if (DAT_00341740 == 0) goto zero;
  if (DAT_0034173c == 0) goto zero;
  if (DAT_00341730 == 0) goto zero;
  return 1;
zero:
  return 0;
}
