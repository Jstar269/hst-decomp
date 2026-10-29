/* HSTMATCH module=hstp_trans_main.prx start=0x00157eec end=0x00157f0c symbol=FUN_00157eec lang=c99 */
/* Clone of src/eboot/FUN_0014c3d8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/var_holder.h"

extern u32 * FUN_00239f98();

/* Read the integer variable of the object. */
u32 FUN_00157eec(void *unused,VarHolder *holder)
{
  u32 *slot;
  
  slot = FUN_00239f98(holder->vars);
  return *slot;
}
