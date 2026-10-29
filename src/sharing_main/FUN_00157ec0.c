/* HSTMATCH module=hstp_trans_main.prx start=0x00157ec0 end=0x00157eec symbol=FUN_00157ec0 lang=c99 */
/* Clone of src/eboot/FUN_0014c3ac.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/var_holder.h"

extern u32 * FUN_00239f98();

/* Store a value into the integer variable of the object. */
void FUN_00157ec0(void *unused,VarHolder *holder,u32 value)
{
  u32 *slot;
  
  slot = FUN_00239f98(holder->vars);
  *slot = value;
}
