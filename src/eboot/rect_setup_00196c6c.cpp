/* HSTMATCH module=EBOOT.BIN start=0x00196c6c end=0x00196ef4 symbol=FUN_00196c6c lang=c++ */
/* Hand-written reconstruction from the disassembly; readability pass (names, shared page types); exact match verified; names and types await human review. */
#include "hst/rect_page.h"

struct Quad { int v[4]; };
extern const Quad DAT_002e17d0;
extern "C" void FUN_000ffb3c(void *, int);

inline void SetupRect(RectElem *elem, const RectEntry *entry) {
    elem->x = (short)entry->x;
    elem->y = (short)(entry->y - 3);
    elem->x2 = elem->x + (int)(entry->w * 20.0f);
    elem->y2 = elem->y + (int)(entry->h * 20.0f);
}

/* Address arithmetic kept as retail has it: element slot n of the wide array is at (n + 18) * 4 + 4 from the
   page, and its value is 0x7c further on (RectPage::wide and RectPage::vals). */
extern "C" void FUN_00196c6c(RectPage *page, int *small_count, int *wide_count, int offset, const RectEntry *entry) {
    if (*small_count < RECT_PAGE_SMALL) {
        int off = *small_count * 4;
        RectElem *elem = *(RectElem **)((char *)off + (int)page + 4);
        FUN_000ffb3c(elem, 0);
        SetupRect(elem, entry);
        (*small_count)++;
    }

    if (offset == 10) {
        Quad local = DAT_002e17d0;
        int i = 0;
        int *delta = local.v;
        do {
            if (*wide_count < RECT_PAGE_WIDE) {
                char *slot = (char *)page + (*wide_count + 18) * 4;
                RectElem *elem = *(RectElem **)(slot + 4);
                FUN_000ffb3c(elem, 0);
                int val = *(int *)(slot + 0x7c) + *delta;
                elem->unk24 = val;
                elem->unk28 = val;
                SetupRect(elem, entry);
                (*wide_count)++;
            }
            i++;
            delta++;
        } while (i < 4);
    } else if (offset != 9 && *wide_count < RECT_PAGE_WIDE) {
        int off = (*wide_count + 18) * 4;
        RectElem *elem = *(RectElem **)((char *)off + (int)page + 4);
        FUN_000ffb3c(elem, 0);
        int val = *(int *)(off + (int)page + 124);
        val = val + offset;
        elem->unk24 = val;
        elem->unk28 = val;
        SetupRect(elem, entry);
        (*wide_count)++;
    }
}
