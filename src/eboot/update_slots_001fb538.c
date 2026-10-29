/* HSTMATCH module=EBOOT.BIN start=0x001fb538 end=0x001fb7cc symbol=FUN_001fb538 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Started from hstgen.py tag v0. Matching idioms: the two four-slot loops are static inline helpers called once per branch of the cur_rec test; the record pointer is computed before the unk12c4 store; the table pointer is read into a local before the mode range test; the global in the second helper is declared before the loop index. */
#include "hst/slot_panel.h"

typedef struct Game { char pad[0xa8]; void *unka8; } Game;
/* Per-mode table; entries 1..9 are read. */
typedef struct Tab { char pad[0x2c]; float level[10]; } Tab;

enum { MODE_COUNT = 10 };

extern Game *DAT_003386b0;
extern Tab *DAT_0034a77c;
extern char DAT_0034179c;

extern int FUN_001b2af0(void *, int);
extern void FUN_001b5764(void *, int, int);
extern void FUN_001e4d64(float, void *, int);
extern void FUN_001e51a4(void *);
extern void FUN_001f37e4(SlotPanel *, PanelSlot *, int, int, int, int);
extern void FUN_001fb8a0(PanelRec *);
extern int FUN_001fb8b0(PanelRec *);


/* Calls FUN_001f37e4 for each live slot (all of them when filter is null, else only the matching one). */
static inline void LoopA(SlotPanel *panel, PanelSlot *filter)
{
  int i;
  for (i = 0; i < PANEL_SLOT_COUNT; i++) {
    if (filter == 0 || filter == panel->slots[i]) {
      PanelSlot *slot = panel->slots[i];
      int live = slot ? slot->unk58 : 0;
      if (live != 0) {
        FUN_001f37e4(panel, slot, panel->ids[i], i, 7, 0);
      }
    }
  }
}

/* Same selection as LoopA, but notifies the global game object's handle (if any) with code 0x81. */
static inline void LoopB(SlotPanel *panel, PanelSlot *filter)
{
  void *game_obj = DAT_003386b0->unka8;
  int i;
  for (i = 0; i < PANEL_SLOT_COUNT; i++) {
    if (filter == 0 || filter == panel->slots[i]) {
      PanelSlot *slot = panel->slots[i];
      int live = slot ? slot->unk58 : 0;
      if (live != 0 && game_obj != 0) {
        FUN_001b5764(game_obj, i, 0x81);
      }
    }
  }
}

/* Starts record update for the current record with the given mode: bumps the record counter, refreshes the
   slots, then passes the per-mode level (0 outside 1..9) to FUN_001e4d64. */
void FUN_001fb538(SlotPanel *panel, int mode)
{
  PanelRec *rec;
  int result;
  float level;
  Tab *tab;
  rec = &panel->recs[panel->cur_rec];
  panel->unk12c4 = 2;
  panel->unk12cc = 0;
  rec->mode = mode;
  result = FUN_001fb8b0(rec);
  FUN_001fb8a0(rec);
  if (panel->cur_rec == 0) {
    LoopA(panel, panel->p3c4);
    LoopB(panel, panel->p3c4);
  } else {
    LoopA(panel, panel->p3c8);
    LoopB(panel, panel->p3c8);
  }
  panel->unk5b8 = FUN_001b2af0(&DAT_0034179c, 16);
  tab = DAT_0034a77c;
  if (mode > 0 && mode < MODE_COUNT) {
    level = tab->level[mode];
  } else {
    level = 0.0f;
  }
  FUN_001e4d64(level, panel->unk510, result);
  FUN_001e51a4(panel->unk510);
}
