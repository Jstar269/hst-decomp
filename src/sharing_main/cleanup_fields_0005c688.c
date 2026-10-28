/* HSTMATCH module=hstp_trans_main.prx start=0x0005c688 end=0x0005c700 symbol=FUN_0005c688 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v16) corrected by hand: simplified field cleanup branches and typed helpers; exact match verified; names and types await human review. */

extern void FUN_000009e4(int);
extern void FUN_00000a00(int *);

int FUN_0005c688(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_000009e4(*(int *)(param_1 + 0x1c));
      *(int *)(param_1 + 0x1c) = 0;
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      FUN_000009e4(*(int *)(param_1 + 0x24));
      *(int *)(param_1 + 0x24) = 0;
    }
    if (param_2 > 0) {
      FUN_00000a00((int *)param_1);
    }
  }
  return param_1;
}
