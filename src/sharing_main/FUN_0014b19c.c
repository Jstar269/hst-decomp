/* HSTMATCH module=hstp_trans_main.prx start=0x0014b19c end=0x0014b1a4 symbol=FUN_0014b19c lang=c99 */
/* Clone of src/eboot/FUN_0013fb50.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

#define THIS_ADJUST 0x40 /* distance from this sub-object to the start of the full object */

extern u32 * FUN_0013da04(u32 *param_1,short param_2);

/* Thunk: moves the pointer back to the full object and forwards to its deleting destructor. */
void FUN_0014b19c(char *self,short delete_flag)
{
  FUN_0013da04((u32 *)(self - THIS_ADJUST),delete_flag);
}
