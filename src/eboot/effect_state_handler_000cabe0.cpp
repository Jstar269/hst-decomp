/* HSTMATCH module=EBOOT.BIN start=0x000cabe0 end=0x000cb5dc symbol=FUN_000cabe0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V { virtual ~V(); };          /* objects owned through a virtual deleting destructor (slot 0) */
struct Eff { char _00[0xd0]; int md0; };

struct Sub90 { char _00[0x44]; int m44; };
struct Global { char _00[0x90]; Sub90 *m90; };

extern "C" {
extern Global *DAT_003386b0;
extern char DAT_0030ebf4[];          /* loader / heap context */
extern char DAT_0034179c[];
extern char DAT_002d5be4[];          /* "game_800_effect_100_effect.xb" */
extern char DAT_002d5c04[];          /* "game_800_effect_200_effect2.xb" */
void *FUN_00000a90(unsigned);        /* operator new[] */
void *FUN_000008d8(void *, void *, void *, unsigned, unsigned); /* __construct_new_array */
void FUN_000006e8(void *, void *);   /* __destroy_new_array */
void FUN_000009e4(void *);           /* operator delete[] */
void *FUN_00000bcc(unsigned);        /* operator new */
void FUN_00056b98();
void FUN_00056cb0();
void *FUN_00063e44(void *, short);
void *FUN_00055e48(void *, short);
void *FUN_00053718(void *, short);
void FUN_000678a0(int);
void FUN_00068e54();
void FUN_00058fc0(void *, int);
void FUN_0005f110(void *, float);
void FUN_001b2040(float, void *, int *);
void FUN_0001ca58(void *, const char *);
void FUN_0001cb88(void *);
V *FUN_000ce954(void *);
V *FUN_000cede4(void *, int);
V *FUN_000d0cfc(void *);
V *FUN_000ebdfc(void *);
V *FUN_000d3204(void *);
V *FUN_000d4288(void *);
V *FUN_000d4cd4(void *);
}

struct Scene;
extern "C" {
void FUN_000c7cd0(Scene *);
void FUN_000c7928(Scene *);
void FUN_000c7ed0(Scene *);
void FUN_0001f21c(Scene *, V *);
}

struct Scene {
    char _00[0x3c];
    V *m3c;
    V *m40;
    int _44;
    V *m48;
    V *m4c;
    V *m50;
    V *m54;
    V *m58;
    int m5c;
    char _60[0x10];
    void *m70;
    V *m74;
    V *m78;
    char _7c[0x1c0 - 0x7c];
    V *m1c0;
    char m1c4;
    int m1c8;
    int m1cc;
    void *m1d0;
    void *m1d4;
    void *m1d8;
    void *m1dc;
    char _1e0[0x2f4 - 0x1e0];
    char m2f4;
};

static inline void ReleaseM70(Scene *self)
{
    if (self->m70) {
        if (self->m70) {
            FUN_00063e44(self->m70, 1);
            self->m70 = 0;
        }
    }
}

static inline void DeleteM74M78(Scene *self)
{
    if (self->m74) { delete self->m74; self->m74 = 0; }
    if (self->m78) { delete self->m78; self->m78 = 0; }
}

static inline void Notify678a0()
{
    FUN_000678a0(DAT_003386b0->m90->m44);
}

static inline void ResetSelection(Scene *self)
{
    self->m1c4 = 0;
    self->m1c8 = -1;
    if (self->m1c0) {
        Eff *e = (Eff *)self->m1c0;
        FUN_00058fc0(e, -1);
        FUN_0005f110(e, 0.0f);
        e->md0 = 0;
    }
    if (self->m1cc != -1) {
        FUN_001b2040(0.2f, DAT_0034179c, &self->m1cc);
        self->m1cc = -1;
    }
}

static inline void StopEffects(Scene *self)
{
    DeleteM74M78(self);
    Notify678a0();
    FUN_00068e54();
    self->m2f4 = 1;
}

static inline void Unload(Scene *self)
{
    if (self->m1d0) { FUN_000006e8(self->m1d0, (void *)FUN_00056cb0); self->m1d0 = 0; }
    if (self->m1d4) { FUN_000009e4(self->m1d4); self->m1d4 = 0; }
    if (self->m1dc) { FUN_00055e48(self->m1dc, 1); self->m1dc = 0; }
    if (self->m1d8) { FUN_00053718(self->m1d8, 1); self->m1d8 = 0; }
    if (self->m1c0) { delete self->m1c0; self->m1c0 = 0; }
    FUN_000c7ed0(self);
    if (self->m58) { delete self->m58; self->m58 = 0; }
    if (self->m54) { delete self->m54; self->m54 = 0; }
    if (self->m50) { delete self->m50; self->m50 = 0; }
    if (self->m4c) { delete self->m4c; self->m4c = 0; }
    if (self->m48) { delete self->m48; self->m48 = 0; }
    if (self->m40) { delete self->m40; self->m40 = 0; }
    if (self->m3c) { delete self->m3c; self->m3c = 0; }
}

static inline void Load(Scene *self)
{
    if (self->m1d0 == 0)
        self->m1d0 = FUN_000008d8(FUN_00000a90(0x6d0), (void *)FUN_00056b98, (void *)FUN_00056cb0, 0x1b0, 4);
    if (self->m1d4 == 0)
        self->m1d4 = FUN_00000a90(4);
    FUN_0001ca58(DAT_0030ebf4, DAT_002d5be4);
    void *mem;
    if (self->m3c == 0) {
        mem = FUN_00000bcc(0x550);
        if (mem) mem = FUN_000ce954(mem);
        self->m3c = (V *)mem;
    }
    if (self->m40 == 0) {
        mem = FUN_00000bcc(0xc0);
        if (mem) mem = FUN_000cede4(mem, self->m5c);
        self->m40 = (V *)mem;
    }
    if (self->m48 == 0) {
        mem = FUN_00000bcc(0x1d0);
        if (mem) mem = FUN_000d0cfc(mem);
        self->m48 = (V *)mem;
    }
    if (self->m4c == 0) {
        mem = FUN_00000bcc(0x74);
        if (mem) mem = FUN_000ebdfc(mem);
        self->m4c = (V *)mem;
    }
    FUN_0001cb88(DAT_0030ebf4);
    FUN_0001ca58(DAT_0030ebf4, DAT_002d5c04);
    if (self->m50 == 0) {
        mem = FUN_00000bcc(0x7b0);
        if (mem) mem = FUN_000d3204(mem);
        self->m50 = (V *)mem;
    }
    if (self->m54 == 0) {
        mem = FUN_00000bcc(0x54);
        if (mem) mem = FUN_000d4288(mem);
        self->m54 = (V *)mem;
    }
    if (self->m58 == 0) {
        mem = FUN_00000bcc(0x720);
        if (mem) mem = FUN_000d4cd4(mem);
        self->m58 = (V *)mem;
    }
    FUN_000c7cd0(self);
    FUN_000c7928(self);
    FUN_0001cb88(DAT_0030ebf4);
    FUN_0001f21c(self, self->m3c);
    FUN_0001f21c(self, self->m40);
    FUN_0001f21c(self, self->m48);
    FUN_0001f21c(self, self->m4c);
    FUN_0001f21c(self, self->m50);
    FUN_0001f21c(self, self->m54);
    FUN_0001f21c(self, self->m58);
}

/* Scene state handler: for each state id release or delete the matching owned objects, reset the selection, or load/unload the effect resources. Always returns 0. */
extern "C" int FUN_000cabe0(Scene *self, int state)
{
    switch (state) {
    case 0xc:
        self->m2f4 = 1;
        ReleaseM70(self);
        Notify678a0();
        DeleteM74M78(self);
        break;
    case 0x16:
        ReleaseM70(self);
        Notify678a0();
        DeleteM74M78(self);
        self->m2f4 = 0;
        break;
    case 0xe:
        ReleaseM70(self);
        Notify678a0();
        DeleteM74M78(self);
        self->m2f4 = 0;
        ResetSelection(self);
        break;
    case 0xf:
        self->m2f4 = 1;
        break;
    case 0xd:
        Notify678a0();
        ResetSelection(self);
        break;
    case 0x8:
        DeleteM74M78(self);
        self->m2f4 = 0;
        break;
    case 0x12:
        StopEffects(self);
        /* retail keeps this always-false test (state is 0x12 here) */
        if (state == 0x10) break;
        Unload(self);
        break;
    case 0x10:
        StopEffects(self);
        break;
    case 0x13:
        Unload(self);
        break;
    case 0x18:
        Load(self);
        break;
    }
    return 0;
}
