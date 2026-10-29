/* HSTMATCH module=EBOOT.BIN start=0x001b6a7c end=0x001b6b5c symbol=FUN_001b6a7c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/state_obj.h"

extern char DAT_0034179c;

extern "C" void FUN_001b42b8(void *, int);
extern "C" void FUN_001b8754(void *, int);
extern "C" void FUN_001b87e8(void *, int, int);
extern "C" void FUN_001b94f8(int *, void *, int *, int *);
extern "C" void FUN_000623e8(int, float);

/* Initial state: runs the start step (sound manager call, then the object's own), calls the list helper
   on the list block, sets three entries to 0.1f and marks the handles as unused. */
extern "C" void FUN_001b6a7c(StateObj *self) {
    int out;
    int tail;
    int head;
    FUN_001b42b8(&DAT_0034179c, 37);
    if (self->unk84 < 2) {
        FUN_001b8754(self, 1);
        self->unk84 = 1;
    }
    else {
        FUN_001b87e8(self, 1, 1);
        self->unk84 = 1;
    }
    head = (int)self->list3c.head;
    tail = self->list3c.tail;
    FUN_001b94f8(&out, self->list3c.tag, &tail, &head);
    FUN_000623e8(2, 0.1f);
    FUN_000623e8(4, 0.1f);
    FUN_000623e8(8, 0.1f);
    self->handle54 = HANDLE_NONE;
    self->handle50 = HANDLE_NONE;
    self->handle64 = HANDLE_NONE;
    self->unk7b = 0;
}
