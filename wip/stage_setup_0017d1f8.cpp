/* HSTMATCH module=EBOOT.BIN start=0x0017d1f8 end=0x0017d470 symbol=FUN_0017d1f8 lang=c++ */
struct Desc {
    int id;
    unsigned int c[4];
    int handle;
};

struct Api {
    char pad[0x3ec];
    unsigned short *(*GetColor)(int id, int key);
    char pad3f0[0x548 - 0x3f0];
    int (*GetHandle)(int id);
};

struct Item {
    int pad;
    int f4;
};

struct Self {
    int pad0;
    int idx;
    Item **items;
    char padc[0x44];
    int mode;
    int pending;
    char pad58;
    unsigned char ready;
    char pad5a[2];
    char list[0x140];
    int f19c;
    char sprites[0x140];
    int f2e0;

    void SetMode(int m)
    {
        if (mode == m) {
            if (pending != 0)
                pending = 0;
        } else {
            pending = m;
            if (m != 0) {
                mode = m;
                pending = 0;
            }
        }
    }
};

extern int DAT_002c2014[][4];

extern "C" {
void FUN_001fe0f4(int f);
void FUN_001fe1f4(void *list);
Api *FUN_0016bc70();
void FUN_001fe584(void *spr, int key, int last, Desc *d, int f);
void FUN_001fe244(void *list, int a, int key, int first, Desc *d, int b, int c);
void FUN_001fe7b8(void *spr);
void FUN_0017c6d4(Self *self, int f);
void FUN_0017c39c(Self *self, int f);
}

static inline void AddPart(Self *self, int id, int key, bool last, bool first, Desc &d, int handle, int fast)
{
    unsigned short *c = FUN_0016bc70()->GetColor(id, key);
    d.c[0] = c[0];
    d.c[1] = c[1];
    d.c[2] = c[2];
    d.c[3] = c[3];
    d.id = id;
    d.handle = handle;
    FUN_001fe584(self->sprites, key, last, &d, fast);
    FUN_001fe244(self->list, 0, key, first, &d, 1, 0);
}

extern "C" void FUN_0017d1f8(Self *self, int idx, int id, int fast)
{
    FUN_001fe0f4(fast);
    self->idx = idx;
    FUN_001fe1f4(self->list);
    Desc d = {0};
    Api *api = FUN_0016bc70();
    int handle;
    switch (id) {
    default:
        handle = api->GetHandle(id);
        break;
    case 0x7ffe:
    case 0x7fff:
        handle = 0;
        break;
    }
    int *keys = DAT_002c2014[idx];
    for (int i = 0; i < 4; i++)
        AddPart(self, id, keys[i], i == 3, i == 0, d, handle, fast);
    FUN_001fe7b8(self->sprites);
    if (fast == 0)
        self->f19c = 0;
    else
        self->f19c = 3;
    self->items[0]->f4 = 0;
    self->items[1]->f4 = 0;
    self->items[2]->f4 = 0;
    self->items[3]->f4 = 0;
    self->SetMode(1);
    if (fast == 0)
        self->f2e0 = 0;
    else
        self->f2e0 = 3;
    if (fast == 0) {
        for (int i = 0; i < 4; i++) {
            FUN_0017c6d4(self, 1);
            FUN_0017c39c(self, 1);
        }
    }
    self->ready = 1;
}
// NEAR (141/158 words, 156 differ from the frame shift): control flow, calls and field offsets match.
// Left: retail keeps the two loop flags (i == 3 -> s7 via xori/sltiu, i == 0 -> s6 via `xor s6,s2,zero`)
// and the handle (s8) in saved registers computed BEFORE the FUN_0016bc70 call, giving s0-s8 saves and an
// 80-byte frame (Desc at sp+56); ours folds the compares into the call arguments (frame 64). Retail also
// loads the four ushorts before storing them (t0/a3/v1/v0). Tried bool locals at the loop top, an inline
// AddPart helper taking the flags as bool params; the switch form for the 0x7fff/0x7ffe handle test matches.
// near miss from lane ol1 (unreviewed)
