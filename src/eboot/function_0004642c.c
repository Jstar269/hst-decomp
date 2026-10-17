/* HSTMATCH module=EBOOT.BIN start=0x0004642c end=0x0004648c symbol=FUN_0004642c lang=c99 */
/* Clone of src/sharing_main/function_0004652c.c (hstclone.py tag u6cr5e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed FUN_000464ec as int and split the short-circuit checks into early guards; exact match verified; names and types await human review. */
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

extern undefined4 DAT_002d0220;
extern undefined4 DAT_00311000;
extern undefined4 DAT_0034a678;
extern int FUN_000464ec();
extern void FUN_00060224();

void FUN_0004642c(void)
{
  if (FUN_000464ec() == 0) return;
  if (DAT_00311000 == 0) return;
  if (DAT_002d0220 == 0) return;
  if (DAT_0034a678 == 0x21) return;
  FUN_00060224(DAT_00311000,1);
  return;
}
