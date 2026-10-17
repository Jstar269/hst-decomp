/* HSTMATCH module=hstp_trans_main.prx start=0x00003314 end=0x00003370 symbol=FUN_00003314 lang=c99 */
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

extern uint FUN_00003100();
extern uint FUN_00003c74();
extern int FUN_000041d0();

void FUN_00003314(undefined4 param_1,undefined4 param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00003100(param_1);
  uVar2 = FUN_000041d0(param_2);
  FUN_00003c74(param_1,0,uVar1,param_2,uVar2);
  return;
}
