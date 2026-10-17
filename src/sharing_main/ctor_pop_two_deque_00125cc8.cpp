/* HSTMATCH module=hstp_trans_main.prx start=0x00125cc8 end=0x00125ed0 symbol=FUN_00125cc8 lang=c++ */
/* Clone of src/eboot/ctor_pop_two_deque_0011aaf4.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7/v21c) corrected by hand: typed owner/deque/element structs (cdeque of 12-byte {int,int,float} with memberwise copy ctor, front() = buf_[start/42][start%42]), the `==10||==9||==8` chain is a `switch (k) { case 8: case 9: case 10: ... default: }`; exact match verified; names and types await human review. */
struct Elem {
    int a, b;
    float c;
    Elem(const Elem &o) : a(o.a), b(o.b), c(o.c) {}
};
struct Map {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem **data_;
    Elem *&operator[](unsigned i) { return data_[(start_ + i) % cap_]; }
};
struct Deque {
    Map buf_;
    unsigned start_;
    unsigned size_;
    Elem &front() { return buf_[start_ / 42][start_ % 42]; }
};
struct Owner {
    char pad[0x2e0];
    Deque dq;
};
struct Self {
    int vptr;
    char padb[0x38];
    Owner *owner;
    char sub[0x70];
    int kind;
    int vb;
    float vc;
    int kind2;
    int vb2;
    float vc2;
    unsigned char flag;
    int count;
};
extern "C" {
extern char DAT_003b12ac;
extern unsigned char DAT_003e47c0;
extern Self *DAT_003e47c4;
extern void FUN_0001ec44(void *);
extern void FUN_0001ef14(void *, int);
extern void FUN_0001ef34(void *, void *);
extern void FUN_0005b6bc(void *);
extern void FUN_00127b6c(void *);
}

extern "C" Self *FUN_00125cc8(Self *self, Owner *o)
{
    FUN_0001ec44(self);
    self->vptr = (int)&DAT_003b12ac;
    self->owner = o;
    FUN_0005b6bc(self->sub);
    self->flag = 0;
    FUN_0001ef34(o, self);
    DAT_003e47c0 = 1;
    DAT_003e47c4 = self;
    self->count = 0;
    Deque *d = &o->dq;
    if (d->size_ == 0) {
        FUN_0001ef14(self, 0);
        DAT_003e47c0 = 0;
    } else {
        Elem &e = d->front();
        self->kind = e.a;
        self->vb = e.b;
        self->vc = e.c;
        FUN_00127b6c(d);
        if (d->size_ != 0) {
            Elem &e2 = d->front();
            self->kind2 = e2.a;
            self->vb2 = e2.b;
            self->vc2 = e2.c;
            FUN_00127b6c(d);
            self->vb = self->vb + self->vb2;
        }
        self->vb2 = 0;
        int k = self->kind;
        switch (k) {
        case 8:
        case 9:
        case 10:
            self->count = 30;
            break;
        default:
            self->count = 45;
        }
    }
    return self;
}
