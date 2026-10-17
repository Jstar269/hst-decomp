/* HSTMATCH module=hstp_trans_main.prx start=0x0008a19c end=0x0008ad08 symbol=FUN_0008a19c lang=c++ rodata=0x002ce73c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Task;
struct Obj;

struct Court { char pad0[0x1364]; int ncourts; };
struct BallBase { char pad0[0x1e0]; };
struct BallTask { char pad0[4]; };
struct Ball : BallBase, BallTask {};

struct Rules { char pad0[0x45]; unsigned char doubles; };
struct Remote { char pad0[0x7a]; unsigned char ready; };
struct Net { char pad0[0x80]; Remote *remote; };
struct Hud { char pad0[0xc]; int count; char pad10[0x52 - 0x10]; unsigned char shown; };
struct Stats { char pad0[0x1c]; int value; };
struct Score { char pad0[0x1e0]; int value; };

struct Scene {
    char pad0[0x3c];
    int state;
    int next;
    int m44;
    int m48;
    unsigned char m4c;
    int m50;
    int m54;
    unsigned char busy;
    char pad59;
    unsigned char m5a;
    unsigned char m5b;
    int side;
    int m60;
    int m64;
    unsigned char m68;
    int timer;
    Obj *players[4];
    Obj *fuki;
    Obj *fukiAnim;
    Ball *ball;
    Obj *m8c;
    Obj *effect;
    Obj *inpane;
    Obj *banner;
    Obj *m9c;
    Score *score;
    Obj *ma4;
    Obj *sound;
};

extern Hud *DAT_003daec4;
extern Obj *DAT_003e1a54;
extern Obj *DAT_003e1a0c;
extern Obj *DAT_003f39e0;
extern char *DAT_003f39d8;
extern char *DAT_003f39dc;
extern Obj *DAT_003f39e4;
extern Obj *DAT_003f39e8;
extern char *DAT_003f3b18;
extern Obj *DAT_003e1df0;
extern unsigned char DAT_003e19f8;
extern char DAT_003b7ebc[];
extern char DAT_003eaad8[];
extern char DAT_003eab08[];
extern char DAT_003eac28[];
extern char DAT_003ead48[];
extern char DAT_003eae68[];
extern Rules *DAT_003e1e84;
extern Obj *DAT_003e1f60;
extern Net *DAT_003e95c4;
extern Obj *DAT_003e1e30;
extern Obj *DAT_003ba2c4;

extern const char DAT_003782e0[];   /* "Game" */
extern const char DAT_003782e8[];   /* "game/100_common/common.xb" */
extern const char DAT_00378304[];   /* "AI" */
extern const char DAT_00378308[];   /* "data/common/parameter/AI_Param_%d.csv" */
extern const char DAT_00378330[];   /* "data/common/parameter/AI_param_PC.csv" */
extern const char DAT_00378358[];   /* "data/common/parameter/AI_param_NPC.csv" */
extern const char DAT_00378380[];   /* "data/chara/parameter/PCGut_PcGut.txt" */
extern const char DAT_003783a8[];   /* "data/chara/parameter/PCGut_NpcGut.txt" */
extern const char DAT_003783d0[];   /* "data/common/ase_fuki/ase_fuki.i3r" */
extern const char DAT_003783f4[];   /* "data/common/ase_fuki/ase_fuki.tat" */
extern const char DAT_00378418[];   /* "data/common/ase_fuki/" */
extern const char DAT_00378430[];   /* "Court" */
extern const char DAT_00378438[];   /* "Ball" */
extern const char DAT_00378440[];   /* "Player" */
extern const char DAT_00378448[];   /* "Effect" */
extern const char DAT_00378450[];   /* "Sound" */
extern const char DAT_00378458[];   /* "Inpane" */
extern const char DAT_00378460[];   /* "Banner" */

void *operator new(unsigned int);

extern "C" {
void FUN_0001f4a0(Scene *, int, int, int);
void FUN_0001ef34(Scene *, void *);
void FUN_00000010(const char *);
void FUN_00000018();
void FUN_00000020(const char *);
void FUN_00000028();
void *FUN_00000a90(unsigned int);
void *FUN_000008d8(void *, void *, void *, unsigned int, unsigned int);
void FUN_0001c5f4(char *, const char *, ...);
void FUN_0001c73c(char *);
int FUN_000143b0(char *, const char *, ...);
Obj *FUN_0005c2f8(void *);
void FUN_00245e7c();
void FUN_00089e18();
void FUN_00245ed0(Obj *);
void FUN_002448f0();
void FUN_0024492c();
void FUN_002449c4(char *, const char *);
void FUN_00246144();
void FUN_00089db8();
void FUN_00246158(Obj *);
void FUN_0024665c();
void FUN_00089d58();
void FUN_00246670(Obj *);
void FUN_0028f0a8();
void FUN_00089ecc();
void FUN_0028f0bc(char *, const char *);
Obj *FUN_000b6f00(void *);
void FUN_000b6f54(Obj *);
Obj *FUN_002c485c(void *);
Obj *FUN_00054130(void *, const char *, int, int, int, int, int);
Obj *FUN_0005e454(void *, const char *, Obj *, const char *, int, int, int, int);
Obj *FUN_00121de8(void *);
Obj *FUN_000df60c(void *);
Obj *FUN_000c7e48(void *);
Court *FUN_0013d738(void *);
void FUN_001c1920(char *, int);
Ball *FUN_0008f594(void *);
Obj *FUN_00097520(void *, int, int, char *);
Obj *FUN_0013a974(void *);
Obj *FUN_001fc610(void *);
void FUN_002bd6a8(Obj *, short);
Obj *FUN_002bd694(void *);
Obj *FUN_000c8b9c(void *);
Obj *FUN_001c2af0(void *);
void FUN_001c40a8(Obj *);
Obj *FUN_0010052c(void *);
Obj *FUN_0012342c(void *);
void FUN_001c3fbc(Obj *);
void FUN_000df7a8(Rules *);
void FUN_00100768(Obj *);
Obj *FUN_00100f4c(Obj *);
void FUN_0020ad2c(Obj *, int);
void FUN_00122c74(Obj *);
Stats *FUN_000c8538(Obj *, int);
void FUN_000429c8(Obj *);
void FUN_000426c0(Obj *, int, int);
void FUN_0008a19c(Scene *, int);
}

extern "C" void FUN_0008a19c(Scene *self, int force)
{
    if (self->state == self->next && force == 0)
        return;

    switch (self->state) {
    case 0:
        FUN_0001f4a0(self, 1, 0, 0);
        break;
    case 1:
        FUN_0001f4a0(self, 3, 0, 0);
        break;
    case 2:
        FUN_0001f4a0(self, 5, 0, 0);
        break;
    case 3:
        FUN_0001f4a0(self, 7, 0, 0);
        break;
    case 4:
        self->m68 = 0;
        FUN_0001f4a0(self, 9, 0, 0);
        break;
    case 5:
        FUN_0001f4a0(self, 11, 0, 0);
        break;
    case 6:
        FUN_0001f4a0(self, 13, 0, 0);
        break;
    case 7:
        FUN_0001f4a0(self, 15, 0, 0);
        break;
    case 8: {
        Hud *hud = DAT_003daec4;
        hud->count = 0;
        hud->shown = 0;
        self->m68 = 0;
        FUN_0001f4a0(self, 17, 0, 0);
        break;
    }
    case 9:
        FUN_0001f4a0(self, 19, 0, 0);
        break;
    }

    self->state = self->next;
    self->m44 = 0;
    self->m48 = 0;
    self->m4c = 0;
    self->m50 = 0;
    if (self->m64 != self->m60)
        self->side ^= 1;
    self->m64 = self->m60;
    self->m54 = 0;

    switch (self->state) {
    case 0: {
        Obj *o;
        Obj *saved;
        Court *court;
        int i;
        char buf[64];

        FUN_00000010(DAT_003782e0);
        o = (Obj *)operator new(0x2c0);
        if (o)
            o = FUN_0005c2f8(o);
        DAT_003e1a54 = o;
        o = (Obj *)operator new(0x2c0);
        if (o)
            o = FUN_0005c2f8(o);
        DAT_003e1a0c = o;
        FUN_0001c5f4(DAT_003b7ebc, DAT_003782e8);

        FUN_00000020(DAT_00378304);
        DAT_003f39e0 = (Obj *)FUN_000008d8(FUN_00000a90(0x34), (void *)FUN_00245e7c, (void *)FUN_00089e18, 0x24, 1);
        FUN_00245ed0(DAT_003f39e0);
        DAT_003f39d8 = (char *)FUN_000008d8(FUN_00000a90(0x70), (void *)FUN_002448f0, (void *)FUN_0024492c, 0x20, 3);
        for (i = 0; i < 3; i++) {
            FUN_000143b0(buf, DAT_00378308, i + 1);
            FUN_002449c4(DAT_003f39d8 + i * 0x20, buf);
        }
        DAT_003f39dc = (char *)FUN_000008d8(FUN_00000a90(0x50), (void *)FUN_002448f0, (void *)FUN_0024492c, 0x20, 2);
        FUN_002449c4(DAT_003f39dc, DAT_00378330);
        FUN_002449c4(DAT_003f39dc + 0x20, DAT_00378358);
        DAT_003f39e4 = (Obj *)FUN_000008d8(FUN_00000a90(0x1c), (void *)FUN_00246144, (void *)FUN_00089db8, 0xc, 1);
        FUN_00246158(DAT_003f39e4);
        DAT_003f39e8 = (Obj *)FUN_000008d8(FUN_00000a90(0x1c), (void *)FUN_0024665c, (void *)FUN_00089d58, 0xc, 1);
        FUN_00246670(DAT_003f39e8);
        FUN_00000028();

        DAT_003f3b18 = (char *)FUN_000008d8(FUN_00000a90(0x28), (void *)FUN_0028f0a8, (void *)FUN_00089ecc, 0xc, 2);
        FUN_0028f0bc(DAT_003f3b18, DAT_00378380);
        FUN_0028f0bc(DAT_003f3b18 + 0xc, DAT_003783a8);

        o = (Obj *)operator new(0x18);
        if (o)
            o = FUN_000b6f00(o);
        DAT_003e1df0 = o;
        FUN_000b6f54(o);

        saved = (Obj *)operator new(0x9a0);
        if (saved)
            saved = FUN_002c485c(saved);

        o = (Obj *)operator new(0x30);
        if (o)
            o = FUN_00054130(o, DAT_003783d0, 0, 0, 0, 0, 0);
        self->fuki = o;
        o = (Obj *)operator new(0x14);
        if (o)
            o = FUN_0005e454(o, DAT_003783f4, self->fuki, DAT_00378418, 0, 0, 0, 0);
        self->fukiAnim = o;
        FUN_0001c73c(DAT_003b7ebc);

        o = (Obj *)operator new(0x530);
        if (o)
            o = FUN_00121de8(o);
        self->m9c = o;
        FUN_0001ef34(self, o);
        o = (Obj *)operator new(0x10c);
        if (o)
            o = FUN_000df60c(o);
        FUN_0001ef34(self, o);
        if (DAT_003e19f8) {
            o = (Obj *)operator new(0x790);
            if (o)
                o = FUN_000c7e48(o);
            FUN_0001ef34(self, o);
        }

        FUN_00000020(DAT_00378430);
        court = (Court *)operator new(0x14c0);
        if (court)
            court = FUN_0013d738(court);
        FUN_0001ef34(self, court);
        FUN_001c1920(DAT_003eaad8, court->ncourts - 1);
        FUN_00000028();

        FUN_00000020(DAT_00378438);
        {
            Ball *b = (Ball *)operator new(0x580);
            if (b)
                b = FUN_0008f594(b);
            self->ball = b;
            FUN_0001ef34(self, (BallTask *)b);
        }
        FUN_00000028();

        FUN_00000020(DAT_00378440);
        o = (Obj *)operator new(0x900);
        if (o)
            o = FUN_00097520(o, 0, 0, DAT_003eab08);
        self->players[0] = o;
        FUN_0001ef34(self, o);
        o = (Obj *)operator new(0x900);
        if (o)
            o = FUN_00097520(o, 1, 1, DAT_003eac28);
        self->players[1] = o;
        FUN_0001ef34(self, o);
        if ((DAT_003e1e84->doubles != 0) ^ 1) {
            o = (Obj *)operator new(0x900);
            if (o)
                o = FUN_00097520(o, 0, 2, DAT_003ead48);
            self->players[2] = o;
            FUN_0001ef34(self, o);
            o = (Obj *)operator new(0x900);
            if (o)
                o = FUN_00097520(o, 1, 3, DAT_003eae68);
            self->players[3] = o;
            FUN_0001ef34(self, o);
        }
        FUN_00000028();

        FUN_0001ef34(self, saved);
        o = (Obj *)operator new(0x140);
        if (o)
            o = FUN_0013a974(o);
        self->m8c = o;
        FUN_0001ef34(self, o);
        {
            Score *s = (Score *)operator new(0x81d0);
            if (s)
                s = (Score *)FUN_001fc610(s);
            self->score = s;
            FUN_0001ef34(self, s);
        }
        if (self->ma4) {
            FUN_002bd6a8(self->ma4, 1);
            self->ma4 = 0;
        }
        o = (Obj *)operator new(4);
        if (o)
            o = FUN_002bd694(o);
        self->ma4 = o;

        FUN_00000020(DAT_00378448);
        o = (Obj *)operator new(0x300);
        if (o)
            o = FUN_000c8b9c(o);
        self->effect = o;
        FUN_0001ef34(self, o);
        FUN_00000028();

        FUN_00000020(DAT_00378450);
        o = (Obj *)operator new(0xfc);
        if (o)
            o = FUN_001c2af0(o);
        self->sound = o;
        FUN_001c40a8(o);
        FUN_00000028();

        FUN_00000020(DAT_00378458);
        o = (Obj *)operator new(0x4c);
        if (o)
            o = FUN_0010052c(o);
        self->inpane = o;
        FUN_0001ef34(self, o);
        FUN_00000028();

        FUN_00000020(DAT_00378460);
        o = (Obj *)operator new(0x31c);
        if (o)
            o = FUN_0012342c(o);
        self->banner = o;
        FUN_0001ef34(self, o);
        FUN_00000028();

        FUN_0001ef34(self, self->sound);
        FUN_0001f4a0(self, 0, 0, 0);
        FUN_00000018();

        if (self->state == 1)
            self->state = 11;
        self->next = 1;
        FUN_001c3fbc(self->sound);
        FUN_000df7a8(DAT_003e1e84);
        FUN_00100768(DAT_003e1f60);
        self->m5a = 0;
        self->m5b = 0;
        FUN_0008a19c(self, 0);
        break;
    }
    case 1:
        FUN_0020ad2c(FUN_00100f4c(DAT_003e1f60), 1);
        FUN_0001f4a0(self, 2, 0, 0);
        break;
    case 2:
        FUN_0001f4a0(self, 4, 0, 0);
        break;
    case 3:
        FUN_0001f4a0(self, 6, 0, 0);
        break;
    case 4:
        if (DAT_003e19f8) {
            self->timer = 300;
            self->m68 = 0;
        }
        FUN_0001f4a0(self, 8, 0, 0);
        break;
    case 5:
        FUN_0001f4a0(self, 10, 0, 0);
        break;
    case 6:
        FUN_0001f4a0(self, 12, 0, 0);
        break;
    case 7:
        if (self->busy)
            DAT_003e95c4->remote->ready = 0;
        FUN_0001f4a0(self, 14, 0, 0);
        if (self->busy)
            FUN_00122c74(self->m9c);
        break;
    case 8:
        if (DAT_003e19f8) {
            self->timer = 450;
            self->m68 = 1;
        }
        FUN_0001f4a0(self, 16, 0, 0);
        break;
    case 9:
        if (DAT_003e1e30)
            self->score->value = FUN_000c8538(DAT_003e1e30, 0)->value;
        FUN_0001f4a0(self, 18, 0, 0);
        break;
    case 10:
        FUN_000429c8(DAT_003ba2c4);
        FUN_000426c0(DAT_003ba2c4, 0x100, 0x80);
        FUN_0001f4a0(self, 24, 0, 0);

        if (self->state == 1)
            self->state = 11;
        self->next = 1;
        FUN_001c3fbc(self->sound);
        FUN_000df7a8(DAT_003e1e84);
        FUN_00100768(DAT_003e1f60);
        self->m5a = 0;
        self->m5b = 0;
        FUN_0008a19c(self, 0);
        break;
    }
    self->busy = 0;
}
