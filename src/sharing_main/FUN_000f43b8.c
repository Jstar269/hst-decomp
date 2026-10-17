/* HSTMATCH module=hstp_trans_main.prx start=0x000f43b8 end=0x000f4414 symbol=FUN_000f43b8 lang=c99 */
/* Clone of src/eboot/FUN_000eecf0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e19f0;
extern void FUN_00105470();
extern void FUN_00108a2c();

void FUN_000f43b8(int param_1)
{
  undefined1 uVar1;
  
  if (*(uchar *)(param_1 + 0x54) == '\0') {
    uVar1 = *(undefined1 *)(DAT_003e19f0 + 0x4c);
    FUN_00105470(*(undefined4 *)(param_1 + 0x5c),uVar1);
    FUN_00105470(*(undefined4 *)(param_1 + 0x60),uVar1);
    FUN_00108a2c(param_1);
  }
  return;
}
