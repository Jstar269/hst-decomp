/* HSTMATCH module=hstp_trans_main.prx start=0x0017d1d4 end=0x0017d8b4 symbol=FUN_0017d1d4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Debug-build twin of src/eboot/menu_state_update_00170f08.cpp: same source, the sprite.h GetSprite() assertion
   (line 1019) is kept here. */

struct Item { int id; char pad4[7]; unsigned char selected; };

struct ItemVec {
    Item **data;
    unsigned size;
    unsigned cap;
    unsigned Size() const { return size; }
    Item *&operator[](unsigned i) { return data[i]; }
};

struct GroupVec {
    ItemVec *data;
    unsigned size;
    unsigned cap;
    unsigned Size() const { return size; }
    ItemVec &operator[](unsigned i) { return data[i]; }
};

struct Pos {
    unsigned idx;
    unsigned grp;
    Pos(unsigned i, unsigned g) : idx(i), grp(g) {}
    bool IsValid() const { bool r; if (idx != 0x7fffffff && grp != 0x7fffffff) r = true; else r = false; return r; }
};

struct Obj { virtual ~Obj(); };

struct Track { char pad0[4]; int cur; char **names; };

struct Sprite { char pad0[0xe]; unsigned short flags; char pad10[0x60 - 0x10]; float x; float y; };
extern "C" void FUN_00177f38(...);
extern const char DAT_002d0090[];   /* "assertion \"%s\" failed: file \"%s\", line %d
" */
extern const char DAT_002d005c[];   /* "sprite_index >= 0 && sprite_index < GetSpriteNum()" */
extern const char DAT_002d0050[];   /* "sprite.h" */
#define HST_ASSERT(cond, text, file, line) do { if (!(cond)) { FUN_00177f38(DAT_002d0090, text, file, line); for (;;) {} } } while (0)

struct SpriteSet {
    char pad0[0x10];
    Sprite **sprites;
    int count;
    int GetSpriteNum() const { return count; }
    Sprite *GetSprite(int sprite_index)
    {
        HST_ASSERT(sprite_index >= 0 && sprite_index < GetSpriteNum(), DAT_002d005c, DAT_002d0050, 1019);
        return sprites[sprite_index];
    }
};
struct Screen {
    char pad0[4];
    Sprite **sprites;
    char pad8[0x54 - 8];
    SpriteSet *set;
    char pad58[0x74 - 0x58];
    float sx;
    float sy;
    void SetScale(float s) { sx = s; sy = s; }
    void SetPos(float x, float y) { sprites[0]->x = x; sprites[0]->y = y; }
};

struct Self {
    char pad0[0x3d];
    unsigned char m3d;
    unsigned char m3e;
    char pad3f[0x41 - 0x3f];
    unsigned char m41;
    unsigned char m42;
    char pad43[0x4d - 0x43];
    unsigned char m4d;
    char pad4e;
    unsigned char m4f;
    unsigned char m50;
    char pad51[3];
    int m54;
    int m58;
    char pad5c[0x64 - 0x5c];
    char m64[0x74 - 0x64];
    int state;
    char pad78[0x90 - 0x78];
    int m90;
    char pad94[0x174 - 0x94];
    void *m174;
    Track *m178;
    void *m17c;
    char pad180[0x2a4 - 0x180];
    char m2a4[0x514 - 0x2a4];
    char m514[4];
    Pos pos;
    ItemVec items;
    GroupVec groups;
    void *m538;
    char pad53c[4];
    int (*m540)();
    char pad544[0x554 - 0x544];
    void (*m554)(int);
    int (*m558)();
    void *m55c;
    char pad560[0x580 - 0x560];
    int m580;
};

extern Obj *DAT_003f468c[];
extern Screen *DAT_003ea8ec;
extern int DAT_003f39a8;
extern char DAT_003eaad8[];

void *operator new(unsigned int);

extern "C" {
void FUN_0017cef0(Self *, int);
void FUN_0017d068(Self *);
bool FUN_00188a38(Track *);
Obj *FUN_000934c8(void *);
void FUN_000935b4(Obj *, char *);
void FUN_000938e0(Obj *, int);
void FUN_00094e8c(Obj *);
int FUN_00177328();
void FUN_0017788c(int);
void FUN_0017bd04(Self *, int);
void FUN_0017f918(Self *, int);
void FUN_0017c8a4(Self *, int);
void FUN_00108f54(Screen *, int);
void FUN_001939e0(void *, int);
void FUN_00193860(void *);
void FUN_0018afb0(void *, char *);
void FUN_0017f75c(Self *, void *, int);
bool FUN_001781f0(int);
void FUN_0017803c(int);
void FUN_001c2130(void *, float);
void FUN_0020c8c4(int);
}

static inline int CountItems(Self *s)
{
    int n = 0;
    for (int g = 0; g < s->groups.size; g++)
        n += s->groups[g].Size();
    return n;
}

static inline Pos FindPos(Self *s, int id)
{
    unsigned idx = 0x7fffffff, grp = 0x7fffffff;
    for (int g = 0; g < s->groups.Size(); g++) {
        for (int i = 0; i < s->groups[g].Size(); i++) {
            if (s->groups[g][i]->id == id) {
                idx = i;
                grp = g;
                goto done;
            }
        }
    }
done:
    return Pos(idx, grp);
}

static inline void ResetScreen()
{
    if (DAT_003ea8ec) {
        DAT_003ea8ec->SetScale(1.0f);
        DAT_003ea8ec->SetPos(240.0f, 136.0f);
    }
}

static inline void ShowScreen(Self *self)
{
    if (DAT_003ea8ec && (DAT_003ea8ec->set->GetSprite(0)->flags & 3) == 0) {
        FUN_00108f54(DAT_003ea8ec, 1);
        ResetScreen();
        FUN_001939e0(self->m174, 1);
    }
}

extern "C" void FUN_0017d1d4(Self *self)
{
    bool b = false;
    if (self->m3e && !self->m3d)
        b = true;
    if (b) {
        FUN_0017cef0(self, 1);
        int idx = self->m54;
        if (self->m4d) {
            if (FUN_00188a38(self->m178) == 0) {
                Obj **pp = &DAT_003f468c[idx];
                if (*pp) {
                    delete *pp;
                    *pp = 0;
                }
            } else {
                Obj **pp = &DAT_003f468c[idx];
                if (*pp == 0) {
                    Obj *mem = (Obj *)operator new(0xe0);
                    if (mem)
                        mem = FUN_000934c8(mem);
                    *pp = mem;
                }
                FUN_000935b4(*pp, self->m178->names[self->m178->cur] + 0x10);
                FUN_000938e0(*pp, 0);
                FUN_00094e8c(*pp);
            }
        }
        self->state = 10;
        int cur = self->m540();
        for (int i = 0; i < CountItems(self); i++) {
            Item *it = self->items[i];
            if (it->id == cur)
                it->selected = 1;
            else
                it->selected = 0;
        }
        int before = FUN_00177328();
        FUN_0017bd04(self, self->m540());
        Pos q = FindPos(self, FUN_00177328());
        if (!q.IsValid()) {
            FUN_0017788c(0);
            FUN_0017bd04(self, self->m540());
        }
        if (before != FUN_00177328() && self->m50) {
            self->m50 = 0;
            if (DAT_003f468c[self->m58]) {
                delete DAT_003f468c[self->m58];
                DAT_003f468c[self->m58] = 0;
            }
        }
        Pos p = FindPos(self, FUN_00177328());
        if (p.idx != 0x7fffffff && p.grp != 0x7fffffff)
            self->pos = p;
        if (self->m50) {
            self->m4f = 1;
            self->m50 = 0;
        }
        self->m3d = 1;
        self->m538 = self->m514;
        self->m554 = FUN_0017788c;
        self->m558 = FUN_00177328;
        self->m55c = self->m64;
        FUN_0017f918(self, self->m558());
        FUN_0017c8a4(self, self->m558());
        if (self->m558() == 0x7fff)
            ShowScreen(self);
        else
            ShowScreen(self);
        FUN_00193860(self->m174);
        FUN_0018afb0(self->m17c, self->m2a4);
        void *m = self->m538;
        FUN_0017f75c(self, m, self->m558());
    } else {
        if (self->m3e && self->m3d)
            FUN_0017d068(self);
        else
            FUN_0017cef0(self, 0);
        if (self->m41) {
            self->state = 0x1d;
            self->m90 = 2;
        } else if (self->m42) {
            self->state = 0x20;
            self->m580 = 0;
        } else {
            self->state = 0x25;
            FUN_0017803c(0x25);
            if (FUN_001781f0(0) != 0)
                FUN_001c2130(DAT_003eaad8, 1.0f / 3.0f);
            else if (DAT_003f39a8 == 3)
                FUN_001c2130(DAT_003eaad8, 1.0f / 3.0f);
            FUN_0020c8c4(1);
            FUN_00108f54(DAT_003ea8ec, 1);
        }
    }
}
