/* HSTMATCH module=hstp_trans_main.prx start=0x00051da4 end=0x00051df0 symbol=FUN_00051da4 lang=c99 */
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

extern undefined DAT_003ba4b0;
extern undefined4 FUN_00050aec();

void FUN_00051da4(int param_1,undefined1 param_2,undefined1 param_3)
{
  int iVar1;
  
  iVar1 = FUN_00050aec((int)&DAT_003ba4b0,*(undefined4 *)(param_1 + 4));
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x92) = param_2;
    *(undefined1 *)(iVar1 + 0x93) = param_3;
  }
  return;
}
