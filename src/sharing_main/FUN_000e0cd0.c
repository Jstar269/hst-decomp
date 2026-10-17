/* HSTMATCH module=hstp_trans_main.prx start=0x000e0cd0 end=0x000e0cec symbol=FUN_000e0cd0 lang=c99 */
/* Clone of src/eboot/FUN_000dcbcc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_000e0cd0(int param_1)
{
  if (*(uchar *)(param_1 + 0x44) != '\0') {
    *(undefined1 *)(param_1 + 0x65) = 1;
  }
  return;
}
