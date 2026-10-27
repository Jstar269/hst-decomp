/* HSTMATCH module=EBOOT.BIN start=0x000c7928 end=0x000c7cd0 symbol=FUN_000c7928 lang=c++ data=0x002d5f4c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (10 strings, 0x002d5f4c-0x002d6125) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Effect;
struct Anim;

struct Banner {
    virtual void v0();
    virtual void v1();
    virtual void Load(const char *path, const char *name, int a, int b, int c, int d);
};

extern "C" {
void *FUN_00000bcc(unsigned);
Banner *FUN_00056b98(void *);
void FUN_000573a0(Banner *, int, const char *, int, int);
Effect *FUN_000535d8(void *);
Anim *FUN_00055dd0(void *);
void FUN_000537bc(Effect *, const char *, const char *, int, int, int, int);
void FUN_00055eac(Anim *, const char *, int);
}

struct Sprite {
    virtual void v0();
    virtual void SetEffect(Effect *);
    char pad[0xc0 - 4];
    unsigned char visible;
    char padc1[3];
    float alpha;
    char padc8[0xd0 - 0xc8];
    float alpha2;
    char padd4[0x1b0 - 0xd4];
};

extern "C" {
void FUN_0005743c(Sprite *, int, Anim *, int);
void FUN_00057b58(Sprite *, float, int, int);
void FUN_00058ec4(float, Sprite *, int);
void FUN_00058ddc(Sprite *, int, int);
void FUN_00059084(Sprite *, int);
}

struct Player;
struct Ctx {
    char pad0[0x70];
    Player *players[4];
};

struct Game {
    char pad[0x1364];
    int court;
};

struct Self {
    char pad0[0x1c0];
    Banner *piyori;
    char pad1c4[0x1d0 - 0x1c4];
    Sprite *prints;
    unsigned char *flags;
    Effect *effect;
    Anim *anim;
};

extern Ctx *DAT_003386b0;
extern Game *DAT_003402a0;

extern "C" void FUN_000c7928(Self *self)
{
    if (self->piyori == 0) {
        Banner *b = (Banner *)FUN_00000bcc(0x1b0);
        if (b)
            b = FUN_00056b98(b);
        self->piyori = b;
    }
    self->piyori->Load("data/menu/game_eff/piyori/eff_piyori.i3r", "data/menu/game_eff/piyori/", 0, 0, 0, 0);
    FUN_000573a0(self->piyori, 0, "data/menu/game_eff/piyori/eff_piyori.i3m", 0, 0);
    if (self->effect == 0) {
        Effect *e = (Effect *)FUN_00000bcc(0x30);
        if (e)
            e = FUN_000535d8(e);
        self->effect = e;
    }
    if (self->anim == 0) {
        Anim *a = (Anim *)FUN_00000bcc(0x10);
        if (a)
            a = FUN_00055dd0(a);
        self->anim = a;
    }
    int court = DAT_003402a0->court;
    if (court == 3 || court == 5 || court == 9 || court == 13 || court == 15) {
        FUN_000537bc(self->effect, "data/menu/game_eff/footprint/eff_tobitsuki_zuza.i3r", "data/menu/game_eff/footprint/", 0, 0, 0, 0);
        FUN_00055eac(self->anim, "data/menu/game_eff/footprint/eff_tobitsuki_zuza.i3m", 0);
    } else if (court == 2 || court == 4 || court == 7 || court == 16 || court == 17 || court == 20) {
        FUN_000537bc(self->effect, "data/menu/game_eff/footprint/eff_tobitsuki_zuza2.i3r", "data/menu/game_eff/footprint/", 0, 0, 0, 0);
        FUN_00055eac(self->anim, "data/menu/game_eff/footprint/eff_tobitsuki_zuza2.i3m", 0);
    } else if (court == 1 || court == 6 || court == 14 || court == 18) {
        FUN_000537bc(self->effect, "data/menu/game_eff/footprint/eff_tobitsuki_zuza3.i3r", "data/menu/game_eff/footprint/", 0, 0, 0, 0);
        FUN_00055eac(self->anim, "data/menu/game_eff/footprint/eff_tobitsuki_zuza3.i3m", 0);
    } else {
        FUN_000537bc(self->effect, "data/menu/game_eff/footprint/eff_tobitsuki_zuza.i3r", "data/menu/game_eff/footprint/", 0, 0, 0, 0);
        FUN_00055eac(self->anim, "data/menu/game_eff/footprint/eff_tobitsuki_zuza.i3m", 0);
    }
    for (int i = 0; i < 4; i++) {
        self->flags[i] = 0;
        if (DAT_003386b0->players[i]) {
            self->prints[i].SetEffect(self->effect);
            FUN_0005743c(&self->prints[i], 0, self->anim, 0);
            FUN_00057b58(&self->prints[i], 0.0f, 0, 0);
            Sprite *s = &self->prints[i];
            FUN_00058ec4(1.0f, s, -1);
            s->alpha = 1.0f;
            s = &self->prints[i];
            FUN_00058ddc(s, 1, -1);
            s->visible = 1;
            s = &self->prints[i];
            FUN_00059084(s, -1);
            s->alpha2 = s->alpha;
        }
    }
}
