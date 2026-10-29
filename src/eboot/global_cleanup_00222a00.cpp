/* HSTMATCH module=EBOOT.BIN start=0x00222a00 end=0x00222b40 symbol=FUN_00222a00 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed deleting virtual calls and retained the duplicated global-pointer check with its zero-store arm; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/prize_display.h"

struct Destroyable {
  virtual void destroy(int);
};

/* Head of a global table: its first word owns an object. */
struct OwnerTable {
  Destroyable *owned;
};

extern u8 DAT_00309664;
extern u32 DAT_0034a264;
extern OwnerTable * DAT_0034a268;
extern OwnerTable * DAT_0034a26c;
extern "C" void FUN_00000a00(void *);
extern "C" PrizeDisplay * FUN_00102ea4(PrizeDisplay *,int);

/* Destructor: free the info widget and both global tables, run the base destructor, and delete the object when flag > 0. */
extern "C" PrizeDisplay * FUN_00222a00(PrizeDisplay *self,short flag)
{
  OwnerTable *table;
  Destroyable *owned;
  
  if (self != (PrizeDisplay *)0x0) {
    self->vptr = &DAT_00309664;
    DAT_0034a264 = 0;
    if (self->info_widget != 0) {
      if (self->info_widget != 0) {
        ((Destroyable *)self->info_widget)->destroy(1);
      }
      self->info_widget = 0;
    }
    table = DAT_0034a268;
    if (DAT_0034a268 != (OwnerTable *)0x0) {
      if (DAT_0034a268 != (OwnerTable *)0x0) {
        owned = DAT_0034a268->owned;
        if (owned != (Destroyable *)0x0) {
          if (owned != (Destroyable *)0x0) {
            owned->destroy(1);
            table->owned = 0;
          }
          else
            table->owned = 0;
        }
        FUN_00000a00(table);
      }
      DAT_0034a268 = (OwnerTable *)0x0;
    }
    table = DAT_0034a26c;
    if (DAT_0034a26c != (OwnerTable *)0x0) {
      if (DAT_0034a26c != (OwnerTable *)0x0) {
        owned = DAT_0034a26c->owned;
        if (owned != (Destroyable *)0x0) {
          if (owned != (Destroyable *)0x0) {
            owned->destroy(1);
            table->owned = 0;
          }
          else
            table->owned = 0;
        }
        FUN_00000a00(table);
      }
      DAT_0034a26c = (OwnerTable *)0x0;
    }
    FUN_00102ea4(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
