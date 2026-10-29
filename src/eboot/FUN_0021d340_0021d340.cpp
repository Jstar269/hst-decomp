/* HSTMATCH module=EBOOT.BIN start=0x0021d340 end=0x0021d3c0 symbol=FUN_0021d340 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5/v17) corrected by hand: declared the loop index before the cursor and materialized the lookup offset before adding the base; readability pass; exact match verified; names and types await human review. */
#include "hst/parts_pane.h"

/* Virtual view of a PartsLayer: slot 1 takes an int (called with 1 for every layer, then 0 for the selected one). */
struct LayerV { virtual void d0(); virtual void Show(int on); };

/* Selects layer `selected`: all layers get Show(1), then the selected one Show(0). */
extern "C" void FUN_0021d340(PartsPane *self, int selected)
{
  LayerV *layer;
  int i;
  char *cursor; /* walks the pane in steps of one array slot; the layers start 0x70 bytes in */
  int offset;

  self->selected = selected;
  i = 0;
  cursor = (char *)self;
  do {
    ((LayerV *)(*(PartsLayer **)(cursor + 0x70)))->Show(1);
    i = i + 1;
    cursor = cursor + 4;
  } while (i < PARTS_LAYER_COUNT);
  offset = self->selected * 4;
  layer = *(LayerV **)((char *)self->layer + offset);
  layer->Show(0);
}
