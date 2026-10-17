/* HSTMATCH module=hstp_trans_main.prx start=0x000562d0 end=0x00056314 symbol=FUN_000562d0 lang=c99 */
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

extern void FUN_00054ea4();
extern void FUN_00056160();

void FUN_000562d0(undefined4 param_1,int param_2)
{
  undefined4 uVar1;
  undefined1 auStack_40 [64];
  
  uVar1 = *(undefined4 *)(param_2 + 0x8c);
  FUN_00056160(auStack_40);
  FUN_00054ea4(param_1,uVar1,auStack_40);
  return;
}
