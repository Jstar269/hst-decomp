/* HSTMATCH module=hstp_trans_main.prx start=0x0001eb84 end=0x0001eb98 symbol=FUN_0001eb84 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003751d4;
extern undefined DAT_003b8f40;

void FUN_0001eb84(void)
{
  DAT_003751d4 = (unsigned int)(&DAT_003b8f40);
  return;
}
