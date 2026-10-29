/* HSTMATCH module=hstp_trans_main.prx start=0x002910e4 end=0x00291130 symbol=FUN_002910e4 lang=c99 */
/* Clone of src/eboot/FUN_0027fc70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/color_pulse.h"

extern u8 DAT_002db018;

/* Sets the top byte of the colour from the pulse table at the phase, then advances the phase by the low byte of step. */
void FUN_002910e4(u32 *phase,u32 *color,u32 step)
{
  *color = *color & 0xffffff | (u32)(u8)(&DAT_002db018)[*phase % PULSE_TABLE_LEN] << 0x18;
  *phase = *phase + (step & 0xff);
}
