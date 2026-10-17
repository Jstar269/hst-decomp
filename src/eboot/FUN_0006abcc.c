/* HSTMATCH module=EBOOT.BIN start=0x0006abcc end=0x0006ac10 symbol=FUN_0006abcc lang=c99 */
/* Clone of src/sharing_main/FUN_0006c1b4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_000006e8();
extern void FUN_000009e4();
extern void FUN_00056cb0();

void FUN_0006abcc(undefined4 *param_1)
{
  FUN_000009e4(param_1[2]);
  param_1[2] = 0;
  FUN_000006e8(param_1[1],FUN_00056cb0);
  param_1[1] = 0;
  *param_1 = 0;
  return;
}
