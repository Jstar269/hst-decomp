/* HSTMATCH module=EBOOT.BIN start=0x0029e3f8 end=0x0029e550 symbol=FUN_0029e3f8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_00309e80;
extern char DAT_002cba24[];
extern char DAT_002cbb24[];
extern void FUN_00000a00(void *);
extern void FUN_000104e0(void *);
extern void FUN_0001f0f0(void *, int);
extern void FUN_00047620(int);
extern void FUN_0029e3cc(const char *, ...);
extern int FUN_002b79a8(int);
}

struct VC {
    virtual ~VC();
};

struct Inner_0029e3f8 {
    int f0;
    VC *m4;
    void *m8;
    char pad0c[0x28 - 0x0c];
    int state;
    char pad2c[0x1b0 - 0x2c];
    VC *m1b0;
    VC *m1b4;

    void CloseState()
    {
        if (state >= 0) {
            int r = FUN_002b79a8(state);
            if (r != 0) {
                FUN_0029e3cc(DAT_002cbb24, r);
            }
            state = -1;
        }
    }

    ~Inner_0029e3f8()
    {
        CloseState();
        FUN_0029e3cc(DAT_002cba24);
        if (m1b0 != 0) {
            delete m1b0;
            m1b0 = 0;
        }
        FUN_000104e0(m8);
        if (m4 != 0) {
            delete m4;
            m4 = 0;
        }
        if (m1b4 != 0) {
            delete m1b4;
            m1b4 = 0;
        }
    }
};

struct Obj_0029e3f8 {
    void *vptr;
    char pad[0x3c - 4];
    Inner_0029e3f8 *inner;
};

extern "C" Obj_0029e3f8 *FUN_0029e3f8(Obj_0029e3f8 *self, short flag)
{
    if (self != 0) {
        self->vptr = &DAT_00309e80;
        FUN_00047620(1);
        if (self->inner != 0) {
            delete self->inner;
            self->inner = 0;
        }
        FUN_0001f0f0(self, 0);
        if (flag > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}