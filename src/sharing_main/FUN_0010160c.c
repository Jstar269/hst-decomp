/* HSTMATCH module=hstp_trans_main.prx start=0x0010160c end=0x00101620 symbol=FUN_0010160c lang=c99 */
/* Clone of src/eboot/FUN_000fbed0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_0010160c(int param_1,int param_2)
{
  *(char *)(param_1 + 0x58) = (char)param_2;
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  return;
}
