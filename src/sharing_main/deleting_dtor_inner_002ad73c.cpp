/* HSTMATCH module=hstp_trans_main.prx start=0x002ad73c end=0x002ad894 symbol=FUN_002ad73c lang=c++ */
/* Clone of src/eboot/deleting_dtor_inner_0029e3f8.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003b314c;
extern char DAT_002dbac4[];
extern char DAT_002dbbc4[];
extern void FUN_00000a00(void *);
extern void FUN_000104e0(void *);
extern void FUN_0001ed28(void *, int);
extern void FUN_00047aa4(int);
extern void FUN_002ad710(const char *, ...);
extern int FUN_002c7748(int);
}

struct VC {
    virtual ~VC();
};

struct Inner_002ad73c {
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
            int r = FUN_002c7748(state);
            if (r != 0) {
                FUN_002ad710(DAT_002dbbc4, r);
            }
            state = -1;
        }
    }

    ~Inner_002ad73c()
    {
        CloseState();
        FUN_002ad710(DAT_002dbac4);
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

struct Obj_002ad73c {
    void *vptr;
    char pad[0x3c - 4];
    Inner_002ad73c *inner;
};

extern "C" Obj_002ad73c *FUN_002ad73c(Obj_002ad73c *self, short flag)
{
    if (self != 0) {
        self->vptr = &DAT_003b314c;
        FUN_00047aa4(1);
        if (self->inner != 0) {
            delete self->inner;
            self->inner = 0;
        }
        FUN_0001ed28(self, 0);
        if (flag > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}