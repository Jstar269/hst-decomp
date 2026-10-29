/* HSTMATCH module=hstp_trans_main.prx start=0x000df92c end=0x000df95c symbol=FUN_000df92c lang=c99 */
/* Clone of src/eboot/FUN_000db90c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

/* Returns 1 when the checked rule field is zero for both passes of the loop. */
u32 FUN_000df92c(RuleObj *self)
{
  int i;

  i = 0;
  do {
    if (self->unk8c != 0) {
      return 0;
    }
    i = i + 1;
  } while (i < 2);
  return 1;
}
