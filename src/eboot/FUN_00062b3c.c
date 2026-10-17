/* HSTMATCH module=EBOOT.BIN start=0x00062b3c end=0x00062b64 symbol=FUN_00062b3c lang=c99 */
/* Clone of src/sharing_main/FUN_00063a00.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_000784d4();

undefined4 FUN_00062b3c(int param_1)
{
  undefined4 uVar1;
  
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_000784d4();
  }
  return uVar1;
}
