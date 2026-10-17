/* HSTMATCH module=EBOOT.BIN start=0x000fb074 end=0x000fb07c symbol=FUN_000fb074 lang=c99 */
/* Clone of src/eboot/FUN_0019075c.c (hstclone.py tag u1r1ee): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_000fa9d4();

void FUN_000fb074(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  FUN_000fa9d4(*(int **)(param_1 + 0x3c),param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}
