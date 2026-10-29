/* HSTMATCH module=EBOOT.BIN start=0x002543a4 end=0x002546b4 symbol=FUN_002543a4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/slot_queue.h"

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

/* First queued int of the deque. */
inline int &DequeFront(SlotDeque *q)
{
    unsigned i = q->first;
    return q->blocks[(q->head + i / SLOT_QUEUE_BLOCK_ELEMS) % q->capacity][i % SLOT_QUEUE_BLOCK_ELEMS];
}

/* Entry started for a slot; virtual slot 1 is called when the slot is set up. */
struct Ent {
    virtual void v0();
    virtual void v1();
};

extern "C" {
extern Ent *DAT_0034b340[];
extern void *DAT_003386c8;
int FUN_00049094(int);
void FUN_00254908(SlotQueueObj *, int);
void FUN_0025a4b8(SlotDeque *);
void FUN_00254bd0(SlotQueueObj *, int);
void FUN_0025488c(SlotQueueObj *);
int FUN_00048fc8(void (*)(SlotQueueObj *), SlotQueueObj *);
void *FUN_0008d970(void *, int);
void FUN_00057b58(void *, int, int, float);
void FUN_00058ddc(void *, int, int);
void FUN_00058ec4(void *, float, int);
void FUN_00059084(void *, int);
void FUN_000550ec(void *, float);
void FUN_000550c8(void *, Vec4 *);
int FUN_002548d8(SlotQueueObj *, int);
int FUN_00014a40(const char *);
void FUN_002182a0(int *, int, unsigned char, const char *);
}

/* Per-frame update: while a slot is pending, finishes its start once the check passes; otherwise pops the
   next queued slot and starts it. Then sets up every ready slot (clears its table and registers its name). */
extern "C" void FUN_002543a4(SlotQueueObj *self)
{
    bool pending = false;
    for (unsigned i = 0; i < SLOT_QUEUE_COUNT; i++) {
        if (self->state[i] == SLOT_STATE_PENDING) {
            pending = true;
            break;
        }
    }
    if (pending) {
        for (unsigned i = 0; i < SLOT_QUEUE_COUNT; i++) {
            if (self->state[i] == SLOT_STATE_PENDING && FUN_00049094(0) != 0) {
                self->state[i] = 0;
                FUN_00254908(self, self->cur);
                break;
            }
        }
    } else if (self->queue.length != 0) {
        SlotDeque *q = &self->queue;
        self->cur = DequeFront(q);
        FUN_0025a4b8(q);
        FUN_00254bd0(self, self->cur);
        self->ready[self->cur] = 0;
        self->state[self->cur] = SLOT_STATE_PENDING;
        FUN_00048fc8(FUN_0025488c, self);
        for (int i = 0; i < SLOT_QUEUE_COUNT; i++) {
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
            } while (++k < SLOT_QUEUE_COUNT);
            if (FUN_00014a40(self->name[i]) != 0)
                FUN_002182a0(self->slot[i], self->arg[i], self->kind[i], self->name[i]);
        }
    }
}
