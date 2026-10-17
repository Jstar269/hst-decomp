/* HSTMATCH module=hstp_trans_main.prx start=0x00189c90 end=0x00189e1c symbol=FUN_00189c90 lang=c99 */
/* Clone of src/eboot/apply_selected_entry_0017d59c.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: flag local is unsigned char (lbu) and the conditional param_2 reassignment is a ternary; exact match verified; names and types await human review. */
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

extern void FUN_000962f4();
extern void FUN_00188a90();
extern void FUN_00188dc8();
extern void FUN_0020c8c4();
extern int FUN_0020ca14();
extern int FUN_0020cd54();
extern void FUN_0020cf88();

void FUN_00189c90(int param_1,int param_2,undefined4 param_3,int param_4,int param_5, undefined4 param_6)
{
  int iVar1;
  unsigned char local_1;
  
  local_1 = '\0';
  iVar1 = FUN_0020ca14(param_1 + 0x5c,&local_1,param_5,param_3,param_2,param_4,param_6);
  if (iVar1 != 0x7fffffff) {
    param_2 = (local_1 != '\0') ? param_1 + iVar1 * 0x20 + 100 : param_2;
    FUN_0020cd54(param_1 + 0x1a0,param_5,param_3,param_2,param_4);
    FUN_0020cf88(param_1 + 0x1a0);
    if (param_4 == 0) {
      *(undefined4 *)(param_1 + 0x19c) = 0;
      *(undefined4 *)(param_1 + 0x2e0) = 0;
      FUN_0020c8c4(0);
      FUN_00188dc8(param_1,1);
      FUN_00188a90(param_1,1);
    }
    else {
      *(undefined4 *)(param_1 + 0x19c) = 3;
      *(undefined4 *)(param_1 + 0x2e0) = 3;
      if (*(int *)(param_2 + 0x14) != 0x7fffffff) {
        FUN_000962f4(*(int *)(*(int *)(param_1 + 8) + param_5 * 4) + 0x10,5);
      }
      iVar1 = *(int *)(param_2 + 0xc);
      if (iVar1 != 0x7fffffff) {
        FUN_000962f4(*(int *)(*(int *)(param_1 + 8) + param_5 * 4) + 0x10,3);
      }
      iVar1 = *(int *)(param_2 + 0x10);
      if (iVar1 != 0x7fffffff) {
        FUN_000962f4(*(int *)(*(int *)(param_1 + 8) + param_5 * 4) + 0x10,4);
      }
    }
  }
  return;
}
