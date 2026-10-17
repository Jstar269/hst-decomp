/* HSTMATCH module=hstp_trans_main.prx start=0x00044f4c end=0x00044fa4 symbol=FUN_00044f4c lang=c99 */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined4 DAT_003b927c;
extern undefined4 DAT_003b9280;
extern int FUN_000e3880();

void FUN_00044f4c(undefined4 param_1,int param_2)
{
  int iVar1;
  uint local_8 [2];
  
  local_8[0] = 8;
  local_8[1] = 4;
  iVar1 = FUN_000e3880(DAT_003b927c,param_2 + 3U & 0xfffffffc,local_8);
  DAT_003b9280 = DAT_003b9280 + *(int *)(iVar1 + -4);
  return;
}
