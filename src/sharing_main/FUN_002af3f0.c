/* HSTMATCH module=hstp_trans_main.prx start=0x002af3f0 end=0x002af484 symbol=FUN_002af3f0 lang=c99 */
/* Clone of src/eboot/FUN_002a00ac.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_002dbb18[];
extern char DAT_002dbb2c[];
extern char DAT_002dbb70[];
extern char DAT_002dbbb4[];
extern void FUN_002ad710();
extern int FUN_002c7678();
extern int FUN_002c76c0();

void FUN_002af3f0(int param_1,undefined4 param_2)
{
  undefined4 uVar2;
  int iVar1;
  int local_4;
  
  iVar1 = FUN_002c76c0(DAT_002dbbb4,param_2,0x28,0x18000,0,0);
  *(int *)(param_1 + 0x28) = iVar1;
  if (iVar1 < 0) {
    FUN_002ad710(DAT_002dbb70,iVar1);
  }
  local_4 = param_1;
  iVar1 = FUN_002c7678(*(undefined4 *)(param_1 + 0x28),4,&local_4);
  if (iVar1 < 0) {
    FUN_002ad710(DAT_002dbb2c,*(undefined4 *)(param_1 + 0x28));
    uVar2 = *(undefined4 *)(param_1 + 0x28);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x28);
  }
  FUN_002ad710(DAT_002dbb18,uVar2);
  return;
}
