/* HSTMATCH module=EBOOT.BIN start=0x002ab180 end=0x002ab3fc symbol=FUN_002ab180 lang=c++ */
struct Slot {
    char pad[0x10];
    char *f10;
    int f14;
    unsigned char f18;
    unsigned char f19;
    unsigned char f1a;
};

struct Table {
    int count;
    int pad;
    int ent[1];
};

struct Menu {
    char pad0[0x30c5];
    unsigned char f30c5;
    char pad1[0x30e4 - 0x30c6];
    Table *f30e4;
    Table *f30e8;
    char pad2[0x3104 - 0x30ec];
    Slot *slots[4];
    unsigned char f3114;
    char pad4[0x3118 - 0x3115];
    int f3118;
    void *f311c;
    int f3120;
};

extern "C" {
extern float DAT_00302bfc, DAT_00302c00, DAT_00302c04, DAT_00302c08;
extern float DAT_00302c0c, DAT_00302c10, DAT_00302c14, DAT_00302c18;
int FUN_001fe0dc();
void FUN_001fe0f4(int p);
void FUN_00048fc8(void (*cb)());
void FUN_002a7fa8();
void FUN_00059174(void *o);
void FUN_0005f0d8(void *o);
void FUN_002a7b44(Slot *s);
}

static inline void SetSlotA(Menu *m, Table *t)
{
    int tab[4];
    int count = t->count;
    bool big = count > 2;
    *(float *)&tab[0] = DAT_00302bfc;
    *(float *)&tab[1] = DAT_00302c00;
    *(float *)&tab[2] = DAT_00302c04;
    *(float *)&tab[3] = DAT_00302c08;
    int sel = big ? tab[m->f3118] : m->f3118;
    int idx = m->f3118;
    Slot *s = m->slots[idx];
    s->f10 = (char *)&t->ent[sel * 13];
    s->f14 = idx;
    s->f18 = big;
    s->f19 = 1;
    s->f1a = 0;
    FUN_00048fc8(FUN_002a7fa8);
}

static inline void SetSlotB(Menu *m, Table *t, int count, int idx)
{
    int tab[4];
    bool big = count > 2;
    *(float *)&tab[0] = DAT_00302c0c;
    *(float *)&tab[1] = DAT_00302c10;
    *(float *)&tab[2] = DAT_00302c14;
    *(float *)&tab[3] = DAT_00302c18;
    int sel = big ? tab[idx] : idx;
    Slot *s = m->slots[idx];
    s->f10 = (char *)&t->ent[sel * 13];
    s->f14 = idx;
    s->f18 = big;
    s->f19 = 1;
    s->f1a = 0;
    FUN_00048fc8(FUN_002a7fa8);
}

extern "C" void FUN_002ab180(Menu *m)
{
    if (m->f30c5 != 0) {
        int idx;
        if (m->f3114 != 0) {
            if (m->f3120 > 0) {
                m->f3120--;
                if (m->f3120 <= 0) {
                    Table *t = m->f30e4;
                    if (t != 0) {
                        SetSlotA(m, t);
                    }
                }
            } else {
                idx = m->f3118;
                if (m->slots[idx]->f1a != 0) {
                    m->f3118 = ++idx;
                    Table *t = m->f30e4;
                    int count = t->count;
                    if (idx >= count) {
                        m->f3114 = 0;
                        m->f30e8 = m->f30e4;
                    } else {
                        SetSlotB(m, t, count, idx);
                    }
                }
            }
            void *o = m->f311c;
            if (o != 0) {
                FUN_00059174(o);
                FUN_0005f0d8(o);
            }
        }
        for (int i = 0; i < m->f3118; i++) {
            FUN_002a7b44(m->slots[i]);
        }
    } else {
        if (FUN_001fe0dc() == 0) {
            FUN_001fe0f4(1);
        }
        if (m->f3120 > 1) {
            m->f3120 = m->f3120 - 1;
        }
    }
}
// NEAR 12 words, layout identical (159/159): only SetSlotA register colouring differs.
// Retail: Table* in a0, count/big share v1, slot ptr in a1; mine: Table* a1, big a0, slot v1.
// Fixed on the way: `if (idx >= count) {else-arm} else SetSlotB` order, `m->f3118 = ++idx`, for-loop tail, `m->f3120 = m->f3120 - 1`.
// Ruled out for SetSlotA: no count var, count as param, big as param, swapped params, ternary/CSE of t->count > 2, slot declared first, idx local first.
// near miss from lane sn8 (unreviewed)
