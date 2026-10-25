/* HSTMATCH module=EBOOT.BIN start=0x00194ba4 end=0x00194e20 symbol=FUN_00194ba4 lang=c++ */
struct Slot {
    unsigned short c[4];
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    char padb;
};
struct Head {
    unsigned char f0;
    unsigned char slot;
    unsigned short c4;
    char pad4[4];
};
struct Entry {
    int f0;
    Head head;
    Slot slots[3];
    char pad30[8];
};
struct Db {
    Entry e[15];

    Head *GetHead(int i)
    {
        if (i >= 0 && i < 15)
            return &e[i].head;
        return 0;
    }
    Slot *GetSlot(short i, short k)
    {
        if (i >= 0 && i < 15 && k >= 0 && k < 4)
            return &e[i].slots[k];
        return 0;
    }
};
struct Rec {
    char pad[0xc];
    unsigned char fc;
    unsigned char fd;
    char pade[0x8e];
};
struct RecTable {
    unsigned int count;
    Rec *recs;

    Rec *Get(short i)
    {
        if (i >= 0 && (unsigned int)i < count)
            return &recs[i];
        return 0;
    }
};
struct Modes {
    char pad[0x1025];
    unsigned char mode[15];

    int Get(short i)
    {
        if (i < 0)
            return 1;
        if (i < 15)
            return mode[i];
        return 1;
    }
};
struct Game {
    char pad[0x80];
    Modes modes;
};

struct Desc {
    int id;
    unsigned int c[5];
};

extern Db *DAT_00341ccc;
extern RecTable *DAT_00341744;
extern Game *DAT_003415a8;

extern "C" {
void FUN_00092c38(void *self, int i);
void FUN_00204c88(void *self, unsigned char *a, unsigned char *b, unsigned char *c, Desc *d, int f9, int fa, int two,
                  unsigned char fd, unsigned char fc, int z);
void FUN_00092630(void *self, int f);
}

static inline Rec *GetRec(int i)
{
    RecTable *t = DAT_00341744;
    if (t != 0 && i >= 0 && (unsigned int)i < t->count)
        return &t->recs[i];
    return 0;
}

extern "C" void FUN_00194ba4(void *self, int id, unsigned int flags)
{
    for (int i = 0; i < 6; i++)
        FUN_00092c38(self, i);
    short sid = id;
    unsigned char b79 = 0;
    unsigned char b78 = 0;
    unsigned char b77 = 0;
    Slot *slot = DAT_00341ccc->GetSlot(sid, DAT_00341ccc->GetHead((unsigned short)sid)->slot);
    Rec *rec = GetRec(sid);
    Desc d;
    d.id = sid;
    d.c[0] = 0x7fffffff;
    d.c[1] = 0x7fffffff;
    d.c[2] = 0x7fffffff;
    d.c[3] = 0x7fffffff;
    d.c[4] = 0x7fffffff;
    d.c[0] = slot->c[0];
    d.c[1] = slot->c[1];
    if ((flags & 8) == 0)
        d.c[2] = slot->c[2];
    if ((flags & 0x10) == 0)
        d.c[3] = slot->c[3];
    if ((flags & 0x20) == 0)
        d.c[4] = DAT_00341ccc->GetHead((unsigned short)sid)->c4;
    FUN_00204c88(self, &b78, &b79, &b77, &d, slot->f9 != 0, slot->fa != 0, DAT_003415a8->modes.Get(d.id) == 2,
                 rec->fd, rec->fc, 0);
    FUN_00092630(self, slot->f8 != 0);
}
// NEAR (156/159 words, 107 differ, mostly register naming): structure, getters, stack layout and calls match.
// Left: retail sign-extends the id once into v0 AFTER loading DAT_00341ccc and keeps it live to `d.id`
// (`seh v0,v0` again), re-extends it into t0 for the slot getter and the record lookup (shared), and puts
// the head pointer in a1; ours keeps `short sid` in a2/v0 and the head in v0 (3 fewer seh). Tried: short
// parameter, int parameter with (short) casts at each use, `int sid = (short)id` with short getter params,
// sid declared before/after the byte flags, a hoisted Db* local.
// near miss from lane ol1 (unreviewed)
