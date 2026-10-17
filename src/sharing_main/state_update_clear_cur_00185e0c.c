/* HSTMATCH module=hstp_trans_main.prx start=0x00185e0c end=0x00185ea8 symbol=FUN_00185e0c lang=c99 */
/* Clone of src/eboot/state_update_clear_cur_00179718.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the table symbol passed as &DAT_003eaad8 (addiu, not ori), the callee 0x1b1f7c takes the tested member as its dropped second argument, and the sign test is >= 0; exact match verified; names and types await human review. */
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

extern undefined DAT_003eaad8;
extern void FUN_0017da40();
extern void FUN_001819fc();
extern void FUN_0018905c();
extern void FUN_0018b0b4();
extern void FUN_0018cfb8();
extern int FUN_001c0010(void *, int);
extern void FUN_0020d6d4();

void FUN_00185e0c(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  FUN_0017da40();
  if (*(int *)(param_1 + 0x6c) >= 2) {
    FUN_001819fc(param_1);
  }
  iVar1 = *(int *)(param_1 + 0x70);
  if (iVar1 != 0x17) {
    FUN_0018cfb8(*(undefined4 *)(param_1 + 0x174));
    FUN_0018905c(*(undefined4 *)(param_1 + 0x178));
    FUN_0018b0b4(*(undefined4 *)(param_1 + 0x17c));
  }
  uVar2 = *(undefined4 *)(param_1 + 0x70);
  FUN_0020d6d4(uVar2,*(undefined4 *)(param_1 + 0x90),0);
  if (*(int *)(param_1 + 0x634) >= 0 && (iVar1 = FUN_001c0010(&DAT_003eaad8, *(int *)(param_1 + 0x634)), iVar1 == 0)) {
    *(undefined4 *)(param_1 + 0x634) = 0xffffffff;
  }
  return;
}
