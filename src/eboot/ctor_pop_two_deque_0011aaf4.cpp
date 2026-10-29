/* HSTMATCH module=EBOOT.BIN start=0x0011aaf4 end=0x0011acfc symbol=FUN_0011aaf4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7/v21c) corrected by hand: typed owner/deque/element structs (cdeque of 12-byte {int,int,float} with memberwise copy ctor, front() = buf_[start/42][start%42]), the `==10||==9||==8` chain is a `switch (first_kind) { case 8: case 9: case 10: ... default: }`; readability pass; exact match verified; names and types await human review. */
enum { ELEMS_PER_BLOCK = 42, COUNT_SHORT = 30, COUNT_LONG = 45 };

struct Elem {
    int kind, amount;
    float param;
    Elem(const Elem &o) : kind(o.kind), amount(o.amount), param(o.param) {}
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
    Elem &front() { return buf_[start_ / ELEMS_PER_BLOCK][start_ % ELEMS_PER_BLOCK]; }
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
    int amount;
    float param;
    int kind2;
    int amount2;
    float param2;
    unsigned char flag;  /* cleared by the constructor */  /* cleared by the constructor */
    int count;
};
extern "C" {
extern char DAT_00307fe0;
extern unsigned char DAT_0033b480;
extern Self *DAT_0033b484;
extern void FUN_0001f06c(void *);
extern void FUN_0001f1fc(void *, int);
extern void FUN_0001f21c(void *, void *);
extern void FUN_0005a8ec(void *);
extern void FUN_0011c998(void *);
}

extern "C" Self *FUN_0011aaf4(Self *self, Owner *owner)
{
    FUN_0001f06c(self);
    self->vptr = (int)&DAT_00307fe0;
    self->owner = owner;
    FUN_0005a8ec(self->sub);
    self->flag = 0;
    FUN_0001f21c(owner, self);
    DAT_0033b480 = 1;
    DAT_0033b484 = self;
    self->count = 0;
    Deque *queue = &owner->dq;
    if (queue->size_ == 0) {
        FUN_0001f1fc(self, 0);
        DAT_0033b480 = 0;
    } else {
        Elem &first = queue->front();
        self->kind = first.kind;
        self->amount = first.amount;
        self->param = first.param;
        FUN_0011c998(queue);
        if (queue->size_ != 0) {
            Elem &second = queue->front();
            self->kind2 = second.kind;
            self->amount2 = second.amount;
            self->param2 = second.param;
            FUN_0011c998(queue);
            self->amount = self->amount + self->amount2;
        }
        self->amount2 = 0;
        int k = self->kind;
        switch (k) {
        case 8:
        case 9:
        case 10:
            self->count = COUNT_SHORT;
            break;
        default:
            self->count = COUNT_LONG;
        }
    }
    return self;
}
