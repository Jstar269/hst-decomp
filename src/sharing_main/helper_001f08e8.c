/* HSTMATCH module=hstp_trans_main.prx start=0x001f08e8 end=0x001f09f4 symbol=FUN_001f08e8 lang=c99 */
/* Clone of src/eboot/helper_001e2694.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: used the owner-relative field offset +0x175c; exact match verified; names and types await human review. */
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

extern void FUN_00108f54();
extern void FUN_001f4118();
extern void FUN_0022da40();

void FUN_001f08e8(int param_1)
{
  int iVar1;
  
  if (*(int *)(param_1 + 500) != 0) {
    FUN_00108f54(*(int *)(param_1 + 500),1);
  }
  iVar1 = *(int *)(param_1 + 0x9b4);
  if (iVar1 != 0) {
    FUN_00108f54(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x810);
  if (iVar1 != 0) {
    FUN_00108f54(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x175c);
  if (iVar1 != 0) {
    FUN_00108f54(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x1954);
  if (iVar1 != 0) {
    FUN_00108f54(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x1d68);
  if (iVar1 != 0) {
    FUN_00108f54(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x1958);
  if (iVar1 != 0) {
    FUN_00108f54(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x1d64);
  if (iVar1 != 0) {
    FUN_0022da40(iVar1,1,0);
  }
  iVar1 = *(int *)(param_1 + 0x21e4);
  if (iVar1 != 0) {
    FUN_00108f54(iVar1,1);
  }
  iVar1 = *(int *)(param_1 + 0x235c);
  if (iVar1 != 0) {
    FUN_00108f54(iVar1,1);
  }
  FUN_001f4118(param_1);
  if (*(int *)(param_1 + 0x25b8) != 0) {
    FUN_00108f54(*(int *)(param_1 + 0x25b8),1);
  }
  return;
}
