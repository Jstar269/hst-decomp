/* HSTMATCH module=hstp_trans_main.prx start=0x00094fc0 end=0x00095028 symbol=FUN_00094fc0 lang=c99 */
/* Clone of src/eboot/FUN_0009312c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_00378d18[];
extern char DAT_00378d20[];
extern char * FUN_00014d64();

undefined4 FUN_00094fc0(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = (int)(FUN_00014d64(param_1,DAT_00378d18));
    if (iVar1 == param_1) {
      *(undefined1 *)(param_1 + 5) = 0x4c;
    }
    else {
      iVar1 = (int)(FUN_00014d64(param_1,DAT_00378d20));
      if (iVar1 == param_1) {
        *(undefined1 *)(param_1 + 5) = 0x52;
      }
    }
  }
  return 0;
}
