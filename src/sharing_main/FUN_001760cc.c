/* HSTMATCH module=hstp_trans_main.prx start=0x001760cc end=0x001760e8 symbol=FUN_001760cc lang=c99 */
/* Clone of src/eboot/FUN_00169f08.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vec.h"

extern u32 FUN_0000c6f4(float param_1,float param_2);

/* Heading from one position to another: atan2 of the x and z differences. */
void FUN_001760cc(Float4 *from,Float4 *to)
{
  FUN_0000c6f4(to->x - from->x,to->z - from->z);
}
