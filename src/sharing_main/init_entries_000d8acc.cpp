/* HSTMATCH module=hstp_trans_main.prx start=0x000d8acc end=0x000d8c34 symbol=FUN_000d8acc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the global's pointer slot is read through a byte offset (`(char *)G + 0x70 + off`) with the counter, offset and entry pointer declared in that order; `G->players[i]` gives other registers. The entry pointer starts at self itself (entry 0 overlaps the +0x3c/+0x40 members). */
struct A3c { int x; };
struct A40 { int x; };
struct Sub {
    virtual void s0();
    virtual void s1(A3c *a);
    char pad[0xc0 - 4];
};
struct Ent {
    char pad0[0x50];
    Sub sub;
    unsigned char f110;
    char pad1[3];
    float f114;
    char pad2[8];
    float f120;
    char pad3[0x1b0 - 0x124];
};
struct Player;
struct Glob {
    char pad[0x70];
    Player *players[4];
};
struct Obj {
    char pad0[0x3c];
    A3c *f3c;
    A40 *f40;
};
extern Glob *DAT_003e19f0;
extern char DAT_0037d2bc[];
extern char DAT_0037d2e4[];
extern char DAT_0037d300[];
extern "C" {
void *FUN_00000bcc(int);
A3c *FUN_00054098(void *);
A40 *FUN_0005697c(void *);
void FUN_0005427c(A3c *, char *, char *, int, int, int, int);
void FUN_00056a58(A40 *, char *, int);
void FUN_00058090(Sub *, int, A40 *, int);
void FUN_000587ac(float, Sub *, int, int);
void FUN_00059ba8(float, Sub *, int);
void FUN_00059ac0(Sub *, int, int);
void FUN_00059d68(Sub *, int);
}
extern "C" void FUN_000d8acc(Obj *self)
{
    void *m;
    m = FUN_00000bcc(0x30);
    if (m != 0) m = FUN_00054098(m);
    self->f3c = (A3c *)m;
    m = FUN_00000bcc(0x10);
    if (m != 0) m = FUN_0005697c(m);
    self->f40 = (A40 *)m;
    FUN_0005427c(self->f3c, DAT_0037d2bc, DAT_0037d2e4, 0, 0, 0, 0);
    FUN_00056a58(self->f40, DAT_0037d300, 0);
    int i = 0;
    int off = 0;
    Ent *p = (Ent *)self;
    do {
        if (*(Player **)((char *)DAT_003e19f0 + 0x70 + off) != 0) {
            p->sub.s1(self->f3c);
            FUN_00058090(&p->sub, 0, self->f40, 0);
            FUN_000587ac(0.0f, &p->sub, 0, 0);
            FUN_00059ba8(1.0f, &p->sub, -1);
            p->f114 = 1.0f;
            FUN_00059ac0(&p->sub, 1, -1);
            p->f110 = 1;
            FUN_00059d68(&p->sub, -1);
            p->f120 = p->f114;
        }
        i++;
        off += 4;
        p++;
    } while (i < 4);
}
