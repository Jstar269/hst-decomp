/* HSTMATCH module=hstp_trans_main.prx start=0x0017bd04 end=0x0017be40 symbol=FUN_0017bd04 lang=c99 */
/* Clone of src/eboot/release_idle_entry_0016fab8.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (starting from the sn6 near miss in wip/release_idle_entry_0017bd04.c); exact match verified; names and types await human review. */
/* Matching idioms: `volatile unsigned count` (bound reloaded every pass); `volatile int id` (the id is read again for the call argument instead of reusing the compare's load);
   `#pragma opt_strength_reduction off` (index recomputed per pass); the compare walks a local copy of the item table taken after the emptiness test, while the returned entry is
   read through the identical struct Mgr2 so it is not shared with the compare's load (retail reloads the table in the match path). */
#pragma opt_strength_reduction off
typedef struct Entry {
  volatile int id;
  int pad4;
  unsigned char f8;
  unsigned char f9;
  unsigned char f10;
  unsigned char f11;
  unsigned char f12;
} Entry;
typedef struct Mgr {
  char pad[0x520];
  Entry **items;
  volatile unsigned count;
} Mgr;
typedef struct Mgr2 {
  char pad[0x520];
  Entry **items;
  volatile unsigned count;
} Mgr2;
extern int FUN_00177328(void);
extern void FUN_0017788c(int);

static inline Entry *FindById(Mgr *m, int id)
{
  unsigned i = 0;
  if (m->count != 0) {
    Entry **items = m->items;
    do {
      if (items[i]->id == id) {
        return ((Mgr2 *)m)->items[i];
      }
      i++;
    } while (i < m->count);
  }
  return 0;
}

void FUN_0017bd04(Mgr *m, int target)
{
  Entry *found = FindById(m, FUN_00177328());
  if (found == 0) {
    return;
  }
  if (target != FUN_00177328()) {
    if (found->f11 == 0 && found->f12 == 0) {
      return;
    }
  }
  {
    unsigned i;
    for (i = 0; i < m->count; i++) {
      Entry *e = m->items[i];
      if (e->id != target) {
        if (e->f8 == 0 && e->f9 == 0 && e->f10 == 0 && e->f11 == 0 && e->f12 == 0) {
          FUN_0017788c(e->id);
          return;
        }
      }
    }
  }
}
