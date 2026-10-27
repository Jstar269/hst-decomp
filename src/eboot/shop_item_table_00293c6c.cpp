/* HSTMATCH module=EBOOT.BIN start=0x00293c6c end=0x00293fcc symbol=FUN_00293c6c lang=c++ data=0x002ffbe8 */
/* ShopItemTable_Build: data/menu/shop/Item.csv; see docs/DATA-TABLES.md Data: its string literals (7 strings, 0x002ffbe8-0x002ffc3f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode (loads data/menu/shop/Item.csv rows into seven record vectors by name prefix); matching idioms: trailing unused empty By-value tag parameter False (retail frame is 16 bytes larger), push_back inline taking an unused char-member Tag that it forwards as Tag() to the out-of-line grow (a plain struct Tag { signed char c; } gives move v0,zero + seb; a constructor folds it), capacity() returning const unsigned & (the cap address hoisted into s0), the two record temporaries declared at function top, the name test chain as if (cmp != 0) idx = K else-if, the allocated Csv as csv = alloc(16); if (csv != 0) csv = ctor(csv), and delete without an extra explicit null test; exact match verified; names and types await human review. */
inline void *operator new(unsigned, void *p) { return p; }

struct Csv {
    virtual ~Csv();
};

struct Rec {
    short v[5];
    Rec() {}
};

struct False {};

struct Tag {
    signed char c;
};

struct RecVec {
    Rec *data;
    unsigned size;
    unsigned cap;
    const unsigned &capacity() const { return cap; }
};

struct Obj {
    RecVec vecs[7];
};

extern Csv *DAT_0034a84c;
extern char DAT_002ffbcc[];
extern char DAT_002ffbe4[];

extern "C" {
void *FUN_00000bcc(unsigned);
Csv *FUN_000649c0(void *);
int FUN_00064bf4(Csv *, char *, int, char *);
int FUN_000650e0(Csv *);
char *FUN_0006517c(Csv *, int, int);
short FUN_00065104(Csv *, int, int);
int FUN_00014d64(char *, char *);
void FUN_00293fcc(RecVec *, const Rec *, Tag);
}

static inline void PushBack(RecVec *v, const Rec &x, Tag)
{
    if (v->size < v->capacity()) {
        new (v->data + v->size) Rec(x);
        ++v->size;
    } else {
        FUN_00293fcc(v, &x, Tag());
    }
}

extern "C" void FUN_00293c6c(Obj *self, False)
{
    int i;
    int row;
    char *name;
    int idx;
    Rec blank;
    Rec r;
    if (DAT_0034a84c == 0) {
        Csv *csv = (Csv *)FUN_00000bcc(16);
        if (csv != 0) {
            csv = FUN_000649c0(csv);
        }
        DAT_0034a84c = csv;
        if (FUN_00064bf4(csv, DAT_002ffbcc, 1, DAT_002ffbe4) == 0 && DAT_0034a84c != 0) {
            delete DAT_0034a84c;
            DAT_0034a84c = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        blank.v[0] = -1;
        blank.v[1] = 0;
        blank.v[2] = 0;
        blank.v[3] = 0;
        blank.v[4] = 0;
        PushBack(&self->vecs[6], blank, Tag());
    }
    for (row = 0; row < FUN_000650e0(DAT_0034a84c); row++) {
        name = FUN_0006517c(DAT_0034a84c, row, 0);
        if (FUN_00014d64(name, "Item_Cam") != 0) {
            idx = 0;
        } else if (FUN_00014d64(name, "Item_CD") != 0) {
            idx = 1;
        } else if (FUN_00014d64(name, "Item_Voice") != 0) {
            idx = 2;
        } else if (FUN_00014d64(name, "Item_JudgeVoice") != 0) {
            idx = 3;
        } else if (FUN_00014d64(name, "Item_Wallpaper") != 0) {
            idx = 4;
        } else if (FUN_00014d64(name, "Item_Tickets") != 0) {
            idx = 5;
        } else if (FUN_00014d64(name, "Judge_") != 0) {
            idx = 6;
        }
        r.v[0] = FUN_00065104(DAT_0034a84c, row, 1);
        r.v[1] = FUN_00065104(DAT_0034a84c, row, 2);
        r.v[2] = FUN_00065104(DAT_0034a84c, row, 3);
        r.v[3] = FUN_00065104(DAT_0034a84c, row, 4);
        r.v[4] = FUN_00065104(DAT_0034a84c, row, 5);
        PushBack(&self->vecs[idx], r, Tag());
    }
}
