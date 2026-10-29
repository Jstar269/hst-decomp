/* HSTMATCH module=EBOOT.BIN start=0x000d4288 end=0x000d42fc symbol=FUN_000d4288 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the trailing `items_size = 0` is an inline `int n = items_size; shrink(n, Alloc())` (unfolded lw/subu/sw, 16-byte allocator-temporary frame slot) and the 0 argument of FUN_000d5798 is an empty tag temporary; same recipe as ctor_clear_vec_000d3204; readability pass; exact match verified; names and types await human review. */
struct Alloc {};
struct Tag {};
/* Owner of two vectors: pointers at 0x3c (data, size, capacity) and records at 0x48. */
struct Self_000d4288 {
    int vptr;
    char pad4[0x38];
    int items_data, items_size, items_cap, recs_data, recs_size, recs_cap;
    void shrink(int n, Alloc) { items_size -= n; }
};
extern "C" {
extern char DAT_00307468;
extern void FUN_0001f06c(void *);
extern void FUN_000d4430(void *);
extern void FUN_000d5798(void *, int, Tag);
}

extern "C" Self_000d4288 *FUN_000d4288(Self_000d4288 *self)
{
    FUN_0001f06c(self);
    self->vptr = (int)&DAT_00307468;
    self->items_data = 0;
    self->items_size = 0;
    self->items_cap = 0;
    self->recs_data = 0;
    self->recs_size = 0;
    self->recs_cap = 0;
    int n = self->items_size;
    self->shrink(n, Alloc());
    FUN_000d5798(&self->recs_data, self->recs_size, Tag());
    FUN_000d4430(self);
    return self;
}
