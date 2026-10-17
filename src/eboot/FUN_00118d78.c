/* HSTMATCH module=EBOOT.BIN start=0x00118d78 end=0x00118de0 symbol=FUN_00118d78 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0277_00118d78_m02.c); exact match verified; names and types await human review. */
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

extern int FUN_00118494();
extern undefined4 FUN_00118de0();
extern undefined4 * FUN_00118f5c();
extern undefined4 FUN_00118f74();

int FUN_00118d78(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  undefined1 auStack_14 [16];
  
  uVar1 = FUN_00118f74(auStack_4);
  FUN_00118f5c(auStack_14,uVar1);
  FUN_00118de0(param_1,param_2,auStack_14);
  FUN_00118494(auStack_14,0xffffffff);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return param_1;
}
