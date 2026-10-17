/* HSTMATCH module=hstp_trans_main.prx start=0x0004658c end=0x000465ec symbol=FUN_0004658c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed FUN_000465ec as int and split the short-circuit checks into early guards; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00375968;
extern undefined4 DAT_003ba300;
extern undefined4 DAT_003f39a8;
extern int FUN_000465ec();
extern void FUN_00061070();

void FUN_0004658c(void)
{
  if (FUN_000465ec() == 0) return;
  if (DAT_003ba300 == 0) return;
  if (DAT_00375968 == 0) return;
  if (DAT_003f39a8 == 0x21) return;
  FUN_00061070(DAT_003ba300,0);
  return;
}
