/* HSTMATCH module=hstp_trans_main.prx start=0x0018eca0 end=0x0018edac symbol=FUN_0018eca0 lang=c99 */
/* Clone of src/eboot/FUN_001825ac.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 FUN_00177e98();
extern void FUN_0018e8a4();
extern void FUN_001920bc();
extern void FUN_001929e8();

void FUN_0018eca0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8, undefined1 uStackX_0)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00177e98();
  uVar2 = (**(code **)(iVar1 + 0x558))();
  FUN_0018e8a4(param_1,uVar2);
  FUN_001920bc(param_1,param_2,param_3,param_4,param_5,param_7,param_6,0,param_8,uStackX_0);
  iVar1 = FUN_00177e98();
  if (*(int *)(*(int *)(iVar1 + 0x5c0) + *(int *)(iVar1 + 0x5b8) * 4) != 4) {
    FUN_001929e8(param_1,param_2,param_3,param_4,param_5,1,param_7,param_8);
  }
  return;
}
