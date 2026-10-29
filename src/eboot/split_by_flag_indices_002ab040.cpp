/* HSTMATCH module=EBOOT.BIN start=0x002ab040 end=0x002ab180 symbol=FUN_002ab040 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: register loop counter k kept beside the address-taken push value idx (k = idx + 1; idx = k) so the counter lives in s2; clear loop via int n = size; shrink(n, Alloc()); names and types await human review. */
#include "hst/vshistory.h"

struct Tag {};
struct Alloc {};
struct IntVec;
extern "C" void FUN_00054510(IntVec *, const int *, Tag);
struct IntVec {
    int *data;
    unsigned size;
    unsigned cap;
    void push_back(const int &x, Tag) {
        if (size < cap) {
            size++;
            data[size - 1] = x;
        } else {
            FUN_00054510(this, &x, Tag());
        }
    }
    void shrink(int n, Alloc) { size -= n; }
};
struct Item {
    char pad[0xd8];
    unsigned char flag; /* 0xd8 */
};
struct FlagLists {
    char pad[0x30ec];
    IntVec by_flag[2]; /* 0x30ec indices of items with the flag set / clear */
};
extern char *DAT_003415a8;
extern "C" {
int FUN_002af31c(char *);
Item *FUN_002af32c(char *, int);
}

/* Clear both index lists, then sort every item index into the list for its flag. */
extern "C" void FUN_002ab040(FlagLists *self)
{
    int i = 0;
    do {
        int n = self->by_flag[i].size;
        self->by_flag[i].shrink(n, Alloc());
        i++;
    } while (i < 2);
    char *list = DAT_003415a8 + HISTORY_LIST_OFFSET;
    int idx = 0;
    int k = 0;
    if (FUN_002af31c(list) > 0) {
        do {
            Item *item = FUN_002af32c(list, k);
            if (item->flag != 0) {
                self->by_flag[0].push_back(idx, Tag());
            } else {
                self->by_flag[1].push_back(idx, Tag());
            }
            k = idx + 1;
            idx = k;
        } while (k < FUN_002af31c(list));
    }
}
