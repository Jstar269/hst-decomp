/* HSTMATCH module=hstp_trans_main.prx start=0x0004d5f8 end=0x0004d644 symbol=FUN_0004d5f8 lang=c99 */
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

extern undefined DAT_002cc260;
extern undefined4 * FUN_00022598();
extern undefined4 * FUN_00022690();

void FUN_0004d5f8(undefined4 param_1,undefined4 param_2)
{
  undefined1 auStack_40 [64];
  
  FUN_00022690(auStack_40,&DAT_002cc260);
  FUN_00022598(param_1,param_2,auStack_40);
  return;
}
