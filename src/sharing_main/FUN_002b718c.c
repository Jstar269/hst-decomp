/* HSTMATCH module=hstp_trans_main.prx start=0x002b718c end=0x002b7198 symbol=FUN_002b718c lang=c99 */
/* Clone of src/eboot/FUN_002a79fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00111aa4();

void FUN_002b718c(int param_1,undefined4 param_2)
{
  FUN_00111aa4(*(undefined4 *)(param_1 + 0x358),param_2,0);
  return;
}
