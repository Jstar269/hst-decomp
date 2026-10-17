/* HSTMATCH module=EBOOT.BIN start=0x00062904 end=0x0006294c symbol=FUN_00062904 lang=c99 */
/* Clone of src/sharing_main/FUN_000637c8.c (hstclone.py tag u5cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: direct negative early return reproduces bltz and the argument-save delay slot; exact match verified; names and types await human review. */
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

extern void FUN_00062a44();
extern void FUN_00076454();

void FUN_00062904(undefined4 param_1,int param_2)
{
  if (param_2 < 0) return;
  FUN_00076454(param_2,0);
  FUN_00062a44(param_1,param_2);
  return;
}
