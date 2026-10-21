/* HSTMATCH module=hstp_trans_main.prx start=0x00214428 end=0x00214624 symbol=FUN_00214428 lang=c++ */
/* Clone of src/eboot/entity_update_00205bc0.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode; matching idioms: the table lookup is ONE compound condition with a single else (if (t != 0 && idx >= 0 && idx < 15) pf = ...; else pf = 0;) so the failing arms share one move-zero block, the entity is read into a local before the lookup so its load fills the beqz slot, FUN_00214254 gets the next-state as its dropped third argument, and the 16 identity floats are copied one statement at a time; exact match verified; names and types await human review. */
struct Mat {
    float m[16];
};

extern Mat DAT_002cc260;
extern char DAT_003977b0[];

struct Entity {
    virtual void v0();
    virtual void v1();
};

struct Obj {
    Entity *ent;
    char pad4[0x1c];
    float pos[4];
    float a30;
    float a34;
    float a38;
    char pad3c[4];
    float scale;
    char pad44[8];
    int cur;
    int next;
    int idx;
};

struct Table {
    float v[4];
};

extern Table *DAT_003f3480;

extern "C" {
void FUN_00214254(void *, int, int);
void FUN_00214280(Obj *);
void FUN_0004d644(float, Mat *, Mat *);
void FUN_0004d5f0(float, Mat *, Mat *);
void FUN_0004d698(float, Mat *, Mat *);
void FUN_00095380(Entity *, float *);
void FUN_000953a8(float, Entity *);
void FUN_00095358(Entity *, Mat *);
void FUN_00213dc0(Obj *);
}

extern "C" void FUN_00214428(Obj *self)
{
    Mat m;

    if (self->next != 0) {
        FUN_00214254(DAT_003977b0, self->cur, self->next);
        self->cur = self->next;
        self->next = 0;
    }
    m.m[0] = DAT_002cc260.m[0];
    m.m[1] = DAT_002cc260.m[1];
    m.m[2] = DAT_002cc260.m[2];
    m.m[3] = DAT_002cc260.m[3];
    m.m[4] = DAT_002cc260.m[4];
    m.m[5] = DAT_002cc260.m[5];
    m.m[6] = DAT_002cc260.m[6];
    m.m[7] = DAT_002cc260.m[7];
    m.m[8] = DAT_002cc260.m[8];
    m.m[9] = DAT_002cc260.m[9];
    m.m[10] = DAT_002cc260.m[10];
    m.m[11] = DAT_002cc260.m[11];
    m.m[12] = DAT_002cc260.m[12];
    m.m[13] = DAT_002cc260.m[13];
    m.m[14] = DAT_002cc260.m[14];
    m.m[15] = DAT_002cc260.m[15];
    FUN_00214280(self);
    FUN_0004d644(self->a34, &m, &m);
    FUN_0004d5f0(self->a30, &m, &m);
    FUN_0004d698(self->a38, &m, &m);
    m.m[12] = self->pos[0];
    m.m[13] = self->pos[1];
    m.m[14] = self->pos[2];
    m.m[15] = self->pos[3];
    FUN_00095380(self->ent, self->pos);
    Entity *e = self->ent;
    int idx = self->idx;
    Table *t = DAT_003f3480;
    float *pf;
    if (t != 0 && idx >= 0 && idx < 15) {
        pf = t[idx].v;
    } else {
        pf = 0;
    }
    float s;
    if (pf != 0) {
        s = self->scale * *pf;
    } else {
        s = 1.0f;
    }
    FUN_000953a8(s, e);
    FUN_00095358(self->ent, &m);
    if (self->cur >= 3) {
        self->ent->v1();
        FUN_00213dc0(self);
    }
}
