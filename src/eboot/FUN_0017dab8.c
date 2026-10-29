/* HSTMATCH module=EBOOT.BIN start=0x0017dab8 end=0x0017db50 symbol=FUN_0017dab8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a, variant v0) corrected by hand: if/else order inverted and the float product regrouped to the retail evaluation order; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_mgr.h"

extern int FUN_0016bc7c();
extern int FUN_00204400();

/* Value of slot `slot` scaled by the settings, and by a per-id factor when the slot's model id is in range. */
float FUN_0017dab8(SlotMgr *self,int slot)
{
  SlotObj *obj;
  float *id_scale;
  float *settings;
  int id;
  float result;
  
  obj = self->entries[slot]->obj;
  id = 0;
  if (obj != 0) {
    id = obj->id;
  }
  if ((id >= 0) && (id <= 0xe)) {
    id_scale = (float *)FUN_00204400();
    settings = (float *)FUN_0016bc7c();
    result = *id_scale * (self->value * *settings);
  }
  else {
    settings = (float *)FUN_0016bc7c();
    result = self->value * *settings;
  }
  return result;
}
