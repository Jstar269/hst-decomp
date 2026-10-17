/* HSTMATCH module=EBOOT.BIN start=0x00290ff0 end=0x00291158 symbol=FUN_00290ff0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting-destructor-style wrapper: the held object's inlined destructor resets three 0x1c-byte members (vtable store, close the descriptor like FUN_00290f68) and frees it, then the holder itself is freed when release > 0. Matching idiom: the held pointer is tested twice (`if (o) { if (o) {...free...} self->inner = 0; }`), as retail does; the member addresses are tested with `&o->m != 0` (inlined member destructors). */
extern char DAT_00309dc0;
extern char DAT_002cac10[];
extern int DAT_0034a808;
extern int DAT_0034a818;
extern void FUN_00000a00(void *);
extern void FUN_0028fb44(const char *, int);
extern int FUN_002b7900(int);

struct Sock {
    unsigned int vtable;
    char pad[16];
    int state;
    char pad2[4];
};
struct Inner {
    char pad[0x34];
    struct Sock a;
    struct Sock b;
    struct Sock c;
};
struct Holder {
    struct Inner *inner;
};

struct Holder *FUN_00290ff0(struct Holder *self, short release)
{
    if (self != 0) {
        DAT_0034a818 = 0;
        struct Inner *o = self->inner;
        if (o != 0) {
            if (o != 0) {
                DAT_0034a808 = 0;
                if (&o->c != 0) {
                    o->c.vtable = (unsigned int)&DAT_00309dc0;
                    if (o->c.state >= 0) {
                        int r = FUN_002b7900(o->c.state);
                        if (r != 0)
                            FUN_0028fb44(DAT_002cac10, r);
                        o->c.state = -1;
                    }
                }
                if (&o->b != 0) {
                    o->b.vtable = (unsigned int)&DAT_00309dc0;
                    if (o->b.state >= 0) {
                        int r = FUN_002b7900(o->b.state);
                        if (r != 0)
                            FUN_0028fb44(DAT_002cac10, r);
                        o->b.state = -1;
                    }
                }
                if (&o->a != 0) {
                    o->a.vtable = (unsigned int)&DAT_00309dc0;
                    if (o->a.state >= 0) {
                        int r = FUN_002b7900(o->a.state);
                        if (r != 0)
                            FUN_0028fb44(DAT_002cac10, r);
                        o->a.state = -1;
                    }
                }
                FUN_00000a00(o);
            }
            self->inner = 0;
        }
        if (release > 0)
            FUN_00000a00(self);
    }
    return self;
}
