/* HSTMATCH module=EBOOT.BIN start=0x001b87e8 end=0x001b8890 symbol=FUN_001b87e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: express the two guarded paths and shared flag store explicitly; readability pass; exact match verified; names and types await human review. */
#include "hst/toggle_obj.h"

extern u8 DAT_0034179c;
extern void FUN_001b4240(int *,float);
extern int FUN_001b4528(int *,int);

/* Switches the object on or off; the shared object is told once per transition (and faded when with_fade). */
void FUN_001b87e8(ToggleObj *self,int on,int with_fade)
{
  int flag;

  if (on == 0) goto zero_case;
  if (self->off == 0) goto zero_case;
  FUN_001b4528((int *)&DAT_0034179c,on);
  goto store_flag;

zero_case:
  if (on != 0) goto store_flag;
  if (self->off != 0) goto store_flag;
  FUN_001b4528((int *)&DAT_0034179c,on);
  if (with_fade == 0) goto store_flag;
  FUN_001b4240((int *)&DAT_0034179c,0.5f);

store_flag:
  flag = on != 0;
  flag ^= 1;
  self->off = (u8)flag;
}
