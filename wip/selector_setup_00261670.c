/* HSTMATCH module=EBOOT.BIN start=0x00261670 end=0x00261884 symbol=FUN_00261670 lang=c99 */
extern void *FUN_001026b8(void *tables, const char *name);
struct Trio { const char *v[3]; };
extern const struct Trio DAT_002fdcf4;
extern const struct Trio DAT_002fdd24;
extern const struct Trio DAT_002fdd30;
extern const struct Trio DAT_002fdd60;
extern char DAT_002fdc40[];
extern char DAT_002fdd6c[];
struct Node { void *f0; short s4; short s6; unsigned char p[0xc]; struct Node *f14; unsigned char q[8]; struct Node *f20; unsigned char r[0x4c]; struct Node *f70; };
struct Entry { struct Node *p0; struct Node *p1; short s8; short s10; struct Node *p3; struct Node *p4; struct Node *p5; int v18; unsigned char pad[0xf0-0x1c]; };
struct World { struct Entry entries[3]; struct Node *title; struct Node *titlebg; int v728; };

static inline void setup(struct Entry *e, void *tables, struct Trio ti, struct Trio tb,
                         struct Trio tx, struct Trio hb)
{
    unsigned int i;
    for (i = 0; i < 3; i++) {
        e->p0 = (struct Node *)FUN_001026b8(tables, ti.v[i]);
        e->p1 = ((struct Node *)FUN_001026b8(tables, tb.v[i]))->f20;
        e->s8 = e->p0->s4;
        e->s10 = e->p0->s6;
        e->p3 = (struct Node *)FUN_001026b8(tables, tb.v[i]);
        e->p4 = (struct Node *)FUN_001026b8(tables, tx.v[i]);
        e->p5 = (struct Node *)FUN_001026b8(tables, hb.v[i]);
        e->v18 = *(int *)e->p4;
        e->p0->f14 = (struct Node *)((char *)e + 0x50);
        e->p1->f70 = (struct Node *)((char *)e + 0x20);
        e->p4->f20->f70 = (struct Node *)((char *)e + 0x20);
        e->p5->f20->f70 = (struct Node *)((char *)e + 0x20);
        e++;
    }
}

void FUN_00261670(struct World *self, void *tables, void *tables2)
{
    setup(self->entries, tables, DAT_002fdcf4, DAT_002fdd24, DAT_002fdd30, DAT_002fdd60);
    self->title = (struct Node *)FUN_001026b8(tables2, DAT_002fdc40);
    self->title->f14 = (struct Node *)((char *)self + 0x50);
    self->titlebg = (struct Node *)FUN_001026b8(tables2, DAT_002fdd6c);
    self->titlebg->f14 = (struct Node *)((char *)self + 0x50);
    self->v728 = 0;
}
// NEAR 90/133 words, function #1 of batch fm4-00.
// Shape that reproduces retail's DEFERRED item lookup: a static inline helper taking FOUR by-value
// 12-byte structs (struct Trio { const char *v[3]; }) whose argument copies land in the caller's frame at
// sp+0x54/0x48/0x3c/0x30 in exactly retail's order (ti, tb, tx, hb -> param order ti,tb,tx,hb; the FIRST
// struct parameter gets the HIGHEST slot and is copied first). The 12-byte globals at 0x2fdcf4 / 0x2fdd24 /
// 0x2fdd30 / 0x2fdd60 are copied with lwc1/swc1 (implicit struct copy), which is what retail shows.
// Loop body (5 calls: ti.v[i], tb.v[i] twice, tx.v[i], hb.v[i]; shorts from tbl+4/+6; three +0x70 back-links)
// is instruction-identical apart from register names.
// WHAT DIFFERS:
//  - prologue schedule: retail emits the whole save block (ra,s8..s0) FIRST and then starts the copies;
//    mwccpsp 219 here always schedules the first lwc1 (and one swc1) above the save block. Tried:
//    declaration+assignment instead of initializer, copies after the e/i setup, plain locals instead of
//    inline-helper params, C++ vs C, for vs do/while - all identical, save block still split.
//  - register colours: retail cursor=e in s2, i in s4, ti-pointer in s3; ours e in s4, i in s3, ti in s2
//    (tb=s1, tx=s0, hb=s6 and the params s7/s5/s8 already match).
// Ruled out: four independent `struct Trio x = DAT_y;` locals (same slots, different copy order and same
// prologue problem); separate const char * members instead of an array member (no strength-reduced walk);
// int-typed locals (lw/sw instead of lwc1/swc1).
// near miss from lane fm4 (unreviewed)
