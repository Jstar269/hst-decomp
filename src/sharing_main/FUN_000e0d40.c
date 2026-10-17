/* HSTMATCH module=hstp_trans_main.prx start=0x000e0d40 end=0x000e0d58 symbol=FUN_000e0d40 lang=c99 */
/* Clone of src/eboot/FUN_000dcc3c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_000e0d40(int param_1,undefined1 param_2)
{
  if (*(uchar *)(param_1 + 0x44) != '\0') {
    *(undefined1 *)(param_1 + 0x70) = param_2;
  }
  return;
}
