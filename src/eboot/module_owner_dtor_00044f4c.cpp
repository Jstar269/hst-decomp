/* HSTMATCH module=EBOOT.BIN start=0x00044f4c end=0x00045160 symbol=FUN_00044f4c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VD {
    virtual ~VD();
};

struct Reent {
    char pad[0xc];
    void *err;
};

struct Self {
    void *vt;
    char pad4[0x3c - 4];
    int module;
    char pad40[0x19074 - 0x40];
    VD *main;
    VD *sub[3];
    int pad19084;
    int heap;
    int h0;
    int h1;
    int h2;
};

extern "C" {
Reent *FUN_0000fe3c();
void FUN_00042dd8(void *, const char *, ...);
void FUN_002b7aa8(int);
void FUN_002b7ab0(int);
int FUN_002b7808(int, int, int, int *, int);
int FUN_002b7800(int);
int FUN_000df5c0(int);
void FUN_0001f0f0(Self *, int);
void FUN_00000a00(void *);
}

extern char DAT_00306f7c;
extern int DAT_0030ff7c;
extern const char DAT_002d00a0[];
extern const char DAT_002d00c4[];
extern const char DAT_002d00ec[];

extern "C" Self *FUN_00044f4c(Self *self, short flag)
{
    if (self != 0) {
        self->vt = &DAT_00306f7c;
        for (int i = 0; i < 3; i++) {
            if (self->sub[i] != 0) {
                delete self->sub[i];
                self->sub[i] = 0;
            }
        }
        if (self->main != 0) {
            delete self->main;
            self->main = 0;
        }
        FUN_002b7aa8(self->h0);
        if (self->h1 != 0) {
            FUN_002b7aa8(self->h1);
            self->h1 = 0;
        }
        if (self->h2 != 0) {
            FUN_002b7aa8(self->h2);
            self->h2 = 0;
        }
        FUN_002b7ab0(self->heap);
        int status;
        if (FUN_002b7808(self->module, 0, 0, &status, 0) < 0)
            FUN_00042dd8(FUN_0000fe3c()->err, DAT_002d00a0);
        else if (FUN_002b7800(self->module) < 0)
            FUN_00042dd8(FUN_0000fe3c()->err, DAT_002d00c4);
        else if (FUN_000df5c0(DAT_0030ff7c) == (int)0x80000100) {
            DAT_0030ff7c = 0;
            FUN_00042dd8(FUN_0000fe3c()->err, DAT_002d00ec);
        }
        DAT_0030ff7c = 0;
        FUN_0001f0f0(self, 0);
        if (0 < flag)
            FUN_00000a00(self);
    }
    return self;
}
