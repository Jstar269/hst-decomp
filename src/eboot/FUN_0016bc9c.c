/* HSTMATCH module=EBOOT.BIN start=0x0016bc9c end=0x0016bcec symbol=FUN_0016bc9c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_0016bc9c.c) corrected by hand: expressed the final status result with explicit 1/0 branches and the positive branch first; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00331c30;
extern undefined4 DAT_00341518;
extern int FUN_00000bcc();
extern undefined4 * FUN_0016d194();

int FUN_0016bc9c(void)
{
  int iVar1;
  
  DAT_00331c30 = 0xbc75c28f;
  iVar1 = FUN_00000bcc(0xdbc);
  if (iVar1 != 0) {
    FUN_0016d194(iVar1);
  }
  if (DAT_00341518 != 0) return 1;
  return 0;
}
