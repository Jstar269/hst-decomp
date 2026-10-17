/* HSTMATCH module=EBOOT.BIN start=0x00056e84 end=0x00056ed8 symbol=FUN_00056e84 lang=c99 */
/* Clone of src/sharing_main/FUN_00057ad8.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the helper result as unsigned char and reordered the callback arms; exact match verified; names and types await human review. */
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

extern bool FUN_00055148();
extern void FUN_00056f04();
extern void FUN_00056f88();

unsigned char FUN_00056e84(undefined4 param_1)
{
  unsigned char cVar1;
  
  cVar1 = FUN_00055148();
  if (cVar1 != 0) {
    FUN_00056f04(param_1);
  } else {
    FUN_00056f88(param_1);
  }
  return cVar1;
}
