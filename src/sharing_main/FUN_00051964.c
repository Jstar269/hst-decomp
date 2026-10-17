/* HSTMATCH module=hstp_trans_main.prx start=0x00051964 end=0x000519d4 symbol=FUN_00051964 lang=c99 */
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

extern undefined DAT_003b0294;
extern void FUN_00051a2c();
extern void FUN_00051b88();

undefined4 * FUN_00051964(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *param_1 = (unsigned int)(&DAT_003b0294);
  FUN_00051a2c();
  FUN_00051b88(param_1,param_2,param_3,param_4,0x10);
  return param_1;
}
