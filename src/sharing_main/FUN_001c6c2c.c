/* HSTMATCH module=hstp_trans_main.prx start=0x001c6c2c end=0x001c6c80 symbol=FUN_001c6c2c lang=c99 */
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

extern undefined DAT_003eaad8;
extern char DAT_0039157f[];
extern void FUN_00000020();
extern void FUN_00000028();
extern void FUN_001c1d9c();

void FUN_001c6c2c(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_00000020(DAT_0039157f + 1);
  FUN_001c1d9c((int)&DAT_003eaad8,param_2,param_3);
  FUN_00000028();
  return;
}
