/* HSTMATCH module=EBOOT.BIN start=0x0006e870 end=0x0006e8e0 symbol=FUN_0006e870 lang=c99 */
/* Clone of src/sharing_main/FUN_00070030.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00051490();
extern void FUN_0005185c();
extern void FUN_0005a770();

void FUN_0006e870(undefined4 *param_1,undefined4 param_2)
{
  if (param_1[1] != 0) {
    FUN_00051490(*param_1,0,0,0x1e0,0x110,0,0);
    FUN_0005a770(param_1[1],*param_1,param_2,0);
    FUN_0005185c(*param_1);
  }
  return;
}
