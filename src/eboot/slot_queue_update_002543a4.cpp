/* HSTMATCH module=EBOOT.BIN start=0x002543a4 end=0x002546b4 symbol=FUN_002543a4 lang=c++ */
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
extern Ent *DAT_0034b340[];
extern void *DAT_003386c8;
int FUN_00049094(int);
void FUN_00254908(Self *, int);
void FUN_0025a4b8(Deque *);
void FUN_00254bd0(Self *, int);
void FUN_0025488c(Self *);
int FUN_00048fc8(void (*)(Self *), Self *);
void *FUN_0008d970(void *, int);
void FUN_00057b58(void *, int, int, float);
void FUN_00058ddc(void *, int, int);
void FUN_00058ec4(void *, float, int);
void FUN_00059084(void *, int);
void FUN_000550ec(void *, float);
void FUN_000550c8(void *, Vec4 *);
int FUN_002548d8(Self *, int);
int FUN_00014a40(const char *);
void FUN_002182a0(int *, int, unsigned char, const char *);
}

extern "C" void FUN_002543a4(Self *self)
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
            if (self->state[i] == 2 && FUN_00049094(0) != 0) {
                self->state[i] = 0;
                FUN_00254908(self, self->cur);
                break;
            }
        }
    } else if (self->queue.size_ != 0) {
        Deque *q = &self->queue;
        self->cur = q->front();
        FUN_0025a4b8(q);
        FUN_00254bd0(self, self->cur);
        self->ready[self->cur] = 0;
        self->state[self->cur] = 2;
        FUN_00048fc8(FUN_0025488c, self);
        for (int i = 0; i < 4; i++) {
            FUN_00057b58(FUN_0008d970(DAT_003386c8, i), 0, 0, 0.0f);
            FUN_00058ddc(FUN_0008d970(DAT_003386c8, i), 1, -1);
            FUN_00058ec4(FUN_0008d970(DAT_003386c8, i), 1.0f, -1);
            FUN_00059084(FUN_0008d970(DAT_003386c8, i), -1);
            FUN_000550ec(FUN_0008d970(DAT_003386c8, i), 10.0f);
            Vec4 v;
            v.x = 0.0f;
            v.y = -0.85f;
            v.z = 0.0f;
            v.w = 1.0f;
            FUN_000550c8(FUN_0008d970(DAT_003386c8, i), &v);
        }
    }
    for (int i = 0; i < self->count; i++) {
        if (FUN_002548d8(self, i) != 0) {
            if (DAT_0034b340[i] != 0)
                DAT_0034b340[i]->v1();
            unsigned k = 0;
            do {
                self->slot[i][k] = 0;
            } while (++k < 4);
            if (FUN_00014a40(self->name[i]) != 0)
                FUN_002182a0(self->slot[i], self->arg[i], self->kind[i], self->name[i]);
        }
    }
}
