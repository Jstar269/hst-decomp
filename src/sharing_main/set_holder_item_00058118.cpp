/* HSTMATCH module=hstp_trans_main.prx start=0x00058118 end=0x00058250 symbol=FUN_00058118 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Sub_00058118 {
    int f0;
};

struct Item_00058118 {
    Sub_00058118 *sub;
};

struct Tag_00058118 {};

struct Vector_00058118 {
    Item_00058118 **data;
    unsigned size;
    unsigned cap;

    unsigned capacity() const { return cap; }
};

extern "C" void FUN_0005829c(void *, unsigned);
extern "C" void FUN_00056de8(Item_00058118 *, int);
extern "C" void FUN_00056eec(Item_00058118 *, int, unsigned);
extern "C" void FUN_0005a2dc(Vector_00058118 *, unsigned);
extern "C" void FUN_0005a228(Vector_00058118 *, unsigned, Item_00058118 **, Tag_00058118);

struct Holder_00058118 {
    char pad_00[0x8c];
    int f8c;
    char pad_90[0x50];
    Vector_00058118 vec;
};

extern "C" void FUN_00058118(Holder_00058118 *self, unsigned idx, Item_00058118 *item, unsigned param_4)
{
    FUN_0005829c(self, idx);
    if (item != 0) {
        if (item->sub == 0 || item->sub->f0 == 0) {
            if (item != 0) {
                FUN_00056de8(item, 1);
                item = 0;
            }
        }
    }
    if (item != 0) {
        FUN_00056eec(item, self->f8c, param_4);
    }
    if (self->vec.capacity() > idx) {
    } else {
        unsigned new_cap = (idx + 16) & -16;
        if (self->vec.cap < new_cap) {
            FUN_0005a2dc(&self->vec, new_cap);
        }
    }
    if (self->vec.size > idx) {
    } else {
        Item_00058118 *val = 0;
        unsigned new_size = idx + 1;
        if (new_size > self->vec.size) {
            FUN_0005a228(&self->vec, new_size - self->vec.size, &val, Tag_00058118());
        } else if (new_size < self->vec.size) {
            unsigned diff = self->vec.size - new_size;
            self->vec.size -= diff;
        }
    }
    self->vec.data[idx] = item;
}
