/* HSTMATCH module=EBOOT.BIN start=0x001fed58 end=0x001fed8c symbol=FUN_001fed58 lang=c99 */
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

extern undefined4 DAT_003313c4;
extern void FUN_0005c900();
extern void FUN_0005ca5c();

void FUN_001fed58(void)
{
  FUN_0005ca5c(DAT_003313c4,0);
  FUN_0005c900(DAT_003313c4,0);
  return;
}
