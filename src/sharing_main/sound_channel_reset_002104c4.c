/* HSTMATCH module=hstp_trans_main.prx start=0x002104c4 end=0x00210598 symbol=FUN_002104c4 lang=c99 */
/* Clone of src/eboot/sound_channel_reset_00201cf4.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: corrected parameter types and orders for FUN_000953a8 and FUN_00095714; exact match verified; names and types await human review. */

typedef unsigned char undefined1;
typedef unsigned int uint;

extern void FUN_000938e0(int, int);
extern void FUN_000953a8(int, float);
extern void FUN_00095714(int, float, int);
extern void FUN_001361c0(float, int, uint, undefined1, undefined1, int, int);

void FUN_002104c4(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    FUN_001361c0(-1.0f, iVar1, *(uint *)(param_1 + 0x20), *(undefined1 *)(param_1 + 0x28),
                 *(undefined1 *)(param_1 + 0x3c), 0, 1);
    FUN_000953a8(*(int *)(param_1 + 8), *(float *)(param_1 + 0x2c));
    FUN_00095714(*(int *)(param_1 + 8), *(float *)(param_1 + 0x34), -1);
    FUN_000938e0(iVar1, 0);
  }
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    FUN_001361c0(-1.0f, iVar1, *(uint *)(param_1 + 0x24), *(undefined1 *)(param_1 + 0x29),
                 *(undefined1 *)(param_1 + 0x3d), 0, 1);
    FUN_000953a8(*(int *)(param_1 + 0xc), *(float *)(param_1 + 0x30));
    FUN_00095714(*(int *)(param_1 + 0xc), *(float *)(param_1 + 0x38), -1);
    FUN_000938e0(iVar1, 0);
  }
}
