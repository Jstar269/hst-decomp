/* HSTMATCH module=hstp_trans_main.prx start=0x0008e860 end=0x0008e894 symbol=FUN_0008e860 lang=c99 */
/* Clone of src/eboot/FUN_0008d114.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern uint * FUN_000114c0();

void FUN_0008e860(int param_1)
{
  FUN_000114c0(param_1,0,0x1c);
  *(undefined4 *)(param_1 + 8) = 1;
  return;
}
