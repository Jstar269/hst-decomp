/* HSTMATCH module=EBOOT.BIN start=0x000c50cc end=0x000c5100 symbol=FUN_000c50cc lang=c99 */
/* Clone of src/sharing_main/FUN_000c8b50.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00338ac4;
extern undefined4 FUN_000bae04();
extern void FUN_002862a8();

void FUN_000c50cc(int param_1)
{
  FUN_002862a8(*(undefined4 *)(param_1 + 0x784));
  if (DAT_00338ac4 != 0) {
    FUN_000bae04(DAT_00338ac4);
  }
  return;
}
