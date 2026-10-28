/* HSTMATCH module=EBOOT.BIN start=0x00088a44 end=0x00089648 symbol=FUN_00088a44 lang=c++ rodata=0x002be804 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/scene.h"

enum {
    NUM_AI_PARAM_FILES = 3,  /* AI_Param_1..3.csv */
    TIMER_STATE4 = 300,      /* timer preset when entering state 4 */
    TIMER_STATE8 = 450,      /* timer preset when entering state 8 */
    WAIT_USEC = 1000000      /* poll interval of the load wait loop */
};

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


extern Hud *DAT_00331b84;
extern Obj *DAT_00338714;
extern Obj *DAT_003386cc;
extern Obj *DAT_0034a6b0;
extern char *DAT_0034a6a8;
extern char *DAT_0034a6ac;
extern Obj *DAT_0034a6b4;
extern Obj *DAT_0034a6b8;
extern char *DAT_0034a7e8;
extern Obj *DAT_00338ab0;
extern unsigned char DAT_003386b8;
extern char DAT_0030ebf4[];
extern char DAT_0034179c[];
extern char DAT_003417d0[];
extern char DAT_003418f0[];
extern char DAT_00341a10[];
extern char DAT_00341b30[];
extern Rules *DAT_00338b44;
extern Obj *DAT_00338c20;
extern Net *DAT_00340284;
extern Obj *DAT_00338af0;
extern Obj *DAT_00310fc4;

extern const char DAT_002d223c[];   /* "Game" */
extern const char DAT_002d2244[];   /* "game/100_common/common.xb" */
extern const char DAT_002d2260[];   /* "AI" */
extern const char DAT_002d2264[];   /* "data/common/parameter/AI_Param_%d.csv" */
extern const char DAT_002d228c[];   /* "data/common/parameter/AI_param_PC.csv" */
extern const char DAT_002d22b4[];   /* "data/common/parameter/AI_param_NPC.csv" */
extern const char DAT_002d22dc[];   /* "data/chara/parameter/PCGut_PcGut.txt" */
extern const char DAT_002d2304[];   /* "data/chara/parameter/PCGut_NpcGut.txt" */
extern const char DAT_002d232c[];   /* "data/common/ase_fuki/ase_fuki.i3r" */
extern const char DAT_002d2350[];   /* "data/common/ase_fuki/ase_fuki.tat" */
extern const char DAT_002d2374[];   /* "data/common/ase_fuki/" */
extern const char DAT_002d238c[];   /* "Court" */
extern const char DAT_002d2394[];   /* "Ball" */
extern const char DAT_002d239c[];   /* "Player" */
extern const char DAT_002d23a4[];   /* "Effect" */
extern const char DAT_002d23ac[];   /* "Sound" */
extern const char DAT_002d23b4[];   /* "Inpane" */
extern const char DAT_002d23bc[];   /* "Banner" */

void *operator new(unsigned int);

extern "C" {
void FUN_0001f558(Scene *, int, int, int);
void FUN_0001f21c(Scene *, void *);
void FUN_00000010(const char *);
void FUN_00000018();
void FUN_00000020(const char *);
void FUN_00000028();
void FUN_00088128();
void FUN_00048fc8(void (*)(), int);
void *FUN_00000a90(unsigned int);
void *FUN_000008d8(void *, void *, void *, unsigned int, unsigned int);
void FUN_0001ca58(char *, const char *, ...);
void FUN_0001cb88(char *);
int FUN_000143b0(char *, const char *, ...);
Obj *FUN_0005b670(void *);
void FUN_00235d50();
void FUN_000886c0();
void FUN_00235da4(Obj *);
void FUN_002347c4();
void FUN_00234800();
void FUN_00234898(char *, const char *);
void FUN_00235fe0();
void FUN_00088660();
void FUN_00235ff4(Obj *);
void FUN_002364f8();
void FUN_00088600();
void FUN_0023650c(Obj *);
void FUN_0027dcd8();
void FUN_00088774();
void FUN_0027dcec(char *, const char *);
Obj *FUN_000b3ca0(void *);
void FUN_000b3cf4(Obj *);
Obj *FUN_002b4d9c(void *);
Obj *FUN_00053670(void *, const char *, int, int, int, int, int);
Obj *FUN_0005d638(void *, const char *, Obj *, const char *, int, int, int, int);
Obj *FUN_00116ecc(void *);
Obj *FUN_000db64c(void *);
Obj *FUN_000c45e0(void *);
Court *FUN_00132180(void *);
void FUN_001b3538(char *, int);
Ball *FUN_0008dd24(void *);
Obj *FUN_0009547c(void *, int, int, char *);
Obj *FUN_0012f41c(void *);
Obj *FUN_001ee248(void *);
void FUN_002ade80(Obj *, short);
Obj *FUN_002ade6c(void *);
Obj *FUN_000c5118(void *);
Obj *FUN_001b4edc(void *);
void FUN_001b63e8(Obj *);
Obj *FUN_000fadf0(void *);
Obj *FUN_00118258(void *);
void FUN_001b62fc(Obj *);
void FUN_000db788(Rules *);
void FUN_000fb02c(Obj *);
int FUN_00049094(int);
void FUN_002b7958(int);
Obj *FUN_000fb810(Obj *);
void FUN_001fc614(Obj *, int);
void FUN_00117c24(Obj *);
Stats *FUN_000c4ba0(Obj *, int);
void FUN_000429a0(Obj *);
void FUN_00042698(Obj *, int, int);
void FUN_00088a44(Scene *, int);
}

extern "C" void FUN_00088a44(Scene *self, int force)
{
    if (self->state == self->next && force == 0)
        return;

    switch (self->state) {
    case 0:
        FUN_0001f558(self, 1, 0, 0);
        break;
    case 1:
        FUN_0001f558(self, 3, 0, 0);
        break;
    case 2:
        FUN_0001f558(self, 5, 0, 0);
        break;
    case 3:
        FUN_0001f558(self, 7, 0, 0);
        break;
    case 4:
        self->unk68 = 0;
        FUN_0001f558(self, 9, 0, 0);
        break;
    case 5:
        FUN_0001f558(self, 11, 0, 0);
        break;
    case 6:
        FUN_0001f558(self, 13, 0, 0);
        break;
    case 7:
        FUN_0001f558(self, 15, 0, 0);
        break;
    case 8: {
        Hud *hud = DAT_00331b84;
        hud->count = 0;
        hud->shown = 0;
        self->unk68 = 0;
        FUN_0001f558(self, 17, 0, 0);
        break;
    }
    case 9:
        FUN_0001f558(self, 19, 0, 0);
        break;
    }

    self->state = self->next;
    self->unk44 = 0;
    self->unk48 = 0;
    self->unk4c = 0;
    self->unk50 = 0;
    if (self->unk64 != self->unk60)
        self->side ^= 1;
    self->unk64 = self->unk60;
    self->unk54 = 0;

    switch (self->state) {
    case 0: {
        Obj *o;
        Obj *deferred;      /* constructed early, attached to the scene after the players */
        Court *court;
        int i;
        char buf[64];

        FUN_00000010(DAT_002d223c);
        FUN_00048fc8(FUN_00088128, 0);
        o = (Obj *)operator new(0x2c0);
        if (o)
            o = FUN_0005b670(o);
        DAT_00338714 = o;
        o = (Obj *)operator new(0x2c0);
        if (o)
            o = FUN_0005b670(o);
        DAT_003386cc = o;
        FUN_0001ca58(DAT_0030ebf4, DAT_002d2244);

        FUN_00000020(DAT_002d2260);
        DAT_0034a6b0 = (Obj *)FUN_000008d8(FUN_00000a90(0x34), (void *)FUN_00235d50, (void *)FUN_000886c0, 0x24, 1);
        FUN_00235da4(DAT_0034a6b0);
        DAT_0034a6a8 = (char *)FUN_000008d8(FUN_00000a90(0x70), (void *)FUN_002347c4, (void *)FUN_00234800, 0x20, 3);
        for (i = 0; i < NUM_AI_PARAM_FILES; i++) {
            FUN_000143b0(buf, DAT_002d2264, i + 1);
            FUN_00234898(DAT_0034a6a8 + i * 0x20, buf);
        }
        DAT_0034a6ac = (char *)FUN_000008d8(FUN_00000a90(0x50), (void *)FUN_002347c4, (void *)FUN_00234800, 0x20, 2);
        FUN_00234898(DAT_0034a6ac, DAT_002d228c);
        FUN_00234898(DAT_0034a6ac + 0x20, DAT_002d22b4);
        DAT_0034a6b4 = (Obj *)FUN_000008d8(FUN_00000a90(0x1c), (void *)FUN_00235fe0, (void *)FUN_00088660, 0xc, 1);
        FUN_00235ff4(DAT_0034a6b4);
        DAT_0034a6b8 = (Obj *)FUN_000008d8(FUN_00000a90(0x1c), (void *)FUN_002364f8, (void *)FUN_00088600, 0xc, 1);
        FUN_0023650c(DAT_0034a6b8);
        FUN_00000028();

        DAT_0034a7e8 = (char *)FUN_000008d8(FUN_00000a90(0x28), (void *)FUN_0027dcd8, (void *)FUN_00088774, 0xc, 2);
        FUN_0027dcec(DAT_0034a7e8, DAT_002d22dc);
        FUN_0027dcec(DAT_0034a7e8 + 0xc, DAT_002d2304);

        o = (Obj *)operator new(0x18);
        if (o)
            o = FUN_000b3ca0(o);
        DAT_00338ab0 = o;
        FUN_000b3cf4(o);

        deferred = (Obj *)operator new(0x9a0);
        if (deferred)
            deferred = FUN_002b4d9c(deferred);

        o = (Obj *)operator new(0x30);
        if (o)
            o = FUN_00053670(o, DAT_002d232c, 0, 0, 0, 0, 0);
        self->fuki = o;
        o = (Obj *)operator new(0x14);
        if (o)
            o = FUN_0005d638(o, DAT_002d2350, self->fuki, DAT_002d2374, 0, 0, 0, 0);
        self->fukiAnim = o;
        FUN_0001cb88(DAT_0030ebf4);

        o = (Obj *)operator new(0x530);
        if (o)
            o = FUN_00116ecc(o);
        self->unk9c = o;
        FUN_0001f21c(self, o);
        o = (Obj *)operator new(0x10c);
        if (o)
            o = FUN_000db64c(o);
        FUN_0001f21c(self, o);
        if (DAT_003386b8) {
            o = (Obj *)operator new(0x790);
            if (o)
                o = FUN_000c45e0(o);
            FUN_0001f21c(self, o);
        }

        FUN_00000020(DAT_002d238c);
        court = (Court *)operator new(0x14c0);
        if (court)
            court = FUN_00132180(court);
        FUN_0001f21c(self, court);
        FUN_001b3538(DAT_0034179c, court->ncourts - 1);
        FUN_00000028();

        FUN_00000020(DAT_002d2394);
        {
            Ball *b = (Ball *)operator new(0x580);
            if (b)
                b = FUN_0008dd24(b);
            self->ball = b;
            FUN_0001f21c(self, (BallTask *)b);
        }
        FUN_00000028();

        FUN_00000020(DAT_002d239c);
        o = (Obj *)operator new(0x900);
        if (o)
            o = FUN_0009547c(o, 0, 0, DAT_003417d0);
        self->players[0] = o;
        FUN_0001f21c(self, o);
        o = (Obj *)operator new(0x900);
        if (o)
            o = FUN_0009547c(o, 1, 1, DAT_003418f0);
        self->players[1] = o;
        FUN_0001f21c(self, o);
        if ((DAT_00338b44->doubles != 0) ^ 1) {
            o = (Obj *)operator new(0x900);
            if (o)
                o = FUN_0009547c(o, 0, 2, DAT_00341a10);
            self->players[2] = o;
            FUN_0001f21c(self, o);
            o = (Obj *)operator new(0x900);
            if (o)
                o = FUN_0009547c(o, 1, 3, DAT_00341b30);
            self->players[3] = o;
            FUN_0001f21c(self, o);
        }
        FUN_00000028();

        FUN_0001f21c(self, deferred);
        o = (Obj *)operator new(0x140);
        if (o)
            o = FUN_0012f41c(o);
        self->unk8c = o;
        FUN_0001f21c(self, o);
        {
            Score *s = (Score *)operator new(0x81d0);
            if (s)
                s = (Score *)FUN_001ee248(s);
            self->score = s;
            FUN_0001f21c(self, s);
        }
        if (self->unka4) {
            FUN_002ade80(self->unka4, 1);
            self->unka4 = 0;
        }
        o = (Obj *)operator new(4);
        if (o)
            o = FUN_002ade6c(o);
        self->unka4 = o;

        FUN_00000020(DAT_002d23a4);
        o = (Obj *)operator new(0x300);
        if (o)
            o = FUN_000c5118(o);
        self->effect = o;
        FUN_0001f21c(self, o);
        FUN_00000028();

        FUN_00000020(DAT_002d23ac);
        o = (Obj *)operator new(0xfc);
        if (o)
            o = FUN_001b4edc(o);
        self->sound = o;
        FUN_001b63e8(o);
        FUN_00000028();

        FUN_00000020(DAT_002d23b4);
        o = (Obj *)operator new(0x4c);
        if (o)
            o = FUN_000fadf0(o);
        self->inpane = o;
        FUN_0001f21c(self, o);
        FUN_00000028();

        FUN_00000020(DAT_002d23bc);
        o = (Obj *)operator new(0x31c);
        if (o)
            o = FUN_00118258(o);
        self->banner = o;
        FUN_0001f21c(self, o);
        FUN_00000028();

        FUN_0001f21c(self, self->sound);
        FUN_0001f558(self, 0, 0, 0);
        FUN_00000018();

        if (self->state == 1)
            self->state = 11;
        self->next = 1;
        FUN_001b62fc(self->sound);
        FUN_000db788(DAT_00338b44);
        FUN_000fb02c(DAT_00338c20);
        self->unk5a = 0;
        self->unk5b = 0;
        FUN_00088a44(self, 0);
        while (!FUN_00049094(0))
            FUN_002b7958(WAIT_USEC);
        break;
    }
    case 1:
        FUN_001fc614(FUN_000fb810(DAT_00338c20), 1);
        FUN_0001f558(self, 2, 0, 0);
        break;
    case 2:
        FUN_0001f558(self, 4, 0, 0);
        break;
    case 3:
        FUN_0001f558(self, 6, 0, 0);
        break;
    case 4:
        if (DAT_003386b8) {
            self->timer = TIMER_STATE4;
            self->unk68 = 0;
        }
        FUN_0001f558(self, 8, 0, 0);
        break;
    case 5:
        FUN_0001f558(self, 10, 0, 0);
        break;
    case 6:
        FUN_0001f558(self, 12, 0, 0);
        break;
    case 7:
        if (self->busy)
            DAT_00340284->remote->ready = 0;
        FUN_0001f558(self, 14, 0, 0);
        if (self->busy)
            FUN_00117c24(self->unk9c);
        break;
    case 8:
        if (DAT_003386b8) {
            self->timer = TIMER_STATE8;
            self->unk68 = 1;
        }
        FUN_0001f558(self, 16, 0, 0);
        break;
    case 9:
        if (DAT_00338af0)
            self->score->value = FUN_000c4ba0(DAT_00338af0, 0)->value;
        FUN_0001f558(self, 18, 0, 0);
        break;
    case 10:
        FUN_00048fc8(FUN_00088128, 0);
        FUN_000429a0(DAT_00310fc4);
        FUN_00042698(DAT_00310fc4, 0x100, 0x80);
        FUN_0001f558(self, 24, 0, 0);

        if (self->state == 1)
            self->state = 11;
        self->next = 1;
        FUN_001b62fc(self->sound);
        FUN_000db788(DAT_00338b44);
        FUN_000fb02c(DAT_00338c20);
        self->unk5a = 0;
        self->unk5b = 0;
        FUN_00088a44(self, 0);
        while (!FUN_00049094(0))
            FUN_002b7958(WAIT_USEC);
        break;
    }
    self->busy = 0;
}
