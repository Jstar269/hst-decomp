/* HSTMATCH module=EBOOT.BIN start=0x0027c908 end=0x0027caa0 symbol=FUN_0027c908 lang=c99 */
typedef struct Item {
    char pad0[0x24];
    int f24;
    int f28;
    float f2c;
    char pad30[4];
    int f34;
    char pad38[8];
} Item;

typedef struct Obj {
    char pad0[0x48];
    Item *cur;
    char pad4c[8];
    int idx;
    int f58;
    char pad5c[0x6c - 0x5c];
    float f6c;
    float f70;
    int f74;
    int f78;
    int f7c;
} Obj;

extern int DAT_0034a7e0;
extern Item *DAT_0034a7e4;
extern int FUN_0027dc84(int, int);
extern void FUN_0027dc90(int, int *);
extern int FUN_0027c774(Obj *, int);
extern void FUN_0027c328(Obj *, int, Item *);

void FUN_0027c908(Obj *o, int idx)
{
    int v;
    int rem;
    int base;
    int next;
    int slot;

    if (idx == o->idx)
        return;
    o->idx = idx;
    o->f58 = 0;
    if (o->f78 >= 0)
        v = o->f7c;
    else
        v = DAT_0034a7e4[o->idx].f24;
    if (v == 0) {
        o->f6c = -1.0f;
        o->f70 = 0.0f;
        o->cur = &DAT_0034a7e4[o->idx];
        FUN_0027c328(o, 0, o->cur);
        return;
    }
    base = FUN_0027dc84(DAT_0034a7e0, DAT_0034a7e4[o->idx].f28);
    slot = o->f78;
    {
        Item *t = DAT_0034a7e4;
        float ft = t[o->idx].f2c;
        float fb = (float)base;
        rem = (int)((ft + fb) - (float)o->f74);
        slot = slot >= 0 ? slot : t[o->idx].f34;
    }
    FUN_0027dc90(slot, &next);
    next = FUN_0027c774(o, next);
    if (rem > 0) {
        Item *to = &DAT_0034a7e4[next];
        Item *from = &DAT_0034a7e4[o->idx];
        o->cur = 0;
        FUN_0027c328(o, 1, from);
        FUN_0027c328(o, 2, to);
        o->f6c = 0.0f;
        o->f70 = (float)rem;
    } else {
        FUN_0027c908(o, next);
    }
}
// lane sx3 NEAR (100/102 words; every difference after +0x1e8 is the 3-word shift of one block): rewritten with a typed Item/Obj layout from the pseudocode.
// Matches: branch layout of the f78/f7c test (`if (o->f78 >= 0) v = o->f7c; else v = tbl[idx].f24;` -> bltzl), the first-call args (base = F(DAT_0034a7e0, tbl[o->idx].f28) as its own
// statement so the table is reloaded after the call), `Item *to` before `Item *from` (s2 = &tbl[next]), add.s order via named locals (`float ft = t[o->idx].f2c; float fb = (float)base; rem = (int)((ft + fb) - (float)o->f74);`).
// Left: in the `slot < 0` arm retail recomputes `lw v0,84(s1); sll v0,v0,6; addu v0,v0,v1` before `lw a0,52(v0)` (table v1 kept, idx*64 NOT reused); ours reuses v0 from the f2c access. Tried: t[...] vs
// DAT[...] vs casts/(t+idx)->f34 vs ItemAt() inline for that access, if/ternary spellings (ternary gives retail's out-of-line arm with `b` over it).
// near miss from lane sx3 (unreviewed)
