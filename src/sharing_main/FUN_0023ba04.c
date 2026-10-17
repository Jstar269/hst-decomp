/* HSTMATCH module=hstp_trans_main.prx start=0x0023ba04 end=0x0023ba20 symbol=FUN_0023ba04 lang=c99 */
/* Clone of src/eboot/FUN_0022bf94.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003ea8e8;
extern void FUN_001cdd24();

void FUN_0023ba04(undefined4 param_1,undefined4 param_2)
{
  FUN_001cdd24(DAT_003ea8e8 + 0x80,param_1,param_2,4);
  return;
}
