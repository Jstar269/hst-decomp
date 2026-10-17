/* HSTMATCH module=hstp_trans_main.prx start=0x002a1c2c end=0x002a1d14 symbol=FUN_002a1c2c lang=c99 */
/* Clone of src/eboot/FUN_002904d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_003a8440[];
extern char DAT_003a845c[];
extern char DAT_003a8478[];
extern uint * FUN_000149a8();
extern undefined1 * FUN_00022da4();
extern void FUN_002a130c();
extern int FUN_002c7728();

undefined4 FUN_002a1c2c(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  int iVar2;
  int local_4;
  
  if (*(uchar *)(param_1 + 0x28) == '\0') {
    FUN_002a130c(DAT_003a8440);
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x8c) = 1;
    FUN_000149a8(param_1 + 0x94);
    *(undefined4 *)(param_1 + 0x90) = param_3;
    FUN_00022da4(*(undefined4 *)(param_1 + 0x2c),0,0x88000);
    iVar2 = FUN_002c7728(*(undefined4 *)(param_1 + 0x88),param_1 + 0x8c,0x48,0,&local_4);
    if (iVar2 == -0x7ffdfe4d) {
      FUN_002a130c(DAT_003a845c);
    }
    else if ((iVar2 != 0) || (local_4 != 0x48)) {
      FUN_002a130c(DAT_003a8478,iVar2,local_4);
      return 0;
    }
    uVar1 = 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  return uVar1;
}
