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
    float next = 0.0f;
    float old_val = obj->GetVal();
    if (obj->count >= 20) {
        float diff = next - old_val;
        next = (fabsf(diff) >= 0.01f) ? (old_val + diff * 0.3f) : next;
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

// Near miss: 43/49 words match (6 differing words).
// Control flow, branches, addresses, and constants are identical.
// Differing words:
// 1) FPR register allocation: retail allocates old_val to $f3 and next to $f4, while MWCC allocates old_val to $f4 and next to $f3.
// 2) Branch delay slot: retail uses `bc1t 0xf17b8` with `nop` in delay slot branching directly to the common `swc1` at 0xf17b8, while MWCC generates `bc1tl 0xf17bc` duplicating the store into the branch-likely delay slot.
// near miss from lane s10172123g8r1-1 (unreviewed)
