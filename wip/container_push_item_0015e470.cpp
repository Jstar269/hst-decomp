/* HSTMATCH module=EBOOT.BIN start=0x0015e470 end=0x0015e558 symbol=FUN_0015e470 lang=c++ */
/* Near miss: 10 of 58 words differ. The 48-byte frame and vector insertion are close; see trailing notes. */

struct Container;

struct Item {
    virtual ~Item();
    virtual void dummy1();
    virtual void dummy2();
    virtual int check();
    void *parent;   /* +4 */
    char pad_8[8];  /* +8 */
    char flag;      /* +0x10 */
};

struct EmptyTag {};

extern "C" void FUN_00160298(void *vec, Item **item, EmptyTag tag);

struct Iter {
    Item **ptr;
};

struct Container {
    char pad[20];
    Item **data;   /* +20 */
    unsigned size; /* +24 */
    unsigned cap;  /* +28 */

    Iter end() const {
        Iter it;
        it.ptr = data + size;
        return it;
    }
};

extern "C" void FUN_0015e470(Iter *result, Container *self, Item *item)
{
    Item *local_1c[7];
    local_1c[0] = item;
    if (item != 0) {
        local_1c[0]->parent = self;
        if (local_1c[0]->check()) {
            local_1c[0]->flag = 0;
        }
        if (self->size < self->cap) {
            self->size++;
            unsigned index = self->size - 1;
            self->data[index] = local_1c[0];
        } else {
            FUN_00160298(&self->data, local_1c, EmptyTag());
        }
        Iter *end = (Iter *)&local_1c[4];
        Iter *ret = (Iter *)&local_1c[2];
        end->ptr = self->data + self->size;
        *ret = *end;
        ret->ptr--;
        result->ptr = ret->ptr;
        local_1c[6] = (Item *)ret->ptr;
        return;
    }
    result->ptr = self->data + self->size;
}
// The remaining differences are the item spill at sp+36 instead of sp+20, the capacity-branch target,
// and iterator return temporary slots (ours sp+24/32, retail sp+36/28/44). Keeping a three-pointer local
// array preserves the 48-byte frame and by-value return schedule. An explicit hidden-result ABI plus a
// seven-pointer local array moves the item spill to sp+20 but loses the return-temporary sequence.
// Tried: old-size vs increment-then-index forms, explicit index and saved pointer locals, vector push_back
// helper, Iterator constructor/copy/pre-decrement/operator-minus forms, explicit-result locals and an
// explicit sret signature with the local array. Best count is 10/58.
// improved by lane lnm1 (unreviewed): 35 -> 5 differing words
