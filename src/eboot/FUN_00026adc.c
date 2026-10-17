/* HSTMATCH module=EBOOT.BIN start=0x00026adc end=0x00026af4 symbol=FUN_00026adc lang=c99 */
/* Clone of src/sharing_main/FUN_00026a74.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_000266ac();
extern void FUN_00027b64();
extern void FUN_000292d8();

void FUN_00026adc(int *param_1,undefined1 (*param_2) [12],undefined4 param_3)
{
  FUN_000266ac(param_1,param_2,param_3,FUN_000292d8,FUN_00027b64,'\x01');
  return;
}
