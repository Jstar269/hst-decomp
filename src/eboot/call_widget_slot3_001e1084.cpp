/* HSTMATCH module=EBOOT.BIN start=0x001e1084 end=0x001e12dc symbol=FUN_001e1084 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls virtual slot 3 (`lw t9,20(t9)`) on a list of widget pointers of the object when non-null (a 21-entry array at +0x1adc is walked in a loop);
   the mode at +0x44 selects an extra call (case 0: object +0x40 and +0xd4, case 1: 0x1eab70 on the field at +0x8c of the object at +0x3c);
   0x1031e8 runs on the object at +0x3c and 0x42ff4 is called last. Names provisional. */
struct Widget {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
};
struct Sub3c {
    char pad[0x8c];
    void *p8c;
};
struct Self {
    char pad[0x3c];
    Sub3c *p3c;
    Widget *w40;
    int mode;
    char pad44[0xd4 - 0x48];
    Widget *wd4;
    char pad_d8[0x1f4 - 0xd8];
    Widget *w1f4;
    char pad1f8[0x810 - 0x1f8];
    Widget *w810;
    char pad814[0x9b4 - 0x814];
    Widget *w9b4;
    char pad9b8[0x175c - 0x9b8];
    Widget *w175c;
    char pad1760[0x1954 - 0x1760];
    Widget *w1954;
    Widget *w1958;
    char pad195c[0x1adc - 0x195c];
    Widget *w1adc[21];
    char pad1b30[0x1d64 - 0x1b30];
    Widget *w1d64;
    Widget *w1d68;
    char pad1d6c[0x21e4 - 0x1d6c];
    Widget *w21e4;
    char pad21e8[0x235c - 0x21e8];
    Widget *w235c;
    char pad2360[0x2464 - 0x2360];
    Widget *w2464;
    char pad2468[0x250c - 0x2468];
    Widget *w250c;
    char pad2510[0x25b8 - 0x2510];
    Widget *w25b8;
};
extern int DAT_00310fc4;
extern "C" {
void FUN_001eab70(void *);
void FUN_001031e8(void *);
void FUN_00042ff4(float, int);
}

extern "C" void FUN_001e1084(Self *self)
{
    if (self->w250c)
        self->w250c->s3();
    switch (self->mode) {
    case 0:
        self->w40->s3();
        if (self->wd4)
            self->wd4->s3();
        break;
    case 1:
        FUN_001eab70(self->p3c->p8c);
        break;
    }
    if (self->p3c)
        FUN_001031e8(self->p3c);
    if (self->w1f4)
        self->w1f4->s3();
    if (self->w9b4)
        self->w9b4->s3();
    if (self->w810)
        self->w810->s3();
    if (self->w175c)
        self->w175c->s3();
    if (self->w1954)
        self->w1954->s3();
    if (self->w1d68)
        self->w1d68->s3();
    if (self->w21e4)
        self->w21e4->s3();
    if (self->w235c)
        self->w235c->s3();
    if (self->w2464)
        self->w2464->s3();
    if (self->w25b8)
        self->w25b8->s3();
    for (int i = 0; i < 21; i++) {
        if (self->w1adc[i])
            self->w1adc[i]->s3();
    }
    if (self->w1958)
        self->w1958->s3();
    if (self->w1d64)
        self->w1d64->s3();
    FUN_00042ff4(100000.0f, DAT_00310fc4);
}
