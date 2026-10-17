/* HSTMATCH module=EBOOT.BIN start=0x0001f1fc end=0x0001f20c symbol=FUN_0001f1fc lang=c99 */
/* Clone of src/sharing_main/FUN_0001ef14.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_0001f1fc(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x24) = param_2;
  *(undefined1 *)(param_1 + 0x2c) = param_2;
  *(undefined1 *)(param_1 + 0x34) = param_2;
  return;
}
