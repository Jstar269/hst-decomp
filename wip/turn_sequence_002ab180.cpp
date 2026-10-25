/* HSTMATCH module=EBOOT.BIN start=0x002ab180 end=0x002ab3fc symbol=FUN_002ab180 lang=c++ data=0x00302bfc */
struct Entry {
    int v[13];
};
struct Track {
    int count;
    int pad;
    Entry e[1];
};
struct Player {
    char pad[0x10];
    Entry *entry;
    int idx;
    unsigned char many;
    unsigned char active;
    unsigned char done;
};
struct Anim;

struct Self {
    char pad[0x30c5];
    unsigned char active;
    char pad30c6[0x1e];
    Track *track;
    Track *shown;
    char pad30ec[0x18];
    Player *players[4];
    unsigned char busy;
    char pad3115[3];
    int cur;
    Anim *anim;
    int timer;
};

extern "C" {
int FUN_001fe0dc();
void FUN_001fe0f4(int f);
void FUN_00048fc8(void (*cb)());
void FUN_002a7fa8();
void FUN_00059174(Anim *a);
void FUN_0005f0d8(Anim *a);
void FUN_002a7b44(Player *p);
}

static inline void Start(Self *self, Track *t)
{
    bool many = !(t->count < 3);
    int order[4] = {0, 2, 1, 3};
    int k;
    int i;
    if (many) {
        i = self->cur;
        k = order[i];
    } else {
        i = self->cur;
        k = i;
    }
    Player *p = self->players[i];
    p->entry = &t->e[k];
    p->idx = i;
    p->many = many;
    p->active = 1;
    p->done = 0;
    FUN_00048fc8(FUN_002a7fa8);
}

static inline void StartAt(Self *self, Track *t, int i)
{
    bool many = !(t->count < 3);
    int order[4] = {0, 2, 1, 3};
    int k;
    if (many)
        k = order[i];
    else
        k = i;
    Player *p = self->players[i];
    p->entry = &t->e[k];
    p->idx = i;
    p->many = many;
    p->active = 1;
    p->done = 0;
    FUN_00048fc8(FUN_002a7fa8);
}

extern "C" void FUN_002ab180(Self *self)
{
    if (self->active != 0) {
        if (self->busy != 0) {
            if (self->timer > 0) {
                if (--self->timer <= 0) {
                    Track *t = self->track;
                    if (t != 0)
                        Start(self, t);
                }
            } else if (self->players[self->cur]->done != 0) {
                int c = ++self->cur;
                if (c >= self->track->count) {
                    self->busy = 0;
                    self->shown = self->track;
                } else
                    StartAt(self, self->track, c);
            }
            Anim *a = self->anim;
            if (a != 0) {
                FUN_00059174(a);
                FUN_0005f0d8(a);
            }
        }
        for (int i = 0; i < self->cur; i++)
            FUN_002a7b44(self->players[i]);
    } else {
        if (FUN_001fe0dc() == 0)
            FUN_001fe0f4(1);
        if (self->timer > 1)
            self->timer--;
    }
}
// NEAR (12 words): everything matches except register colouring inside the first (timer) expansion of
// Start: retail track=a0, many=v1, player=a1; ours track=a1, many=a0, player=v1 (the cur++ expansion,
// StartAt, matches exactly). Two separate inlines are needed (each owns an initialiser copy, data 0x302bfc
// and 0x302c0c; the first reads self->cur inside both branches, the second takes the incremented value).
// Tried: all 24 declaration orders of many/k/i/p, many as bool/u8/int/char/uint, Start loading the track
// itself, the null test inside Start, the whole expansion written in place.
// near miss from lane ol1 (unreviewed)
