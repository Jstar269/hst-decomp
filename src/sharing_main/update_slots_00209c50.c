/* HSTMATCH module=hstp_trans_main.prx start=0x00209c50 end=0x00209ee4 symbol=FUN_00209c50 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/update_slots_001fb538.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Started from hstgen.py tag v0. Matching idioms: the two four-slot loops are static inline helpers called once per branch of the cur_rec test; the record pointer is computed before the unk12c4 store; the table pointer is read into a local before the mode range test; the global in the second helper is declared before the loop index. */
#include "hst/slot_panel.h"

typedef struct Game { char pad[0xa8]; void *unka8; } Game;
/* Per-mode table; entries 1..9 are read. */
typedef struct Tab { char pad[0x2c]; float level[10]; } Tab;

enum { MODE_COUNT = 10 };

extern Game *DAT_003e19f0;
extern Tab *DAT_003f3aac;
extern char DAT_003eaad8;

extern int FUN_001c0bb0(void *, int);
extern void FUN_001c3418(void *, int, int);
extern void FUN_001f2f7c(float, void *, int);
extern void FUN_001f33bc(void *);
extern void FUN_00201ca4(SlotPanel *, PanelSlot *, int, int, int, int);
extern void FUN_00209fb8(PanelRec *);
extern int FUN_00209fc8(PanelRec *);


/* Calls FUN_00201ca4 for each live slot (all of them when filter is null, else only the matching one). */
static inline void LoopA(SlotPanel *panel, PanelSlot *filter)
{
  int i;
  for (i = 0; i < PANEL_SLOT_COUNT; i++) {
    if (filter == 0 || filter == panel->slots[i]) {
      PanelSlot *slot = panel->slots[i];
      int live = slot ? slot->unk58 : 0;
      if (live != 0) {
        FUN_00201ca4(panel, slot, panel->ids[i], i, 7, 0);
      }
    }
  }
}

/* Same selection as LoopA, but notifies the global game object's handle (if any) with code 0x81. */
static inline void LoopB(SlotPanel *panel, PanelSlot *filter)
{
  void *game_obj = DAT_003e19f0->unka8;
  int i;
  for (i = 0; i < PANEL_SLOT_COUNT; i++) {
    if (filter == 0 || filter == panel->slots[i]) {
      PanelSlot *slot = panel->slots[i];
      int live = slot ? slot->unk58 : 0;
      if (live != 0 && game_obj != 0) {
        FUN_001c3418(game_obj, i, 0x81);
      }
    }
  }
}

/* Starts record update for the current record with the given mode: bumps the record counter, refreshes the
   slots, then passes the per-mode level (0 outside 1..9) to FUN_001f2f7c. */
void FUN_00209c50(SlotPanel *panel, int mode)
{
  PanelRec *rec;
  int result;
  float level;
  Tab *tab;
  rec = &panel->recs[panel->cur_rec];
  panel->unk12c4 = 2;
  panel->unk12cc = 0;
  rec->mode = mode;
  result = FUN_00209fc8(rec);
  FUN_00209fb8(rec);
  if (panel->cur_rec == 0) {
    LoopA(panel, panel->p3c4);
    LoopB(panel, panel->p3c4);
  } else {
    LoopA(panel, panel->p3c8);
    LoopB(panel, panel->p3c8);
  }
  panel->unk5b8 = FUN_001c0bb0(&DAT_003eaad8, 16);
  tab = DAT_003f3aac;
  if (mode > 0 && mode < MODE_COUNT) {
    level = tab->level[mode];
  } else {
    level = 0.0f;
  }
  FUN_001f2f7c(level, panel->unk510, result);
  FUN_001f33bc(panel->unk510);
}
