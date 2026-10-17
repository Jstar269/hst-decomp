/* HSTMATCH module=hstp_trans_main.prx start=0x00123f4c end=0x00123fb4 symbol=FUN_00123f4c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0320_00123f4c_m01.c); exact match verified; names and types await human review. */
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

extern int FUN_00123668();
extern undefined4 FUN_00123fb4();
extern undefined4 * FUN_00124130();
extern undefined4 FUN_00124148();

int FUN_00123f4c(int param_1,undefined4 param_2)
{
  undefined1 auStack_4 [4];
  undefined4 uVar1;
  undefined1 auStack_14 [16];
  
  uVar1 = FUN_00124148(auStack_4);
  FUN_00124130(auStack_14,uVar1);
  FUN_00123fb4(param_1,param_2,auStack_14);
  FUN_00123668(auStack_14,0xffffffff);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return param_1;
}
