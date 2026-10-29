/* HSTMATCH module=EBOOT.BIN start=0x00170f08 end=0x00171588 symbol=FUN_00170f08 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Menu/selection state step: loop indices are int compared against unsigned sizes (this keeps MWCC from
   strength-reducing/unrolling the loops, as in retail); twin: src/sharing_main/menu_state_update_0017d1d4.cpp. */

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

enum { POS_NONE = 0x7fffffff };  /* idx/grp value meaning "not found" */
struct Pos {
    unsigned idx;
    unsigned grp;
    Pos(unsigned i, unsigned g) : idx(i), grp(g) {}
    bool IsValid() const { bool r; if (idx != POS_NONE && grp != POS_NONE) r = true; else r = false; return r; }
};

struct SlotObj { virtual ~SlotObj(); };  /* object kept per slot in DAT_0034b340 */

struct NameList { char pad0[4]; int cur; char **names; };  /* names[cur] is the current entry */

struct Sprite { char pad0[0xe]; unsigned short flags; char pad10[0x60 - 0x10]; float x; float y; };
/* Release build: assertions compile to nothing (the Sharing build keeps them, see the twin). */
#define HST_ASSERT(cond, text, file, line) ((void)0)

struct SpriteSet {
    char pad0[0x10];
    Sprite **sprites;
    int count;
    int GetSpriteNum() const { return count; }
    Sprite *GetSprite(int sprite_index)
    {
        HST_ASSERT(sprite_index >= 0 && sprite_index < GetSpriteNum(), "sprite_index >= 0 && sprite_index < GetSpriteNum()", "sprite.h", 1019);
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
    unsigned char entered;
    unsigned char unk3e;
    char pad3f[0x41 - 0x3f];
    unsigned char unk41;
    unsigned char unk42;
    char pad43[0x4d - 0x43];
    unsigned char useSlotObj;
    char pad4e;
    unsigned char unk4f;
    unsigned char unk50;
    char pad51[3];
    int slotIdx;
    int slotIdx2;
    char pad5c[0x64 - 0x5c];
    char unk64[0x74 - 0x64];
    int state;
    char pad78[0x90 - 0x78];
    int unk90;
    char pad94[0x174 - 0x94];
    void *unk174;
    NameList *nameList;
    void *unk17c;
    char pad180[0x2a4 - 0x180];
    char unk2a4[0x514 - 0x2a4];
    char unk514[4];
    Pos pos;
    ItemVec items;
    GroupVec groups;
    void *unk538;
    char pad53c[4];
    int (*getSelectedId)();
    char pad544[0x554 - 0x544];
    void (*setFn)(int);
    int (*getFn)();
    void *unk55c;
    char pad560[0x580 - 0x560];
    int unk580;
};

extern SlotObj *DAT_0034b340[];
extern Screen *DAT_003415ac;
extern int DAT_0034a678;
extern char DAT_0034179c[];

void *operator new(unsigned int);

extern "C" {
void FUN_00170c24(Self *, int);
void FUN_00170d9c(Self *);
bool FUN_0017c344(NameList *);
SlotObj *FUN_00091830(void *);
void FUN_0009191c(SlotObj *, char *);
void FUN_00091c48(SlotObj *, int);
void FUN_00092ff8(SlotObj *);
int FUN_0016b164();
void FUN_0016b6c8(int);
void FUN_0016fab8(Self *, int);
void FUN_0017358c(Self *, int);
void FUN_00170658(Self *, int);
void FUN_00103628(Screen *, int);
void FUN_00187294(void *, int);
void FUN_00187114(void *);
void FUN_0017e8bc(void *, char *);
void FUN_001733d0(Self *, void *, int);
bool FUN_0016bf78(int);
void FUN_0016bdc4(int);
void FUN_001b3ea4(void *, float);
void FUN_001fe0f4(int);
}

/* Total number of items over all groups. */
static inline int CountItems(Self *s)
{
    int n = 0;
    for (int g = 0; g < s->groups.size; g++)
        n += s->groups[g].Size();
    return n;
}

/* Position (item index, group index) of the item with this id, POS_NONE when absent. */
static inline Pos FindPos(Self *s, int id)
{
    unsigned idx = POS_NONE, grp = POS_NONE;
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

/* Unit scale, centred on the 480x272 screen. */
static inline void ResetScreen()
{
    if (DAT_003415ac) {
        DAT_003415ac->SetScale(1.0f);
        DAT_003415ac->SetPos(240.0f, 136.0f);
    }
}

static inline void ShowScreen(Self *self)
{
    if (DAT_003415ac && (DAT_003415ac->set->GetSprite(0)->flags & 3) == 0) {
        FUN_00103628(DAT_003415ac, 1);
        ResetScreen();
        FUN_00187294(self->unk174, 1);
    }
}

/* Per-frame step of the selection menu: enters the selected state once, otherwise routes to the next state. */
extern "C" void FUN_00170f08(Self *self)
{
    bool b = false;
    if (self->unk3e && !self->entered)
        b = true;
    if (b) {
        FUN_00170c24(self, 1);
        int idx = self->slotIdx;
        if (self->useSlotObj) {
            if (FUN_0017c344(self->nameList) == 0) {
                SlotObj **pp = &DAT_0034b340[idx];
                if (*pp) {
                    delete *pp;
                    *pp = 0;
                }
            } else {
                SlotObj **pp = &DAT_0034b340[idx];
                if (*pp == 0) {
                    SlotObj *mem = (SlotObj *)operator new(0xe0);
                    if (mem)
                        mem = FUN_00091830(mem);
                    *pp = mem;
                }
                FUN_0009191c(*pp, self->nameList->names[self->nameList->cur] + 0x10);
                FUN_00091c48(*pp, 0);
                FUN_00092ff8(*pp);
            }
        }
        self->state = 10;
        int cur = self->getSelectedId();
        for (int i = 0; i < CountItems(self); i++) {
            Item *it = self->items[i];
            if (it->id == cur)
                it->selected = 1;
            else
                it->selected = 0;
        }
        int before = FUN_0016b164();
        FUN_0016fab8(self, self->getSelectedId());
        Pos q = FindPos(self, FUN_0016b164());
        if (!q.IsValid()) {
            FUN_0016b6c8(0);
            FUN_0016fab8(self, self->getSelectedId());
        }
        if (before != FUN_0016b164() && self->unk50) {
            self->unk50 = 0;
            if (DAT_0034b340[self->slotIdx2]) {
                delete DAT_0034b340[self->slotIdx2];
                DAT_0034b340[self->slotIdx2] = 0;
            }
        }
        Pos p = FindPos(self, FUN_0016b164());
        if (p.idx != POS_NONE && p.grp != POS_NONE)
            self->pos = p;
        if (self->unk50) {
            self->unk4f = 1;
            self->unk50 = 0;
        }
        self->entered = 1;
        self->unk538 = self->unk514;
        self->setFn = FUN_0016b6c8;
        self->getFn = FUN_0016b164;
        self->unk55c = self->unk64;
        FUN_0017358c(self, self->getFn());
        FUN_00170658(self, self->getFn());
        if (self->getFn() == 0x7fff)
            ShowScreen(self);
        else
            ShowScreen(self);
        FUN_00187114(self->unk174);
        FUN_0017e8bc(self->unk17c, self->unk2a4);
        void *m = self->unk538;
        FUN_001733d0(self, m, self->getFn());
    } else {
        if (self->unk3e && self->entered)
            FUN_00170d9c(self);
        else
            FUN_00170c24(self, 0);
        if (self->unk41) {
            self->state = 0x1d;
            self->unk90 = 2;
        } else if (self->unk42) {
            self->state = 0x20;
            self->unk580 = 0;
        } else {
            self->state = 0x25;
            FUN_0016bdc4(0x25);
            if (FUN_0016bf78(0) != 0)
                FUN_001b3ea4(DAT_0034179c, 1.0f / 3.0f);
            else if (DAT_0034a678 == 3)
                FUN_001b3ea4(DAT_0034179c, 1.0f / 3.0f);
            FUN_001fe0f4(1);
            FUN_00103628(DAT_003415ac, 1);
        }
    }
}
