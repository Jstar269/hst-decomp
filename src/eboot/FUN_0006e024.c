/* HSTMATCH module=EBOOT.BIN start=0x0006e024 end=0x0006e094 symbol=FUN_0006e024 lang=c99 */
/* Clone of src/sharing_main/FUN_0006f6ec.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined * DAT_00331c2c;
extern void FUN_00000a00();
extern void FUN_0006e93c();

int FUN_0006e024(int param_1,short param_2)
{
  if (param_1 != 0) {
    if ((DAT_00331c2c != 0) && (*(int *)(param_1 + 4) != 0)) {
      FUN_0006e93c(DAT_00331c2c + 0xc,*(int *)((int)param_1 + 4));
      *(undefined4 *)(param_1 + 4) = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
