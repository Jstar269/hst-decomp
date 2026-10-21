/* HSTMATCH module=hstp_trans_main.prx start=0x002a5278 end=0x002a55d8 symbol=FUN_002a5278 lang=c++ */
/* Clone of src/eboot/shop_item_table_00293c6c.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
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

extern Csv *DAT_003f3b7c;
extern char DAT_003a8ad8[];
extern char DAT_003a8af0[];
extern char DAT_003a8af4[];
extern char DAT_003a8b00[];
extern char DAT_003a8b08[];
extern char DAT_003a8b14[];
extern char DAT_003a8b24[];
extern char DAT_003a8b34[];
extern char DAT_003a8b44[];

extern "C" {
void *FUN_00000bcc(unsigned);
Csv *FUN_00065884(void *);
int FUN_00065ab8(Csv *, char *, int, char *);
int FUN_00065fa4(Csv *);
char *FUN_000661a8(Csv *, int, int);
short FUN_00066038(Csv *, int, int);
int FUN_00014d64(char *, char *);
void FUN_002a55d8(RecVec *, const Rec *, Tag);
}

static inline void PushBack(RecVec *v, const Rec &x, Tag)
{
    if (v->size < v->capacity()) {
        new (v->data + v->size) Rec(x);
        ++v->size;
    } else {
        FUN_002a55d8(v, &x, Tag());
    }
}

extern "C" void FUN_002a5278(Obj *self, False)
{
    int i;
    int row;
    char *name;
    int idx;
    Rec blank;
    Rec r;
    if (DAT_003f3b7c == 0) {
        Csv *csv = (Csv *)FUN_00000bcc(16);
        if (csv != 0) {
            csv = FUN_00065884(csv);
        }
        DAT_003f3b7c = csv;
        if (FUN_00065ab8(csv, DAT_003a8ad8, 1, DAT_003a8af0) == 0 && DAT_003f3b7c != 0) {
            delete DAT_003f3b7c;
            DAT_003f3b7c = 0;
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
    for (row = 0; row < FUN_00065fa4(DAT_003f3b7c); row++) {
        name = FUN_000661a8(DAT_003f3b7c, row, 0);
        if (FUN_00014d64(name, DAT_003a8af4) != 0) {
            idx = 0;
        } else if (FUN_00014d64(name, DAT_003a8b00) != 0) {
            idx = 1;
        } else if (FUN_00014d64(name, DAT_003a8b08) != 0) {
            idx = 2;
        } else if (FUN_00014d64(name, DAT_003a8b14) != 0) {
            idx = 3;
        } else if (FUN_00014d64(name, DAT_003a8b24) != 0) {
            idx = 4;
        } else if (FUN_00014d64(name, DAT_003a8b34) != 0) {
            idx = 5;
        } else if (FUN_00014d64(name, DAT_003a8b44) != 0) {
            idx = 6;
        }
        r.v[0] = FUN_00066038(DAT_003f3b7c, row, 1);
        r.v[1] = FUN_00066038(DAT_003f3b7c, row, 2);
        r.v[2] = FUN_00066038(DAT_003f3b7c, row, 3);
        r.v[3] = FUN_00066038(DAT_003f3b7c, row, 4);
        r.v[4] = FUN_00066038(DAT_003f3b7c, row, 5);
        PushBack(&self->vecs[idx], r, Tag());
    }
}
