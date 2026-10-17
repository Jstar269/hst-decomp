/* HSTMATCH module=hstp_trans_main.prx start=0x00113ccc end=0x00113cf4 symbol=FUN_00113ccc lang=c99 */
/* Clone of src/eboot/FUN_0010d724.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_00107ddc();

void FUN_00113ccc(int param_1)
{
  FUN_00107ddc();
  *(undefined4 *)(param_1 + 0xf8) = 0;
  return;
}
