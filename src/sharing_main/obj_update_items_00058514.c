/* HSTMATCH module=hstp_trans_main.prx start=0x00058514 end=0x00058588 symbol=FUN_00058514 lang=c99 */
/* Clone of src/eboot/obj_update_items_000578c0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00056eec(struct Item *, int, unsigned char);
extern void FUN_00057ce0(struct Obj *);

void FUN_00058514(struct Obj *self)
{
    struct Obj *s = self;
    unsigned int i = 0;
    if (s->count != 0) {
        do {
            struct Item *item = s->items[i];
            if (item != 0) {
                FUN_00056eec(item, s->f8c, item->flag);
            }
            i++;
        } while (i < s->count);
    }
    FUN_00057ce0(s);
}
