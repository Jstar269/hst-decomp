/* HSTMATCH module=hstp_trans_main.prx start=0x0004b044 end=0x0004b13c symbol=FUN_0004b044 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v16) corrected by hand: reversed the status arms to preserve the retail logger branch; exact match verified; names and types await human review. */
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

extern undefined DAT_0037607c;
extern undefined DAT_003ba4b0;
extern char DAT_00376060[];
extern bool FUN_0002b824();
extern undefined4 FUN_0002b8f4();
extern void FUN_00048fb8();
extern void FUN_00049020();
extern void FUN_0004b13c();
extern void FUN_0004b1bc();
extern void FUN_0004b2d4();
extern uint FUN_0004cd8c();
extern void FUN_0004f864();

undefined4 FUN_0004b044(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5)
{
  int iVar1;
  
  FUN_0004b13c(param_1);
  iVar1 = FUN_0004cd8c(param_2,0,0x10,1);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    FUN_00048fb8();
    iVar1 = FUN_0002b8f4(*param_1);
    FUN_00049020();
    if (iVar1 != 0) {
      FUN_0004f864((int)&DAT_003ba4b0,iVar1,DAT_00376060,0x158,&DAT_0037607c);
    } else {
      FUN_0002b824(*param_1,1);
      FUN_0004b1bc(param_1,param_3);
      FUN_0004b2d4(param_1,param_4,param_5);
      return 1;
    }
  }
  FUN_0004b13c(param_1);
  return 0;
}
