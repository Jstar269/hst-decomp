/* HSTMATCH module=hstp_trans_main.prx start=0x00097edc end=0x00097f14 symbol=FUN_00097edc lang=c99 */
/* Clone of src/eboot/FUN_00095dd8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

int FUN_00097edc(int param_1)
{
  *(undefined4 *)(param_1 + 0x2c) = 1;
  FUN_000114c0(param_1,0,0x40);
  return param_1;
}
