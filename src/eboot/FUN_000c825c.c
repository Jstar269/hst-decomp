/* HSTMATCH module=EBOOT.BIN start=0x000c825c end=0x000c82c8 symbol=FUN_000c825c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
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

extern int * FUN_000008d8();
extern int FUN_00000a90();
extern void FUN_00056b98();
extern void FUN_00056cb0();

void FUN_000c825c(int param_1)
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x1d0) == 0) {
    uVar1 = FUN_00000a90(0x6d0);
    uVar1 = (unsigned int)(FUN_000008d8(uVar1,FUN_00056b98,FUN_00056cb0,0x1b0,4));
    *(undefined4 *)(param_1 + 0x1d0) = uVar1;
  }
  if (*(int *)(param_1 + 0x1d4) == 0) {
    uVar1 = FUN_00000a90(4);
    *(undefined4 *)(param_1 + 0x1d4) = uVar1;
  }
  return;
}
