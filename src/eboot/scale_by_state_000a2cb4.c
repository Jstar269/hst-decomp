/* HSTMATCH module=EBOOT.BIN start=0x000a2cb4 end=0x000a2d90 symbol=FUN_000a2cb4 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (inputs/generated/FUN_000a2cb4.c, no hstgen tag) corrected by hand: float constant first in the products, the lookup table typed float[] so the index scales once, the if/else chain rewritten as a switch with cases in source order (the compare chain then tests them in reverse), per-case products parenthesised; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

extern float DAT_003411c8;
extern float DAT_003411cc[];
extern undefined4 FUN_000b3c68();
extern float FUN_00163d68(undefined4, undefined4);

float FUN_000a2cb4(int param_1)
{
  float fVar3;

  fVar3 = 0.01f * (float)FUN_00163d68(FUN_000b3c68(), *(undefined4 *)(param_1 + 0x154));
  if (0 < *(int *)(param_1 + 0x440)) {
    fVar3 = fVar3 * (0.01f * DAT_003411cc[*(int *)(param_1 + 0x440)]);
  }
  switch (*(int *)(param_1 + 0x444)) {
  case 0:
    fVar3 = 0.0f;
    break;
  case 1:
    fVar3 = fVar3 * (0.01f * DAT_003411cc[0]);
    break;
  case 2:
    fVar3 = fVar3 * (0.01f * DAT_003411c8);
    break;
  case 3:
    break;
  case 4:
    break;
  }
  return fVar3;
}
