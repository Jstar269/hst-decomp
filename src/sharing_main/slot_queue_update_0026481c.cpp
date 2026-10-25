/* HSTMATCH module=hstp_trans_main.prx start=0x0026481c end=0x00264b2c symbol=FUN_0026481c lang=c++ */
/* Clone of src/eboot/slot_queue_update_002543a4.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

typedef int Elem;
typedef Elem *Block;

struct Map {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block *data_;
    Block &operator[](unsigned i) { return data_[(start_ + i) % cap_]; }
};

struct Deque {
    Map map_;
    unsigned start_;
    unsigned size_;
    Elem &front() { return map_[start_ / 128][start_ % 128]; }
};

struct Ent {
    virtual void v0();
    virtual void v1();
};

struct Self {
    int cur;
    unsigned char ready[4];
    int arg[4];
    char name[4][17];
    unsigned char kind[4];
    char pad0[0xf8 - 0x60];
    int count;
    char pad1[0x19c - 0xfc];
    int slot[4][4];
    int state[4];
    Deque queue;
};

extern "C" {
extern Ent *DAT_003f468c[];
extern void *DAT_003e1a08;
int FUN_00048e38(int);
void FUN_00264d80(Self *, int);
void FUN_0026a968(Deque *);
void FUN_00265048(Self *, int);
void FUN_00264d04(Self *);
int FUN_00048d44(void (*)(Self *), Self *);
void *FUN_0008f108(void *, int);
void FUN_000587ac(void *, int, int, float);
void FUN_00059ac0(void *, int, int);
void FUN_00059ba8(void *, float, int);
void FUN_00059d68(void *, int);
void FUN_00055c0c(void *, float);
void FUN_00055be8(void *, Vec4 *);
int FUN_00264d50(Self *, int);
int FUN_00014a40(const char *);
void FUN_002273b8(int *, int, unsigned char, const char *);
}

extern "C" void FUN_0026481c(Self *self)
{
    bool waiting = false;
    for (unsigned i = 0; i < 4; i++) {
        if (self->state[i] == 2) {
            waiting = true;
            break;
        }
    }
    if (waiting) {
        for (unsigned i = 0; i < 4; i++) {
            if (self->state[i] == 2 && FUN_00048e38(0) != 0) {
                self->state[i] = 0;
                FUN_00264d80(self, self->cur);
                break;
            }
        }
    } else if (self->queue.size_ != 0) {
        Deque *q = &self->queue;
        self->cur = q->front();
        FUN_0026a968(q);
        FUN_00265048(self, self->cur);
        self->ready[self->cur] = 0;
        self->state[self->cur] = 2;
        FUN_00048d44(FUN_00264d04, self);
        for (int i = 0; i < 4; i++) {
            FUN_000587ac(FUN_0008f108(DAT_003e1a08, i), 0, 0, 0.0f);
            FUN_00059ac0(FUN_0008f108(DAT_003e1a08, i), 1, -1);
            FUN_00059ba8(FUN_0008f108(DAT_003e1a08, i), 1.0f, -1);
            FUN_00059d68(FUN_0008f108(DAT_003e1a08, i), -1);
            FUN_00055c0c(FUN_0008f108(DAT_003e1a08, i), 10.0f);
            Vec4 v;
            v.x = 0.0f;
            v.y = -0.85f;
            v.z = 0.0f;
            v.w = 1.0f;
            FUN_00055be8(FUN_0008f108(DAT_003e1a08, i), &v);
        }
    }
    for (int i = 0; i < self->count; i++) {
        if (FUN_00264d50(self, i) != 0) {
            if (DAT_003f468c[i] != 0)
                DAT_003f468c[i]->v1();
            unsigned k = 0;
            do {
                self->slot[i][k] = 0;
            } while (++k < 4);
            if (FUN_00014a40(self->name[i]) != 0)
                FUN_002273b8(self->slot[i], self->arg[i], self->kind[i], self->name[i]);
        }
    }
}
