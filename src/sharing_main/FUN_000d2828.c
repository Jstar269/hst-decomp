/* HSTMATCH module=hstp_trans_main.prx start=0x000d2828 end=0x000d2854 symbol=FUN_000d2828 lang=c99 */
/* Clone of src/eboot/FUN_000cec2c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0005ffd8();

void FUN_000d2828(int param_1)
{
  if (*(uchar *)(param_1 + 0x3c) != '\0') {
    FUN_0005ffd8(param_1 + 0x40,0);
  }
  return;
}
