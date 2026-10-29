/* HSTMATCH module=EBOOT.BIN start=0x00224738 end=0x00224830 symbol=FUN_00224738 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/page_menu.h"

extern void FUN_000ffb3c(void *, int);
extern void FUN_00110a78(void *, void *, int);
extern void *FUN_001fea10(int, int, int);

/* Highlight entry `selected`: each entry's four child nodes get flags (0, 1, 0, 1) for the chosen entry and the
   opposite pattern (1, 0, 1, 0) for the others; then refresh the optional helper object. */
void FUN_00224738(PageMenu *menu, int selected)
{
    int target = selected;
    int i = 0;

    if (menu->count > 0) {
        PageMenu *e = menu; /* advances 16 bytes (four child nodes) per entry */
        do {
            if (i == target) {
                FUN_000ffb3c(e->node[1], 0);
                FUN_000ffb3c(e->node[2], 1);
                FUN_000ffb3c(e->node[3], 0);
                FUN_000ffb3c(e->node[4], 1);
            } else {
                FUN_000ffb3c(e->node[1], 1);
                FUN_000ffb3c(e->node[2], 0);
                FUN_000ffb3c(e->node[3], 1);
                FUN_000ffb3c(e->node[4], 0);
            }
            i++;
            e = (PageMenu *)((char *)e + 4 * sizeof(UiNode *));
        } while (i < menu->count);
    }

    if (menu->hook != 0) {
        void *res = FUN_001fea10(18, 32, menu->cursor);
        FUN_00110a78(menu->hook, res, 0);
    }
}
