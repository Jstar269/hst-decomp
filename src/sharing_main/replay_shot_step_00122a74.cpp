/* HSTMATCH module=hstp_trans_main.prx start=0x00122a74 end=0x00122c74 symbol=FUN_00122a74 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Replay.cpp (from the assert, line 509): advances the shot index ring of 9 records when the frame counter reaches the next record's start frame, then clamps f70 with an MSL-style `const int &Min` (both operands get stack homes, retail's address select); `self->frame >= rec->frame` gives the register `slt`, `-rec->frame <= self->frame` the `$at` one. */
struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

struct Game {
    char pad0[0x88];
    VObj *f88;
};

struct ShotRec {
    char pad0[0x38];
    int frame;         /* 0x38 */
    char pad3c[4];
    int count;         /* 0x40 */
    char pad44[0x70 - 0x44];
};

struct Replay {
    char pad0[0x50];
    int f50;
    char pad54[4];
    int frame;         /* 0x58 */
    char pad5c[4];
    int f60;
    int m_ShotIndexRecEnd;  /* 0x64 */
    int m_ShotIndex;   /* 0x68 */
    char pad6c[4];
    int f70;
    char pad74[0x80 - 0x74];
    ShotRec recs[9];   /* 0x80 */
};

extern "C" {
extern Game *DAT_003e19f0;
extern char DAT_0038024c[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_00380340[]; /* "nextIndex == m_ShotIndexRecEnd" */
extern char DAT_00380298[]; /* "Replay.cpp" */
void FUN_00121eb4(...);
void FUN_0001f4a0(Game *g, int a, int b, int c);
void FUN_00123284(Replay *r, ShotRec *rec, int f);
void FUN_0008c348(Game *g);
}

#define HST_ASSERT(cond, text, line) do { if (!(cond)) { FUN_00121eb4(DAT_0038024c, text, DAT_00380298, line); for (;;) {} } } while (0)

inline const int &Min(const int &a, const int &b) { return b < a ? b : a; }

extern "C" void FUN_00122a74(Replay *self)
{
    bool done = false;
    if (self->f60 >= 0) {
        if (self->frame == self->f50)
            FUN_0001f4a0(DAT_003e19f0, 20, 0, 0);
        int cur = self->m_ShotIndex;
        int nextIndex = (cur + 1) % 9;
        ShotRec *rec = &self->recs[nextIndex];
        if (rec->frame >= 0 && self->frame >= rec->frame) {
            FUN_00123284(self, rec, 1);
            VObj *o = DAT_003e19f0->f88;
            int n = self->frame - rec->frame;
            for (int j = 0; j < n; j++)
                o->v10();
            self->m_ShotIndex = nextIndex;
            self->f70 = n - 1;
            cur = self->m_ShotIndex;
            nextIndex = (cur + 1) % 9;
            rec = &self->recs[nextIndex];
        }
        if (rec->frame < 0 && -rec->frame <= self->frame) {
            HST_ASSERT(nextIndex == self->m_ShotIndexRecEnd, DAT_00380340, 509);
            done = true;
        }
        self->f70 = Min(self->f70 + 1, self->recs[cur].count - 1);
        self->frame++;
    } else {
        done = true;
    }
    if (done)
        FUN_0008c348(DAT_003e19f0);
}
