/* HSTMATCH module=hstp_trans_main.prx start=0x0020c81c end=0x0020c850 symbol=FUN_0020c81c lang=c99 */
/* Clone of src/eboot/FUN_001fe04c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0021019c();
extern void FUN_002108fc();

void FUN_0020c81c(int param_1)
{
  FUN_0021019c(param_1 + 200);
  FUN_002108fc(param_1 + 0x1250,param_1 + 0xcd0);
  return;
}
