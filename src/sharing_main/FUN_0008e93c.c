/* HSTMATCH module=hstp_trans_main.prx start=0x0008e93c end=0x0008e97c symbol=FUN_0008e93c lang=c99 */
/* Clone of src/eboot/FUN_0008d1ec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern uint * FUN_000114c0();

int FUN_0008e93c(int param_1)
{
  FUN_000114c0(param_1,0,0x6c);
  *(undefined2 *)(param_1 + 0x68) = 0xffff;
  *(undefined2 *)(param_1 + 0x6a) = 0xffff;
  *(undefined2 *)(param_1 + 0x24) = 0xffff;
  return param_1;
}
