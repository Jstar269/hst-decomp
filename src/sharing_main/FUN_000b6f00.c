/* HSTMATCH module=hstp_trans_main.prx start=0x000b6f00 end=0x000b6f40 symbol=FUN_000b6f00 lang=c99 */
/* Clone of src/eboot/FUN_000b3ca0.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_000007f4();
extern void FUN_00089f2c();
extern void FUN_000b6f40();

int FUN_000b6f00(int param_1)
{
  FUN_000007f4(param_1,FUN_000b6f40,FUN_00089f2c,0xc,2);
  return param_1;
}
