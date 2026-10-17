/* HSTMATCH module=hstp_trans_main.prx start=0x00026a74 end=0x00026a8c symbol=FUN_00026a74 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
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

extern int FUN_000266d4();
extern void FUN_00026490();
extern void FUN_000291ec();

void FUN_00026a74(int *param_1,undefined1 (*param_2) [12],undefined4 param_3)
{
  FUN_000266d4(param_1,param_2,param_3,FUN_000291ec,FUN_00026490,'\x01');
  return;
}
