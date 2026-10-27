/* HSTMATCH module=hstp_trans_main.prx start=0x002a26f8 end=0x002a2860 symbol=FUN_002a26f8 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/holder_release_inner_00290ff0.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Deleting-destructor-style wrapper: the held object's inlined destructor resets three 0x1c-byte members (vtable store, close the descriptor like FUN_002a2670) and frees it, then the holder itself is freed when release > 0. Matching idiom: the held pointer is tested twice (`if (o) { if (o) {...free...} self->inner = 0; }`), as retail does; the member addresses are tested with `&o->m != 0` (inlined member destructors). */
extern char DAT_003b30a8;
extern char DAT_002db244[];
extern int DAT_003f3b38;
extern int DAT_003f3b48;
extern void FUN_00000a00(void *);
extern void FUN_002a130c(const char *, int);
extern int FUN_002c76a0(int);

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

struct Holder *FUN_002a26f8(struct Holder *self, short release)
{
    if (self != 0) {
        DAT_003f3b48 = 0;
        struct Inner *o = self->inner;
        if (o != 0) {
            if (o != 0) {
                DAT_003f3b38 = 0;
                if (&o->c != 0) {
                    o->c.vtable = (unsigned int)&DAT_003b30a8;
                    if (o->c.state >= 0) {
                        int r = FUN_002c76a0(o->c.state);
                        if (r != 0)
                            FUN_002a130c(DAT_002db244, r);
                        o->c.state = -1;
                    }
                }
                if (&o->b != 0) {
                    o->b.vtable = (unsigned int)&DAT_003b30a8;
                    if (o->b.state >= 0) {
                        int r = FUN_002c76a0(o->b.state);
                        if (r != 0)
                            FUN_002a130c(DAT_002db244, r);
                        o->b.state = -1;
                    }
                }
                if (&o->a != 0) {
                    o->a.vtable = (unsigned int)&DAT_003b30a8;
                    if (o->a.state >= 0) {
                        int r = FUN_002c76a0(o->a.state);
                        if (r != 0)
                            FUN_002a130c(DAT_002db244, r);
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
