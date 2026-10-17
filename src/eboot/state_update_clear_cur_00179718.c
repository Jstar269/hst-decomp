/* HSTMATCH module=EBOOT.BIN start=0x00179718 end=0x001797b4 symbol=FUN_00179718 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the table symbol passed as &DAT_0034179c (addiu, not ori), the callee 0x1b1f7c takes the tested member as its dropped second argument, and the sign test is >= 0; exact match verified; names and types await human review. */
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

extern undefined DAT_0034179c;
extern void FUN_00171714();
extern void FUN_001755b8();
extern void FUN_0017c968();
extern void FUN_0017e9c0();
extern void FUN_001808c4();
extern int FUN_001b1f7c(void *, int);
extern void FUN_001fef04();

void FUN_00179718(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00171714();
  if (*(int *)(param_1 + 0x6c) >= 2) {
    FUN_001755b8(param_1);
  }
  iVar1 = *(int *)(param_1 + 0x70);
  if (iVar1 != 0x17) {
    FUN_001808c4(*(undefined4 *)(param_1 + 0x174));
    FUN_0017c968(*(undefined4 *)(param_1 + 0x178));
    FUN_0017e9c0(*(undefined4 *)(param_1 + 0x17c));
  }
  uVar2 = *(undefined4 *)(param_1 + 0x70);
  FUN_001fef04(uVar2,*(undefined4 *)(param_1 + 0x90),0);
  if (*(int *)(param_1 + 0x634) >= 0 && (iVar1 = FUN_001b1f7c(&DAT_0034179c, *(int *)(param_1 + 0x634)), iVar1 == 0)) {
    *(undefined4 *)(param_1 + 0x634) = 0xffffffff;
  }
  return;
}
