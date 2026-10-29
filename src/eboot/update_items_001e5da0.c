/* HSTMATCH module=EBOOT.BIN start=0x001e5da0 end=0x001e5df0 symbol=FUN_001e5da0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order; readability pass; exact match verified; names and types await human review. */
#include "hst/result_widgets.h"

extern void FUN_00102c54(ResultWidget *);

/* Set every widget's field 0x60 to 350.0f and notify it. */
void FUN_001e5da0(ResultWidgetTable *table)
{
    int i;
    for (i = 0; i < RESULT_WIDGET_COUNT; i++) {
        ResultWidget *widget = table->widget[i];
        widget->unk60 = 350.0f;
        FUN_00102c54(table->widget[i]);
    }
}
