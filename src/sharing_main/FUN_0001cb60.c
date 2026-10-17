/* HSTMATCH module=hstp_trans_main.prx start=0x0001cb60 end=0x0001cbf0 symbol=FUN_0001cb60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: reversed the direct and indirect callback arms to match the retail branch path; exact match verified; names and types await human review. */
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

extern int FUN_00000a90();
extern undefined4 * FUN_00011090();

int FUN_0001cb60(int param_1,undefined4 *param_2,code *param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *param_2;
  iVar1 = param_2[1];
  if (param_1 == 0) {
    param_1 = FUN_00000a90(uVar2);
  }
  if (iVar1 != 0) {
    (*param_3)(param_1,param_2 + 2,uVar2);
  } else {
    FUN_00011090(param_1,param_2 + 2,uVar2);
  }
  return param_1;
}
