/* HSTMATCH module=hstp_trans_main.prx start=0x0006b76c end=0x0006b7b8 symbol=FUN_0006b76c lang=c99 */
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

extern undefined4 DAT_003daf68;
extern void FUN_0006c7e8();

undefined4 FUN_0006b76c(undefined4 param_1)
{
  undefined4 uVar1;
  int local_4;
  undefined4 local_8;
  
  local_8 = param_1;
  FUN_0006c7e8(&local_4,DAT_003daf68 + 0x1c,&local_8);
  if (local_4 == DAT_003daf68 + 0x20) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_4 + 0x10);
  }
  return uVar1;
}
