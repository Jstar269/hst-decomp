/* HSTMATCH module=EBOOT.BIN start=0x000d4ddc end=0x000d4f44 symbol=FUN_000d4ddc lang=c++ data=0x002d67cc */
/* Clone of src/sharing_main/init_entries_000d8acc.cpp (hstclone.py tag c034920): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d67cc-0x002d680f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern Glob *DAT_003386b0;
extern char DAT_002d6810[];
extern "C" {
void *FUN_00000bcc(int);
A3c *FUN_000535d8(void *);
A40 *FUN_00055dd0(void *);
void FUN_000537bc(A3c *, char *, char *, int, int, int, int);
void FUN_00055eac(A40 *, char *, int);
void FUN_0005743c(Sub *, int, A40 *, int);
void FUN_00057b58(float, Sub *, int, int);
void FUN_00058ec4(float, Sub *, int);
void FUN_00058ddc(Sub *, int, int);
void FUN_00059084(Sub *, int);
}
extern "C" void FUN_000d4ddc(Obj *self)
{
    void *m;
    m = FUN_00000bcc(0x30);
    if (m != 0) m = FUN_000535d8(m);
    self->f3c = (A3c *)m;
    m = FUN_00000bcc(0x10);
    if (m != 0) m = FUN_00055dd0(m);
    self->f40 = (A40 *)m;
    FUN_000537bc(self->f3c, "data/menu/game_eff/charge/charge.i3r", "data/menu/game_eff/charge/", 0, 0, 0, 0);
    FUN_00055eac(self->f40, DAT_002d6810, 0);
    int i = 0;
    int off = 0;
    Ent *p = (Ent *)self;
    do {
        if (*(Player **)((char *)DAT_003386b0 + 0x70 + off) != 0) {
            p->sub.s1(self->f3c);
            FUN_0005743c(&p->sub, 0, self->f40, 0);
            FUN_00057b58(0.0f, &p->sub, 0, 0);
            FUN_00058ec4(1.0f, &p->sub, -1);
            p->f114 = 1.0f;
            FUN_00058ddc(&p->sub, 1, -1);
            p->f110 = 1;
            FUN_00059084(&p->sub, -1);
            p->f120 = p->f114;
        }
        i++;
        off += 4;
        p++;
    } while (i < 4);
}
