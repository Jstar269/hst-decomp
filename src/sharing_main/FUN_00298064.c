/* HSTMATCH module=hstp_trans_main.prx start=0x00298064 end=0x002980f8 symbol=FUN_00298064 lang=c99 */
/* Clone of src/eboot/FUN_00286938.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003f344c;
extern char DAT_003a78f0[];
extern int FUN_00000a90();
extern uint * FUN_000149a8();
extern int FUN_00014a40();
extern int * FUN_001579f8();
extern int FUN_00157c78();
extern undefined4 FUN_0016243c();

void FUN_00298064(int param_1,undefined4 param_2)
{
  int uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) != 0) {
    FUN_001579f8(*(int *)(param_1 + 4),1);
    *(undefined4 *)(param_1 + 4) = 0;
  }
  uVar1 = FUN_0016243c(*(undefined4 *)(DAT_003f344c + 0x3c),param_2);
  *(undefined4 *)(param_1 + 4) = uVar1;
  iVar2 = FUN_00014a40(param_2);
  uVar1 = FUN_00000a90(iVar2 + 1);
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  FUN_000149a8(uVar1,param_2);
  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = FUN_00157c78(*(int *)(param_1 + 4),DAT_003a78f0);
    *(undefined4 *)(param_1 + 0x3c) = uVar1;
  }
  return;
}
