/* HSTMATCH module=hstp_trans_main.prx start=0x0004a1c4 end=0x0004a220 symbol=FUN_0004a1c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v16) corrected by hand: reordered the branch arms and kept cleanup inside the nonnull case; exact match verified; names and types await human review. */
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

extern undefined DAT_003ba4b0;
extern void FUN_000009e4();
extern void FUN_000506b8();

void FUN_0004a1c4(int param_1)
{
  if (*(int *)(param_1 + 0x20) >= 0) {
    FUN_000506b8((int)&DAT_003ba4b0,*(int *)((int)param_1 + 32));
    *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_000009e4(*(int *)((int)param_1 + 28));
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}
