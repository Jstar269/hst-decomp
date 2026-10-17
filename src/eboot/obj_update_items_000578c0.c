/* HSTMATCH module=EBOOT.BIN start=0x000578c0 end=0x00057934 symbol=FUN_000578c0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#pragma opt_strength_reduction off

struct Item {
    char pad[9];
    unsigned char flag;
};

struct Obj {
    char pad[140];
    int f8c;
    char pad2[80];
    struct Item **items;
    unsigned int count;
};

extern void FUN_000562d8(struct Item *, int, unsigned char);
extern void FUN_0005708c(struct Obj *);

void FUN_000578c0(struct Obj *self)
{
    struct Obj *s = self;
    unsigned int i = 0;
    if (s->count != 0) {
        do {
            struct Item *item = s->items[i];
            if (item != 0) {
                FUN_000562d8(item, s->f8c, item->flag);
            }
            i++;
        } while (i < s->count);
    }
    FUN_0005708c(s);
}
