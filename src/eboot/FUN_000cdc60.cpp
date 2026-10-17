/* HSTMATCH module=EBOOT.BIN start=0x000cdc60 end=0x000ce180 symbol=FUN_000cdc60 lang=c++ */
/* Clone of src/sharing_main/FUN_000d185c.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: `volatile int last` (loop bound reloaded per pass), by-value getter `GetV10()` (batched Vec4 copy), byte-offset accumulation `off = idx * 16; off += (int)self` (index-first addu), by-value inline setter `SetV60(Vec4)` called with a Vec4(...) temporary (two stack copies), chained ifs for the 0/1/2 mappings, unsigned range test `k - 4U < 2`; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct Ent34 { char pad[0x30]; float f; };
struct Mat4 { Vec4 r0, r1, r2, r3; };
struct Sub {
    virtual ~Sub();
    char pad4[0x60 - 4];
    Vec4 v60;
    char pad70[0x7c - 0x70];
    int f7c;
    void SetV60(Vec4 v) { v60 = v; }
};

struct Slot {
    char pad0[0xdc];
    Ent34 ents[1];
    char padE[0x158 - 0xdc - 0x34];
    int first;                  /* 0x158 */
    volatile int last;          /* 0x15c */
    char pad160[0x1b0 - 0x160];
    int state;                  /* 0x1b0 */
    bool HasActive()
    {
        for (int i = first; i <= last; i++) {
            if (ents[i].f != 0.0f) {
                return true;
            }
        }
        return false;
    }
};

struct Ball {
    char pad0[0x10];
    Vec4 v10;
    Vec4 v20;
    Vec4 GetV10() { return v10; }
};
struct Player { char pad0[0x4d8]; unsigned char flag; char pad4d9[0x5bc - 0x4d9]; int f5bc; };
struct Game {
    char pad0[0x70];
    Player *players[6];
    Ball *ball;
};

struct Ent16 { int f84; int f88; int f8c; int f90; };
struct EntView { char pad[0x84]; int f84; int f88; int f8c; int f90; };

struct Obj {
    char pad0[0x48];
    int f48;
    char pad4c[0x60 - 0x4c];
    Vec4 v60;
    char pad70[4];
    Sub *o74;
    Sub *o78;
    char pad7c[0x80 - 0x7c];
    int f80;
    Ent16 ent[16];
    char pad184[0x18c - 0x184];
    Slot *slots[10];
    int *f1b4;
    char pad1b8[0x2f0 - 0x1b8];
    float f2f0;
};

extern Game *DAT_003386b0;
extern float DAT_002d279c;
extern unsigned DAT_002d5ab0;

extern "C" {
void FUN_00093a90(Vec4 *, int);
void FUN_000ca9c8(Obj *, int);
void FUN_000d13e4(int, int, int, int, int, Vec4, Vec4, int);
void FUN_0001d998(Mat4 *, Vec4 *);
void FUN_00055044(Slot *, Mat4 *);
void FUN_000550ec(float, Slot *);
void FUN_0001f21c(Obj *, Sub *);
void *FUN_00000bcc(int);
Sub *FUN_000dfdf8(Sub *, int);
}

extern "C" void FUN_000cdc60(Obj *self, int idx, int play)
{
    Ball *ball = DAT_003386b0->ball;
    self->v60 = ball->GetV10();
    self->v60.y = self->v60.y - self->f2f0 * (DAT_002d279c - 1.0f);

    Vec4 b;
    Vec4 a;
    ball = DAT_003386b0->ball;
    FUN_00093a90(&b, DAT_003386b0->players[idx]->f5bc);
    a = ball->v20;
    FUN_000ca9c8(self, idx);
    if ((DAT_002d5ab0 & 0x1000) != 0) {
        int off = idx * 16;
        off += (int)self;
        EntView *e = (EntView *)off;
        FUN_000d13e4(self->f48, idx, e->f8c, e->f90, e->f84, b, a, play);
    }
    self->f80 = idx;
    if ((DAT_002d5ab0 & 0x1000) != 0) {
        int off = idx * 16;
        off += (int)self;
        int *pk = &((EntView *)off)->f8c;
        int k = *pk;
        if (k != 7 && k - 4U < 2) {
            Mat4 m;
            FUN_0001d998(&m, &a);
            m.r3 = b;
            FUN_00055044(self->slots[*pk], &m);
            FUN_000550ec(DAT_002d279c, self->slots[*pk]);
            Slot *s = self->slots[*pk];
            if (!s->HasActive()) {
                s->state = 5;
            }
        }
    }
    if (self->o74) {
        delete self->o74;
        self->o74 = 0;
    }
    if (self->o78) {
        delete self->o78;
        self->o78 = 0;
    }
    int u = 0;
    int w = self->ent[idx].f84;
    if (w == 0) u = 1;
    if (w == 1) u = 2;
    if (w == 2) u = 0;
    if ((DAT_002d5ab0 & 0x1000) == 0) {
        return;
    }
    if (DAT_003386b0->players[idx]->flag != 0 || self->ent[idx].f8c == 4) {
        Sub *n = (Sub *)FUN_00000bcc(0x80);
        if (n) n = FUN_000dfdf8(n, self->f1b4[u]);
        self->o74 = n;
        int w2 = self->ent[idx].f84;
        int u2 = 0;
        if (w2 == 0) u2 = 4;
        if (w2 == 1) u2 = 5;
        if (w2 == 2) u2 = 3;
        Sub *n2 = (Sub *)FUN_00000bcc(0x80);
        if (n2) n2 = FUN_000dfdf8(n2, self->f1b4[u2]);
        self->o78 = n2;
        self->o78->SetV60(Vec4(128.0f, 128.0f, 128.0f, 128.0f));
    } else {
        Sub *n = (Sub *)FUN_00000bcc(0x80);
        if (n) n = FUN_000dfdf8(n, self->f1b4[u]);
        self->o74 = n;
    }
    self->o74->SetV60(Vec4(128.0f, 128.0f, 128.0f, 128.0f));
    if (DAT_003386b0->players[idx]->flag != 0 || self->ent[idx].f8c == 4) {
        self->o74->f7c = u;
        self->o78->f7c = 3;
    } else {
        self->o74->f7c = u;
    }
    FUN_0001f21c(self, self->o74);
    if (DAT_003386b0->players[idx]->flag != 0 || self->ent[idx].f8c == 4) {
        FUN_0001f21c(self, self->o78);
    }
}
