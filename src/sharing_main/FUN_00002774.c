/* HSTMATCH module=hstp_trans_main.prx start=0x00002774 end=0x000027d4 symbol=FUN_00002774 lang=c99 */
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

extern undefined DAT_003b3310;
extern undefined DAT_003b3314;

int FUN_00002774(undefined4 param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)&DAT_003b3310;
  do {
    if (*piVar2 == 0) {
      *(undefined4 *)(&DAT_003b3310 + iVar1 * 8) = param_1;
      piVar2 = (int *)((int)&DAT_003b3314 + iVar1 * 8);
      *piVar2 = param_2;
      *piVar2 = param_2 + -0xc;
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 2;
  } while (iVar1 < 0x10);
  return -1;
}
