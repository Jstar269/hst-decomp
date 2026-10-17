/* HSTMATCH module=hstp_trans_main.prx start=0x0022d0a4 end=0x0022d130 symbol=FUN_0022d0a4 lang=c99 */
/* Clone of src/eboot/FUN_0021db30_0021db30.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the float zero argument and placed the receiver first in the helper prototype; exact match verified; names and types await human review. */
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

extern void FUN_0022d130();
extern void FUN_0022d288();
extern void FUN_0022d4e0();
extern void FUN_0022d604(float param_1,int param_2);
extern void FUN_0022d6c0();
extern void FUN_0022d780(float param_1,int param_2);
extern void FUN_0022d7d0(int param_1,float param_2,float param_3);
extern void FUN_0022da40();

void FUN_0022d0a4(int param_1)
{
  *(undefined4 *)(param_1 + 0x1e8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  FUN_0022d4e0(param_1,0);
  FUN_0022d604(0.0f,param_1);
  FUN_0022d780(1.0f,param_1);
  FUN_0022da40(param_1,0,0);
  FUN_0022d7d0(param_1,0.0f,0.0f);
  FUN_0022d6c0(param_1,0);
  FUN_0022d130(param_1);
  FUN_0022d288(param_1);
  return;
}
