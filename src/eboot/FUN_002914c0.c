/* HSTMATCH module=EBOOT.BIN start=0x002914c0 end=0x00291688 symbol=FUN_002914c0 lang=c99 */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode shape); matching idiom: the inner object is allocated in the condition (if ((o = alloc(0x1f0)) != 0)) so the copy lands in the beqz slot and the holder store after the join is not merged into a likely branch; exact match verified; names and types await human review. */
extern char DAT_00309db4;
extern char DAT_00309dc0;
extern char DAT_002ff9a8[];
extern void *DAT_0034a81c;
extern struct Holder *DAT_0034a818;
extern struct Inner *DAT_0034a808;
extern void *FUN_00000bcc(unsigned);
extern void *FUN_000114c0(void *, int, unsigned);
extern void FUN_00050fc0(void *);
extern void FUN_0028f5e4(struct Inner *, int);
extern int FUN_0004e780(int *, int *, int, int, int, int);
extern void FUN_00051274(void *, const char *, int, int, int);
extern int FUN_00051450(void *);
extern void FUN_00022d7c(int, int, int);
extern void FUN_00051398(float, void *);

struct Sock {
    unsigned int vtable;
    char pad[16];
    int state;
    char pad2[4];
};

struct Inner {
    char pad0[0x28];
    unsigned char f28;
    unsigned char f29;
    unsigned char f2a;
    char pad1;
    int f2c;
    int f30;
    struct Sock a;
    struct Sock b;
    struct Sock c;
    char pad2[0xdc - 0x6c - sizeof(struct Sock)];
    int fdc;
    int fe0;
    int fe4;
    int fe8;
    char pad3[0x1f0 - 0xec];
};

struct Holder {
    struct Inner *inner;
};

struct Player {
    unsigned int vtable;
    char pad[0x1c];
    unsigned char f20;
    unsigned char f21;
    unsigned char f22;
};

struct Player *FUN_002914c0(struct Player *self, int param_2)
{
    struct Holder *h;
    int local_4;
    int local_8;

    FUN_00050fc0(self);
    self->vtable = (unsigned int)&DAT_00309db4;
    DAT_0034a81c = self;
    h = (struct Holder *)FUN_00000bcc(4);
    if (h != 0) {
        struct Inner *o;
        h->inner = 0;
        if ((o = (struct Inner *)FUN_00000bcc(0x1f0)) != 0) {
            o->f28 = 0;
            o->f29 = 0;
            o->f2a = 0;
            o->f2c = 0;
            o->f30 = 0;
            o->a.vtable = (unsigned int)&DAT_00309dc0;
            o->a.state = -1;
            o->b.vtable = (unsigned int)&DAT_00309dc0;
            o->b.state = -1;
            o->c.vtable = (unsigned int)&DAT_00309dc0;
            o->c.state = -1;
            o->fdc = 0;
            o->fe0 = 0;
            o->fe4 = 0;
            o->fe8 = 0;
            DAT_0034a808 = o;
            FUN_000114c0(o, 0, 4);
            FUN_000114c0((char *)o + 4, 0, 12);
            FUN_000114c0((char *)o + 16, 0, 24);
            FUN_000114c0((char *)o + 212, 0, 8);
            FUN_000114c0((char *)o + 140, 0, 72);
            FUN_000114c0((char *)o + 236, 0, 256);
        }
        h->inner = o;
        DAT_0034a818 = h;
    }
    FUN_0028f5e4(DAT_0034a818->inner, param_2);
    local_4 = 0;
    local_8 = 0;
    FUN_00051274(self, DAT_002ff9a8, FUN_0004e780(&local_4, &local_8, 3, 0, 0x200, 0x110), 1, 0x10);
    FUN_00022d7c(FUN_00051450(self), 0, 0x88000);
    FUN_00051398(9998.0f, self);
    self->f21 = 0;
    self->f22 = 0;
    return self;
}
