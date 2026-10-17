/* HSTMATCH module=EBOOT.BIN start=0x00062a6c end=0x00062a9c symbol=FUN_00062a6c lang=c99 */
/* Clone of src/sharing_main/FUN_00063930.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 FUN_000775d0();

bool FUN_00062a6c(int param_1)
{
  bool bVar1;
  uint uVar2;
  
  if (param_1 < 0) {
    bVar1 = false;
  }
  else {
    uVar2 = FUN_000775d0();
    bVar1 = (uVar2 & 3) != 0;
  }
  return bVar1;
}
