/* HSTMATCH module=EBOOT.BIN start=0x002918f0 end=0x002919d4 symbol=FUN_002918f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/thread_task.h"

struct V { float v[3]; };

extern "C" char DAT_002ffa04[];
extern "C" char DAT_002ff9dc[];
extern "C" void LAB_002919d4();

extern "C" int FUN_002b7920(int, void *, int, int, int, int);
extern "C" int FUN_002b78d8(int, int, void *);
extern "C" void FUN_002b79a8(int);
extern "C" void FUN_0028fb44(char *, int);

/* Creates the thread, then starts it with a pointer to the task as its argument.
   Returns 1 on success; on failure logs, releases the handle and returns 0. */
extern "C" int FUN_002918f0(ThreadTask *self, int key, int unk4, V *pos, int priority, int stack_size, int attr) {
    int r;
    V tmp = *pos;
    ThreadTask *start_arg;
    self->unk4 = unk4;
    self->pos[0] = tmp.v[0];
    self->pos[1] = tmp.v[1];
    self->pos[2] = tmp.v[2];
    self->key = key;
    r = FUN_002b7920(key, (void *)&LAB_002919d4, priority, stack_size, attr, 0);
    self->thread = r;
    if (r < 0) {
        FUN_0028fb44(DAT_002ffa04, r);
    } else {
        start_arg = self;
        if (FUN_002b78d8(self->thread, 4, &start_arg) < 0) {
            FUN_0028fb44(DAT_002ff9dc, self->thread);
        } else {
            return 1;
        }
    }
    if (self->thread > 0) {
        FUN_002b79a8(self->thread);
        self->thread = -1;
    }
    return 0;
}
