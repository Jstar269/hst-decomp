/* HSTMATCH module=hstp_trans_main.prx start=0x000df14c end=0x000df184 symbol=FUN_000df14c lang=c99 */
/* Clone of src/eboot/FUN_000d7420.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00000a00();

void FUN_000df14c(undefined4 param_1,uint *param_2)
{
  if (((param_2 != (uint *)0x0) && (param_2 != (uint *)0x0)) && ((*param_2 & 1) != 0)) {
    FUN_00000a00(param_2[2]);
  }
  return;
}
