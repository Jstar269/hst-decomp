/* HSTMATCH module=hstp_trans_main.prx start=0x00161e34 end=0x00161e80 symbol=FUN_00161e34 lang=c99 data=0x00384010 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00384010-0x00384022) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined DAT_003e9630;
extern undefined4 DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001db840();

undefined4 FUN_00161e34(undefined4 param_1,undefined4 param_2)
{
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("SetGameOverMatch\n");
  }
  FUN_001db840(DAT_003f344c,1);
  return 0;
}
