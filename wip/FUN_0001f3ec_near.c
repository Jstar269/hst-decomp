/* HSTMATCH module=EBOOT.BIN start=0x0001f3ec end=0x0001f540 symbol=FUN_0001f3ec lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Frame 48 = 28 saved registers + 16 bytes of home area, which the unprototyped indirect
   dispatch forces. a0 = the object (its first word is the vtable), a1 = a slot index (stride 8: bytes 36/37 and a
   word at 40 per slot), a2 = an offset that is also added to a0 for a gate byte at +32. The tail walks an intrusive
   list: head at +12, a cursor word at +20, and per element a pointer at +8 that is recursed into; the recursion can
   clear the object's +8 count, so the cursor is re-read through its address after every call. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Node {
    u32 f0;                      /* 0 */
    u32 f4;                      /* 4 */
    u32 f8;                      /* 8: recursed-into object */
    u32 fc;                      /* 12 */
} Node;

typedef struct Vt {
    void (*f0)(void *, ...);     /* variadic: retail homes a0..a3 (16 bytes) for these calls */
    void (*f1)(void *, ...);
    void (*f2)(void *, ...);
    void (*f3)(void *, ...);     /* 12 */
    void (*f4)(void *, ...);     /* 16 */
    void (*f5)(void *, ...);     /* 20 */
} Vt;

typedef struct Obj {
    Vt *vt;                      /* 0 */
    u32 f4;                      /* 4 */
    u32 f8;                      /* 8: live count */
    Node *f0c;                   /* 12: sentinel node (list head) */
    Node *f10;                   /* 16: walk start */
    u32 f14;                     /* 20: walk cursor */
    u8 f18;                      /* 24 */
    u8 pad19[7];
    u8 f20;                      /* 32: gate byte */
} Obj;

void FUN_0001f3ec(Obj *self, int idx, int off);

void FUN_0001f3ec(Obj *self, int idx, int off)
{
    Node *head;
    Node *cur;
    u32 *slot;

    if (*(u8 *)((char *)self + off + 32) == 0)
        return;
    if (*(u8 *)((char *)self + idx * 8 + 37) == 0)
        return;
    if (*(u8 *)((char *)self + idx * 8 + 36) != 0) {
        if (*(u32 *)((char *)self + idx * 8 + 40) == (u32)off) {
            switch (idx) {
            case 0:
                self->vt->f3(self);
                break;
            case 1:
                self->vt->f4(self);
                break;
            case 2:
                self->vt->f5(self);
                break;
            }
        }
    }

    if (self->f8 == 0)
        return;

    head = (Node *)((char *)self + 12);
    slot = &self->f14;
    cur = (Node *)self->f10;
    *slot = (u32)cur;
    if (cur != head) {
        do {
            ((void (*)())FUN_0001f3ec)((Obj *)cur->f8, idx, off);
            if (self->f8 == 0)
                break;
            if ((Node *)*slot == head)
                break;
            if ((Node *)*slot != cur)
                cur = (Node *)*slot;
            else {
                cur = (Node *)cur->f4;
                *slot = (u32)cur;
            }
        } while (cur != head);
    }
    *slot = (u32)head;
}

// PHASE-3 REBUILD (2026-10-28, pass 17): rewritten from the disassembly; the old draft was 78/85 words.
// NOW 85/85 words (extent exact), 36 differ. Decode: a gate byte at `a0 + a2 + 32`; a per-slot byte pair at
// `a0 + idx*8 + 36/37` and a word at `+40`; a 3-way dispatch through the vtable at **offset 0** of the object
// (`lw t9,0(a0); lw t9,{12,16,20}(t9); jalr t9` - the C++ virtual-call shape, this pointer in a0); then an
// intrusive-list walk: sentinel at `self+12`, start at `+16`, cursor at `+20`, per element a pointer at `+8` that is
// recursed into, and the recursion can clear the object's `+8` count, so the cursor is re-read through `&self->f14`
// after every call.
// FRAME: retail -48, ours -32. The 16 bytes cannot come from a variadic or unprototyped indirect call (both tried;
// each keeps -32) and nothing in retail stores to sp+32..47, so it is pure home-area slack. The frame is a single
// differing word, not a shifter.
// STEERING: the recursive call goes through an unprototyped function-pointer cast (`((void (*)())
// FUN_0001f3ec)(...)`), which is the only form that reaches retail's 85-word extent; named here per the brief.
// LEFT (36): retail loads the vptr through a0 and calls through t9; ours loads through s5 into v0 (a0 is not kept
// as this). Also s0/s1 are swapped (retail: s0 = sentinel, s1 = &cursor) and retail recomputes `self+12` into v1 at
// each store instead of keeping it in a register.
// improved by lane dsn2 (unreviewed): 85 -> 36 differing words
