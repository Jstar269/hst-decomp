/* HSTMATCH module=hstp_trans_main.prx start=0x002a2acc end=0x002a2c94 symbol=FUN_002a2acc lang=c99 data=0x003a88b4 */
/* Clone of src/eboot/FUN_002914c0.c (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003a88b4-0x003a88c7) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode shape); matching idiom: the inner object is allocated in the condition (if ((o = alloc(0x1f0)) != 0)) so the copy lands in the beqz slot and the holder store after the join is not merged into a likely branch; exact match verified; names and types await human review. */
extern char DAT_003b309c;
extern char DAT_003b30a8;
extern void *DAT_003f3b4c;
extern struct Holder *DAT_003f3b48;
extern struct Inner *DAT_003f3b38;
extern void *FUN_00000bcc(unsigned);
extern void *FUN_000114c0(void *, int, unsigned);
extern void FUN_000518d4(void *);
extern void FUN_002a0dac(struct Inner *, int);
extern int FUN_0004eaf8(int *, int *, int, int, int, int);
extern void FUN_00051b88(void *, const char *, int, int, int);
extern int FUN_00051df0(void *);
extern void FUN_00022da4(int, int, int);
extern void FUN_00051d38(float, void *);

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

struct Player *FUN_002a2acc(struct Player *self, int param_2)
{
    struct Holder *h;
    int local_4;
    int local_8;

    FUN_000518d4(self);
    self->vtable = (unsigned int)&DAT_003b309c;
    DAT_003f3b4c = self;
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
            o->a.vtable = (unsigned int)&DAT_003b30a8;
            o->a.state = -1;
            o->b.vtable = (unsigned int)&DAT_003b30a8;
            o->b.state = -1;
            o->c.vtable = (unsigned int)&DAT_003b30a8;
            o->c.state = -1;
            o->fdc = 0;
            o->fe0 = 0;
            o->fe4 = 0;
            o->fe8 = 0;
            DAT_003f3b38 = o;
            FUN_000114c0(o, 0, 4);
            FUN_000114c0((char *)o + 4, 0, 12);
            FUN_000114c0((char *)o + 16, 0, 24);
            FUN_000114c0((char *)o + 212, 0, 8);
            FUN_000114c0((char *)o + 140, 0, 72);
            FUN_000114c0((char *)o + 236, 0, 256);
        }
        h->inner = o;
        DAT_003f3b48 = h;
    }
    FUN_002a0dac(DAT_003f3b48->inner, param_2);
    local_4 = 0;
    local_8 = 0;
    FUN_00051b88(self, "PsmfPlayerMaterial", FUN_0004eaf8(&local_4, &local_8, 3, 0, 0x200, 0x110), 1, 0x10);
    FUN_00022da4(FUN_00051df0(self), 0, 0x88000);
    FUN_00051d38(9998.0f, self);
    self->f21 = 0;
    self->f22 = 0;
    return self;
}
