/* HSTMATCH module=hstp_trans_main.prx start=0x000e0da4 end=0x000e0e68 symbol=FUN_000e0da4 lang=c99 */
/* Clone of src/eboot/FUN_000dcca0.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the merged else-branch split back into two independent member tests; exact match verified; names and types await human review. */
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
extern int FUN_00089f84();

void FUN_000e0da4(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  if (0 < param_3) {
    *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + param_3;
  }
  iVar1 = FUN_00089f84(DAT_003e19f0);
  if (param_2 == *(int *)(iVar1 + 0x148)) {
    if (*(int *)(param_1 + 0x8c) == 1) {
      *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x1ec) =
           *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x1ec) + param_3;
    }
    if (*(int *)(param_1 + 0x8c) == 2) {
      *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x208) =
           *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x208) + param_3;
    }
  }
  if (param_3 < 0) {
    *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + param_3;
  }
  return;
}
