/* HSTMATCH module=EBOOT.BIN start=0x001b9470 end=0x001b94f8 symbol=FUN_001b9470 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Item {
    short key;
};

void FUN_001b9470(struct Item **first, struct Item **last)
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
