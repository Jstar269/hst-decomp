/* HSTMATCH module=EBOOT.BIN start=0x0006a208 end=0x0006a254 symbol=FUN_0006a208 lang=c99 */
/* Clone of src/sharing_main/FUN_0006b76c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00331c28;
extern void FUN_0006b200();

undefined4 FUN_0006a208(undefined4 param_1)
{
  undefined4 uVar1;
  int local_4;
  undefined4 local_8;
  
  local_8 = param_1;
  FUN_0006b200(&local_4,DAT_00331c28 + 0x1c,&local_8);
  if (local_4 == DAT_00331c28 + 0x20) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_4 + 0x10);
  }
  return uVar1;
}
