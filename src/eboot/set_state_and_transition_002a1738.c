/* HSTMATCH module=EBOOT.BIN start=0x002a1738 end=0x002a17e0 symbol=FUN_002a1738 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: corrected callee prototype argument orders for float parameters; readability pass; exact match verified; names and types await human review. */
#include "hst/anim_host.h"

extern void FUN_00057bc0(void *self, float f1, int a, int b, float f2, float f3);
extern void FUN_00057b58(void *self, int a, int b, float f);
extern void FUN_002a1398(void *self, int a, int b);
extern void FUN_00058ddc(void *self, int a, int b);
extern void FUN_00058ec4(float f, void *self, int a);
extern void FUN_00059084(void *self, int a);

/* Sets the host's animation state and starts it on channel 1. */
void FUN_002a1738(AnimHost *host, int state)
{
  host->state = state;
  if (state == HOST_STATE_SPECIAL) {
    FUN_00057bc0(host, 0.0f, 1, -1, 0.0f, 0.0f);
    FUN_00057b58(host, 1, state, 0.0f);
  } else {
    FUN_002a1398(host, 1, state);
  }
  FUN_00058ddc(host, 1, 1);
  FUN_00058ec4(1.0f, host, 1);
  FUN_00059084(host, 1);
}
