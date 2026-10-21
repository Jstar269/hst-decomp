/* HSTMATCH module=hstp_trans_main.prx start=0x002339dc end=0x00233b74 symbol=FUN_002339dc lang=c++ */
/* Clone of src/eboot/ctor_tables_00224468.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003b28f0;
extern int DAT_00399594;
extern int DAT_00398354;
extern int DAT_003994d8;
extern int DAT_00399528;
extern int DAT_0039953c;
extern int DAT_00399548;
extern int DAT_0039956c;
extern int DAT_00399578;
extern "C" void FUN_0010873c(void *);
extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" int FUN_00109304(void *, int, int);
extern "C" int FUN_00108124(int, int);
extern "C" void *FUN_00000bcc(unsigned int);
extern "C" void *FUN_001196d8(void *);

class Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

struct Entry {
    int idx;
    int id;
    int out;
};

struct Node {
    void *vt;
    char pad[0x1c];
    int f20;
    int f24;
    int f28;
};

struct Extra {
    char pad[0xd8];
    int fD8;
    char pad2[0x114 - 0xdc];
    unsigned char b114;
};

struct Self {
    void *vt;
    char pad[0x54];
    int slots[3];
    Node *arr[9];
    int f88;
    int f8c;
};

extern "C" Self *FUN_002339dc(Self *self) {
    FUN_0010873c(self);
    self->vt = &DAT_003b28f0;
    self->f88 = 0;
    FUN_00109a44(self, &DAT_00399594, 0);
    FUN_00108e6c(self, *(float *)&DAT_00398354);
    int i = 0;
    int *tab = &DAT_003994d8;
    int off = 0;
    do {
        *(int *)((unsigned int)self + off + 0x58) = FUN_00109304(self, *tab, 0);
        i++;
        tab++;
        off += 4;
    } while (i < 3);
    int k = 0;
    Entry *e = (Entry *)&DAT_00399528;
    int off2 = 0;
    do {
        Node *n = (Node *)FUN_00108124(*(int *)((char *)self + (e->idx << 2) + 0x58), e->id);
        *(int *)((unsigned int)self + off2 + 0x64) = (int)n;
        e->out = n->f24;
        k++;
        off2 += 4;
        e++;
    } while (k < 9);
    Extra *p = (Extra *)self->arr[0]->f20;
    self->f8c = (int)p;
    p->fD8 = 0;
    p->b114 = 1;
    int g0 = *(int *)&DAT_0039953c;
    Node *n1 = self->arr[1];
    n1->f24 = g0;
    n1->f28 = g0;
    int g1 = *(int *)&DAT_00399548;
    Node *n2 = self->arr[2];
    n2->f24 = g1;
    n2->f28 = g1;
    int g2 = *(int *)&DAT_0039956c + 1;
    Node *n5 = self->arr[5];
    n5->f24 = g2;
    n5->f28 = g2;
    int g3 = *(int *)&DAT_00399578 + 1;
    Node *n6 = self->arr[6];
    n6->f24 = g3;
    n6->f28 = g3;
    void *obj = FUN_00000bcc(124);
    if (obj != 0) {
        self->f88 = (int)FUN_001196d8(obj);
    } else {
        self->f88 = (int)obj;
    }
    ((Base *)self)->m1();
    return self;
}
