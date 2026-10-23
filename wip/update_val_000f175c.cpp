/* HSTMATCH module=EBOOT.BIN start=0x000f175c end=0x000f1820 symbol=FUN_000f175c lang=c++ */

extern "C" float fabsf(float);
extern "C" void FUN_00103480(void *);
extern "C" void FUN_00103128(void *);

struct Sub {
    char pad[120];
    float val;
};

struct Obj {
    char pad0[84];
    struct Sub *sub84;
    struct Sub *sub88;
    char pad1[80];
    int count;
    float val;

    float GetVal() const { return val; }
};

extern "C" void FUN_000f175c(struct Obj *obj) {
    float old_val = obj->GetVal();
    if (obj->count >= 20) {
        float next = 0.0f;
        float diff = next - old_val;
        if (fabsf(diff) >= 0.01f) next = old_val + diff * 0.3f;
        obj->val = next;
    }
    float new_val = obj->val;
    obj->sub84->val = new_val;
    obj->sub88->val = new_val;
    if (old_val > 0.0f || obj->val > 0.0f) {
        FUN_00103480(obj);
    }
    FUN_00103128(obj);
    obj->count++;
}

// NEAR MISS (lane sw1): 2 words differ (was 6). `float next = 0.0f;` declared INSIDE the `if (obj->count >= 20)` block plus the if-form
// `if (fabsf(diff) >= 0.01f) next = old_val + diff * 0.3f;` gives retail's float registers (old_val $f3, next $f4), the `move s0,a0` bnez-slot filler and everything else.
// Left: the inner branch is `bc1tl 0xf17bc` + duplicated `swc1 $f4,176(s0)` in the slot; retail has plain `bc1t 0xf17b8; nop` onto the shared store.
// The ternary `next = (cond) ? X : next;` (and `else next = next;`) gives the plain bc1t (as in 0xee8d0, where it is the fix) but swaps old_val/next to $f4/$f3 (6 words).
// Ruled out (96-file grid: 4 declaration placements x 3 spellings of the compare x 8 spellings of the update; 7 more shapes with temps/bool/`z`): none has both.
