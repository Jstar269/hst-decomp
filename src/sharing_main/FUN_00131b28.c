/* HSTMATCH module=hstp_trans_main.prx start=0x00131b28 end=0x00131b34 symbol=FUN_00131b28 lang=c99 */
/* Clone of src/eboot/FUN_001268b8.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern uint FUN_00104f10();

void FUN_00131b28(int param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_00104f10(*(undefined4 *)(param_1 + 0x1c),param_2,param_3,1);
  return;
}
