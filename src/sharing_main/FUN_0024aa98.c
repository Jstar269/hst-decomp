/* HSTMATCH module=hstp_trans_main.prx start=0x0024aa98 end=0x0024aac0 symbol=FUN_0024aa98 lang=c99 */
/* Clone of src/eboot/FUN_0023a900.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0024c4d0();

void FUN_0024aa98(int param_1)
{
  if (0 < *(int *)(param_1 + 0x3c)) {
    FUN_0024c4d0(param_1 + 0x50);
  }
  return;
}
