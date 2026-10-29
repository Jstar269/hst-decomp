/* HSTMATCH module=EBOOT.BIN start=0x001e5df0 end=0x001e5e3c symbol=FUN_001e5df0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained a separate advanced cursor for the indexed calls, kept as the helper argument; readability pass; exact match verified; names and types await human review. */
#include "hst/result_widgets.h"

extern void FUN_00102c54();

/* Clear field 0x60 of every widget and notify it. */
void FUN_001e5df0(ResultWidgetTable *table)
{
  int i;
  ResultWidgetTable *cursor;

  i = 0;
  cursor = table;
  do {
    cursor->widget[0]->unk60 = 0;
    FUN_00102c54(cursor->widget[0]);
    i = i + 1;
    cursor = (ResultWidgetTable *)((char *)cursor + 4);
  } while (i < RESULT_WIDGET_COUNT);
}
