/* HSTMATCH module=EBOOT.BIN start=0x002919e4 end=0x00291a80 symbol=FUN_002919e4 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-written from the disassembly; exact match verified. Names and types await human review. */
/* Matching idiom: a 12-byte `V3 v = *src;` local stages the record through sp+20..28 before the
   memberwise stores; the error case is the fall-through (`if (r < 0) { ... return 0; } return 1;`),
   and keeping the result in a local `r` leaves it in v0 for both the field store and the error call. */
struct V3 {
    float x, y, z;
};

#include "hst/thread_task.h"

extern "C" {
    extern void LAB_002919d4();
    extern char DAT_002ffa04;
    extern int FUN_002b7920(int, void *, int, int, int, int);
    extern void FUN_0028fb44(void *, int);
}

/* Like FUN_002918f0 but only creates the thread (no start); returns 1 on success, 0 on error. */
extern "C" int FUN_002919e4(ThreadTask *self, int key, int unk4, const V3 *src, int priority, int stack_size, int attr)
{
    V3 v = *src;        /* 12-byte local -> the sp+20 float staging MWCC emits */
    self->unk4 = unk4;
    self->pos[0] = v.x;
    self->pos[1] = v.y;
    self->pos[2] = v.z;
    self->key = key;
    int r = FUN_002b7920(key, &LAB_002919d4, priority, stack_size, attr, 0);
    self->thread = r;
    if (r < 0) {
        FUN_0028fb44(&DAT_002ffa04, r);
        return 0;
    }
    return 1;
}
