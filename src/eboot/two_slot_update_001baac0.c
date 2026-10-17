/* HSTMATCH module=EBOOT.BIN start=0x001baac0 end=0x001bab98 symbol=FUN_001baac0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the flag byte is set with `if (b) 1 else 0` (truthy test; the `== 0` order puts the store in the other branch-likely slot); exact match verified; names and types await human review. */
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

extern undefined1 FUN_001baf80();
extern void FUN_00206290();

void FUN_001baac0(int param_1,int *param_2)
{
  undefined1 uVar1;
  
  if (*(uchar *)(*param_2 + 0x60) != '\0') {
    uVar1 = FUN_001baf80(*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 8) + 4));
    FUN_00206290(*(undefined4 *)(*(int *)(param_1 + 4) + 8),uVar1,*(undefined4 *)(*param_2 + 100));
    *(undefined1 *)(param_1 + 0x12) = 1;
    *(undefined1 *)(param_1 + 0x16) = 1;
    if (*(uchar *)(*param_2 + 0x6a)) {
      *(undefined1 *)(param_1 + 0x1a) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x1a) = 0;
    }
  }
  if (*(uchar *)(*param_2 + 0x90) != '\0') {
    uVar1 = FUN_001baf80(*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 4));
    FUN_00206290(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc),uVar1,*(undefined4 *)(*param_2 + 0x94)
                );
    *(undefined1 *)(param_1 + 0x13) = 1;
    *(undefined1 *)(param_1 + 0x17) = 1;
    if (*(uchar *)(*param_2 + 0x9a)) {
      *(undefined1 *)(param_1 + 0x1b) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x1b) = 0;
    }
  }
  return;
}
