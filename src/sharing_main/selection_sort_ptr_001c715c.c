/* HSTMATCH module=hstp_trans_main.prx start=0x001c715c end=0x001c71e4 symbol=FUN_001c715c lang=c99 */
/* Clone of src/eboot/selection_sort_ptr_001b9470.c (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Item {
    short key;
};

void FUN_001c715c(struct Item **first, struct Item **last)
{
    if (first == last)
        return;

    struct Item **end = last - 1;
    if (first >= end)
        return;

    struct Item **p;
    struct Item **max;
    do {
        max = first;
        if (first != last && (p = first + 1) != last) {
            do {
                if ((*p)->key > (*max)->key)
                    max = p;
                p++;
            } while (p != last);
        }
        if (max != first) {
            struct Item *t = *max;
            *max = *first;
            *first = t;
        }
    } while (++first < end);
}
