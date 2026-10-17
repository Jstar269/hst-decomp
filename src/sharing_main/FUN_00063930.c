/* HSTMATCH module=hstp_trans_main.prx start=0x00063930 end=0x00063960 symbol=FUN_00063930 lang=c99 */
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

extern undefined4 FUN_00078d90();

bool FUN_00063930(int param_1)
{
  bool bVar1;
  uint uVar2;
  
  if (param_1 < 0) {
    bVar1 = false;
  }
  else {
    uVar2 = FUN_00078d90();
    bVar1 = (uVar2 & 3) != 0;
  }
  return bVar1;
}
