/* HSTMATCH module=EBOOT.BIN start=0x000574c4 end=0x000575fc symbol=FUN_000574c4 lang=c++ */
/* Clone of src/sharing_main/set_holder_item_00058118.cpp (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Sub_000574c4 {
    int f0;
};

struct Item_000574c4 {
    Sub_000574c4 *sub;
};

struct Tag_000574c4 {};

struct Vector_000574c4 {
    Item_000574c4 **data;
    unsigned size;
    unsigned cap;

    unsigned capacity() const { return cap; }
};

extern "C" void FUN_00057648(void *, unsigned);
extern "C" void FUN_000561d4(Item_000574c4 *, int);
extern "C" void FUN_000562d8(Item_000574c4 *, int, unsigned);
extern "C" void FUN_000595f8(Vector_000574c4 *, unsigned);
extern "C" void FUN_00059544(Vector_000574c4 *, unsigned, Item_000574c4 **, Tag_000574c4);

struct Holder_000574c4 {
    char pad_00[0x8c];
    int f8c;
    char pad_90[0x50];
    Vector_000574c4 vec;
};

extern "C" void FUN_000574c4(Holder_000574c4 *self, unsigned idx, Item_000574c4 *item, unsigned param_4)
{
    FUN_00057648(self, idx);
    if (item != 0) {
        if (item->sub == 0 || item->sub->f0 == 0) {
            if (item != 0) {
                FUN_000561d4(item, 1);
                item = 0;
            }
        }
    }
    if (item != 0) {
        FUN_000562d8(item, self->f8c, param_4);
    }
    if (self->vec.capacity() > idx) {
    } else {
        unsigned new_cap = (idx + 16) & -16;
        if (self->vec.cap < new_cap) {
            FUN_000595f8(&self->vec, new_cap);
        }
    }
    if (self->vec.size > idx) {
    } else {
        Item_000574c4 *val = 0;
        unsigned new_size = idx + 1;
        if (new_size > self->vec.size) {
            FUN_00059544(&self->vec, new_size - self->vec.size, &val, Tag_000574c4());
        } else if (new_size < self->vec.size) {
            unsigned diff = self->vec.size - new_size;
            self->vec.size -= diff;
        }
    }
    self->vec.data[idx] = item;
}
