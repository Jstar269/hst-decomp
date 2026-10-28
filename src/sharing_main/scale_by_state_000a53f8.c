/* HSTMATCH module=hstp_trans_main.prx start=0x000a53f8 end=0x000a54fc symbol=FUN_000a53f8 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (via the EBOOT twin src/eboot/scale_by_state_000a2cb4.c, no hstgen tag) corrected by hand: twin source with Sharing addresses and the debug-build default ASSERT(false) (Player.cpp line 6693) as a real assert; exact match verified; names and types await human review. */
#include "hst/types.h"

extern float DAT_003ea508;
extern float DAT_003ea50c[];
extern u32 FUN_000b6e80();
extern float FUN_001703f0(u32, u32);

extern const char DAT_0037a6cc[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_0037a704[];   /* "Player.cpp" */
extern const char DAT_0037a8b8[];   /* "false" */
extern void FUN_00097e3c();
#define HST_ASSERT(cond, text, line) do { if (!(cond)) { FUN_00097e3c(DAT_0037a6cc, text, DAT_0037a704, line); for (;;) {} } } while (0)

float FUN_000a53f8(int param_1)
{
  float fVar3;

  fVar3 = 0.01f * (float)FUN_001703f0(FUN_000b6e80(), *(u32 *)(param_1 + 0x154));
  if (0 < *(int *)(param_1 + 0x440)) {
    fVar3 = fVar3 * (0.01f * DAT_003ea50c[*(int *)(param_1 + 0x440)]);
  }
  switch (*(int *)(param_1 + 0x444)) {
  case 0:
    fVar3 = 0.0f;
    break;
  case 1:
    fVar3 = fVar3 * (0.01f * DAT_003ea50c[0]);
    break;
  case 2:
    fVar3 = fVar3 * (0.01f * DAT_003ea508);
    break;
  case 3:
    break;
  case 4:
    break;
  default:
    HST_ASSERT(0, DAT_0037a8b8, 6693);
  }
  return fVar3;
}
