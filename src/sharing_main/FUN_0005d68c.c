/* HSTMATCH module=hstp_trans_main.prx start=0x0005d68c end=0x0005d6e0 symbol=FUN_0005d68c lang=c99 */
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

extern void FUN_000009e4();
extern int FUN_00000a90();

void FUN_0005d68c(int param_1,int param_2)
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_000009e4(*(int *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(int *)(param_1 + 0x18) = param_2;
  if (0 < param_2) {
    uVar1 = FUN_00000a90(param_2 << 5);
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
  }
  return;
}
