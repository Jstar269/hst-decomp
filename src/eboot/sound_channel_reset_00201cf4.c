/* HSTMATCH module=EBOOT.BIN start=0x00201cf4 end=0x00201dc8 symbol=FUN_00201cf4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: corrected parameter types and orders for FUN_00093484 and FUN_000937f0; exact match verified; names and types await human review. */

typedef unsigned char undefined1;
typedef unsigned int uint;

extern void FUN_00091c48(int, int);
extern void FUN_00093484(int, float);
extern void FUN_000937f0(int, float, int);
extern void FUN_0012ad54(float, int, uint, undefined1, undefined1, int, int);

void FUN_00201cf4(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    FUN_0012ad54(-1.0f, iVar1, *(uint *)(param_1 + 0x20), *(undefined1 *)(param_1 + 0x28),
                 *(undefined1 *)(param_1 + 0x3c), 0, 1);
    FUN_00093484(*(int *)(param_1 + 8), *(float *)(param_1 + 0x2c));
    FUN_000937f0(*(int *)(param_1 + 8), *(float *)(param_1 + 0x34), -1);
    FUN_00091c48(iVar1, 0);
  }
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    FUN_0012ad54(-1.0f, iVar1, *(uint *)(param_1 + 0x24), *(undefined1 *)(param_1 + 0x29),
                 *(undefined1 *)(param_1 + 0x3d), 0, 1);
    FUN_00093484(*(int *)(param_1 + 0xc), *(float *)(param_1 + 0x30));
    FUN_000937f0(*(int *)(param_1 + 0xc), *(float *)(param_1 + 0x38), -1);
    FUN_00091c48(iVar1, 0);
  }
}
