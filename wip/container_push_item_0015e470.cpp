/* HSTMATCH module=EBOOT.BIN start=0x0015e470 end=0x0015e558 symbol=FUN_0015e470 lang=c++ */
/* Near-miss for container push_item returning iterator by value (58 words).
   If item is non-null: sets item->parent = self, checks item, sets item->flag = 0 if check returns true,
   then pushes to self->data vector (inlining size < cap check or calling FUN_00160298 vector grow),
   and returns --self->end(). Otherwise returns self->end().
   Differs only in stack slot allocation (20(sp) vs 28(sp)) and return store scheduling.
*/

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

extern "C" Iter FUN_0015e470(Container *self, Item *item)
{
    if (item != 0) {
        item->parent = self;
        if (item->check()) {
            item->flag = 0;
        }
        unsigned sz = self->size;
        if (sz < self->cap) {
            self->size++;
            self->data[self->size - 1] = item;
        } else {
            FUN_00160298(&self->data, &item, EmptyTag());
        }
        Iter it = self->end();
        it.ptr--;
        return it;
    }
    return self->end();
}
// near miss from lane u2r1-3 (unreviewed)
