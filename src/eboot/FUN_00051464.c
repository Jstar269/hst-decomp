/* HSTMATCH module=EBOOT.BIN start=0x00051464 end=0x00051478 symbol=FUN_00051464 lang=c99 */
/* Clone of src/sharing_main/FUN_00051df0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_00311170;
extern undefined4 FUN_00050044();

void FUN_00051464(int param_1)
{
  FUN_00050044((int)&DAT_00311170,*(undefined4 *)(param_1 + 4),0);
  return;
}
