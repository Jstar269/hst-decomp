/* HSTMATCH module=hstp_trans_main.prx start=0x0006c7e8 end=0x0006c85c symbol=FUN_0006c7e8 lang=c99 */
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

extern undefined4 * FUN_0006d71c();

void FUN_0006c7e8(int *param_1,char *param_2,int *param_3)
{
  char *iVar1;
  
  iVar1 = (char *)(FUN_0006d71c(param_2,param_3,*(undefined4 *)(param_2 + 4),param_2 + 4));
  if ((iVar1 == param_2 + 4) || (*param_3 < *(int *)(iVar1 + 0xc))) {
    *param_1 = (int)(param_2 + 4);
  }
  else {
    *param_1 = (int)(iVar1);
  }
  return;
}
