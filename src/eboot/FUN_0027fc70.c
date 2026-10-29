/* HSTMATCH module=EBOOT.BIN start=0x0027fc70 end=0x0027fcbc symbol=FUN_0027fc70 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/color_pulse.h"

extern u8 DAT_002caa58;

/* Sets the top byte of the colour from the pulse table at the phase, then advances the phase by the low byte of step. */
void FUN_0027fc70(u32 *phase,u32 *color,u32 step)
{
  *color = *color & 0xffffff | (u32)(u8)(&DAT_002caa58)[*phase % PULSE_TABLE_LEN] << 0x18;
  *phase = *phase + (step & 0xff);
}
