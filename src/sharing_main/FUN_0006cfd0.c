/* HSTMATCH module=hstp_trans_main.prx start=0x0006cfd0 end=0x0006d010 symbol=FUN_0006cfd0 lang=c99 */
/* Clone of src/eboot/FUN_0022995c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0006df1c();

void FUN_0006cfd0(undefined4 *param_1)
{
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    FUN_0006df1c(param_1,(undefined4 *)param_1[1]);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = (unsigned int)(param_1 + 1);
  }
  return;
}
