/* HSTMATCH module=hstp_trans_main.prx start=0x0001d84c end=0x0001d8c8 symbol=FUN_0001d84c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed the copied globals as bytes to preserve retail byte loads and stores; exact match verified; names and types await human review. */
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
extern undefined DAT_003b910c;
extern undefined DAT_003b910d;
extern undefined DAT_003b910e;
extern undefined DAT_003b910f;
extern undefined DAT_003b9110;
extern undefined DAT_003b9111;
extern undefined DAT_003b9112;
extern undefined DAT_003b9113;
extern void FUN_0001deb4();
extern undefined4 FUN_0001ebdc();

void FUN_0001d84c(void)
{
  DAT_003751d4 = (unsigned int)(&DAT_003b8f40);
  DAT_003b910c = DAT_003b9110;
  DAT_003b910d = DAT_003b9111;
  DAT_003b910e = DAT_003b9112;
  DAT_003b910f = DAT_003b9113;
  FUN_0001ebdc(&DAT_003b9110);
  FUN_0001deb4(DAT_003751d4);
  return;
}
