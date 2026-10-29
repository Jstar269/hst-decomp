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

struct ReceiveState {
    int state;
    VC *obj;
    void *unk08;
    char pad0c[0x28 - 0x0c];
    int thread;
    char pad2c[0x1b0 - 0x2c];
    VC *listener;
    VC *unk1b4;

    void CloseThread()
    {
        if (thread >= 0) {
            int result = FUN_002b79a8(thread);
            if (result != 0) {
                FUN_0029e3cc(DAT_002cbb24, result);
            }
            thread = -1;
        }
    }

    ~ReceiveState()
    {
        CloseThread();
        FUN_0029e3cc(DAT_002cba24);
        if (listener != 0) {
            delete listener;
            listener = 0;
        }
        FUN_000104e0(unk08);
        if (obj != 0) {
            delete obj;
            obj = 0;
        }
        if (unk1b4 != 0) {
            delete unk1b4;
            unk1b4 = 0;
        }
    }
};

struct ReceiveScreen {
    void *vptr;
    char pad[0x3c - 4];
    ReceiveState *recv;
};

extern "C" ReceiveScreen *FUN_0029e3f8(ReceiveScreen *self, short flags)
{
    if (self != 0) {
        self->vptr = &DAT_00309e80;
        FUN_00047620(1);
        if (self->recv != 0) {
            delete self->recv;
            self->recv = 0;
        }
        FUN_0001f0f0(self, 0);
        if (flags > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}