/* HSTMATCH module=hstp_trans_main.prx start=0x002a1bb4 end=0x002a1c2c symbol=FUN_002a1bb4 lang=c99 */
/* Clone of src/eboot/FUN_0029045c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_003a83f0[];
extern char DAT_003a8418[];
extern void FUN_002a130c();
extern int FUN_002c7488();
extern int FUN_002c74a8();

undefined4 FUN_002a1bb4(undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_002c74a8(param_1,0,0,0,0);
  if (iVar1 < 0) {
    FUN_002a130c(DAT_003a83f0,iVar1);
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_002c7488(param_1);
    if (iVar1 < 0) {
      FUN_002a130c(DAT_003a8418,iVar1);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}
