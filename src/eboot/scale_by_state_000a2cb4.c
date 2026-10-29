/* HSTMATCH module=EBOOT.BIN start=0x000a2cb4 end=0x000a2d90 symbol=FUN_000a2cb4 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (inputs/generated/FUN_000a2cb4.c, no hstgen tag) corrected by hand: float constant first in the products, the lookup table typed float[] so the index scales once, the if/else chain rewritten as a switch with cases in source order (the compare chain then tests them in reverse), per-case products parenthesised; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern float DAT_003411c8;
extern float DAT_003411cc[];
extern u32 FUN_000b3c68();
extern float FUN_00163d68(u32, u32);

typedef struct ScaledObj {
  char pad000[0x154];
  u32 unk154;       /* 0x154 */
  char pad158[0x440 - 0x158];
  int unk440;       /* 0x440 index into the percentage table when positive */
  int unk444;       /* 0x444 selector 0..4 applied after the table factor */
} ScaledObj;

float FUN_000a2cb4(ScaledObj *obj)
{
  float scale;

  scale = 0.01f * (float)FUN_00163d68(FUN_000b3c68(), obj->unk154);
  if (0 < obj->unk440) {
    scale = scale * (0.01f * DAT_003411cc[obj->unk440]);
  }
  switch (obj->unk444) {
  case 0:
    scale = 0.0f;
    break;
  case 1:
    scale = scale * (0.01f * DAT_003411cc[0]);
    break;
  case 2:
    scale = scale * (0.01f * DAT_003411c8);
    break;
  case 3:
    break;
  case 4:
    break;
  }
  return scale;
}
