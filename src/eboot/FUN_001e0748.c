/* HSTMATCH module=EBOOT.BIN start=0x001e0748 end=0x001e075c symbol=FUN_001e0748 lang=c99 data=0x002ebac8 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ebac8-0x002ebaec) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined DAT_0030ebf4;
extern void FUN_0001ca58();

void FUN_001e0748(undefined4 param_1,undefined4 param_2,uint param_3,int *param_4,undefined4 param_5 ,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  FUN_0001ca58((int)&DAT_0030ebf4,"game/700_prize/030_prize_display.xb",param_3,param_4,param_5,param_6,
               param_7,param_8);
  return;
}
