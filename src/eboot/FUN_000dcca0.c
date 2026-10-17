/* HSTMATCH module=EBOOT.BIN start=0x000dcca0 end=0x000dcd64 symbol=FUN_000dcca0 lang=c99 */
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

extern undefined4 DAT_003386b0;
extern int FUN_0008882c();

void FUN_000dcca0(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  if (0 < param_3) {
    *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + param_3;
  }
  iVar1 = FUN_0008882c(DAT_003386b0);
  if (param_2 == *(int *)(iVar1 + 0x148)) {
    if (*(int *)(param_1 + 0x8c) == 1) {
      *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1ec) =
           *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1ec) + param_3;
    }
    if (*(int *)(param_1 + 0x8c) == 2) {
      *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x208) =
           *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x208) + param_3;
    }
  }
  if (param_3 < 0) {
    *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + param_3;
  }
  return;
}
