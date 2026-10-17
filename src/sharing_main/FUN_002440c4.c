/* HSTMATCH module=hstp_trans_main.prx start=0x002440c4 end=0x0024414c symbol=FUN_002440c4 lang=c99 */
/* Clone of src/eboot/FUN_00233fc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern int * DAT_003f3994;
extern undefined DAT_003f39a8;
extern void FUN_00243618();
extern void FUN_00244258();
extern void FUN_0024476c();

void FUN_002440c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  bool bVar1;
  int iVar2;
  
  if (DAT_003f3994 != (int *)0x0) {
    FUN_00243618(DAT_003f3994,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    iVar2 = DAT_003f3994[3];
    bVar1 = true;
    if ((iVar2 != 6) && (iVar2 != 7)) {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_00244258((int *)&DAT_003f39a8,2);
    }
    else if (iVar2 == 9) {
      FUN_0024476c((int *)&DAT_003f39a8);
    }
  }
  return;
}
