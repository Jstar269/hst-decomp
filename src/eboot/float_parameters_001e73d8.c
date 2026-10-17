/* HSTMATCH module=EBOOT.BIN start=0x001e73d8 end=0x001e744c symbol=FUN_001e73d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the mixed integer and float helper parameters and passed the pointer and float values in declared order; exact match verified; names and types await human review. */
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

extern char DAT_002ec180[];
extern undefined4 FUN_00065740();
extern int FUN_001ee224();
extern void FUN_0021780c(int,int,float,float);
extern void FUN_00217834();

void FUN_001e73d8(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = FUN_001ee224();
  uVar1 = FUN_00065740(uVar1,DAT_002ec180,1);
  FUN_00217834(param_1 + 0x928,*(undefined4 *)(param_1 + 0x948),0xffffffff,uVar1);
  FUN_0021780c(param_1 + 0x928,uVar1,1.5f,1.0f);
  return;
}
