/* HSTMATCH module=hstp_trans_main.prx start=0x00104c88 end=0x00104cac symbol=FUN_00104c88 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh128a), refined by hstperm.py tag p4 random mutation from try/gen-sh128a/v0/FUN_00104c88.c; exact match verified; names and types await human review. */
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


uint FUN_00104c88(int param_1,uint param_2)
{
  uint uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 >= 0x14) {
    uVar1 = *(uint *)(param_1 + 0xc) ^ 0x8729382e;
  }
  return uVar1;
}
