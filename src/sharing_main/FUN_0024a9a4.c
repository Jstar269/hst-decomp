/* HSTMATCH module=hstp_trans_main.prx start=0x0024a9a4 end=0x0024a9c8 symbol=FUN_0024a9a4 lang=c99 */
/* Clone of src/eboot/FUN_0023a80c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/hist_obj.h"

/* Global record with a divisor at 0x18b8. */
typedef struct Timing {
  char pad00[0x18b8];
  int unk18b8;  /* 0x18b8 */
} Timing;

extern Timing * DAT_003f39ec;

/* True when the counter divided by the global divisor is odd. */
bool FUN_0024a9a4(HistObj *self)
{
  return (self->unk1850 / DAT_003f39ec->unk18b8 & 1U) != 0;
}
