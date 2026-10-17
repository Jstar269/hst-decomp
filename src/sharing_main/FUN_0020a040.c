/* HSTMATCH module=hstp_trans_main.prx start=0x0020a040 end=0x0020a080 symbol=FUN_0020a040 lang=c99 */
/* Clone of src/eboot/FUN_001cd88c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0020a090();

void FUN_0020a040(int param_1,undefined4 param_2,int param_3)
{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  if (param_3 < 1) {
    FUN_0020a090();
    *(undefined4 *)(param_1 + 8) = 0xffffffff;
  }
  else {
    *(int *)(param_1 + 0xc) = param_3;
  }
  return;
}
