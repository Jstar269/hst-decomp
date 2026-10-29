/* HSTMATCH module=EBOOT.BIN start=0x0017c6d4 end=0x0017c968 symbol=FUN_0017c6d4 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/pending_slots.h"

typedef PendingSlot Slot;
typedef PendingSlotsObj Obj;

extern "C" {
int FUN_00049094(unsigned int);
int FUN_001fe0dc(void);
void FUN_001fe0e8(int);
void FUN_0017d018(Obj*, int, float*, unsigned char, int);
void FUN_0017db50(Obj*);
int FUN_00048fc8(void (*)(Obj*), Obj*);
void FUN_0017c6d4(Obj *self, unsigned int force);
}

/* Counts the timers down; when the flush timer runs out, applies and clears every queued slot, then hands the current slot to the start helper. */
void FUN_0017c6d4(Obj *self, unsigned int force) {
    Slot *slot = &self->current;
    bool start = false;
    bool ticked;

    if (FUN_00049094(force & 0xff)) {
        if (FUN_001fe0dc()) {
            FUN_001fe0e8(0);
        }
        ticked = true;
        if (--self->flush_timer <= 0) {
            self->flush_timer = 0;
            for (int i = 0; i < PENDING_SLOT_COUNT; i++) {
                Slot *s = &self->queued[i];
                if (self->queued[i].id == PENDING_SLOT_EMPTY) break;
                FUN_0017d018(self, s->id, s->data, s->unk4, 1);
                s->id = PENDING_SLOT_EMPTY;
                s->unk4 = 0;
                s->handled = 0;
                s->unk6 = 0;
                s->unk7 = 0;
                *(int*)&s->data[0] = PENDING_SLOT_EMPTY;
                *(int*)&s->data[1] = PENDING_SLOT_EMPTY;
                *(int*)&s->data[2] = PENDING_SLOT_EMPTY;
                *(int*)&s->data[3] = PENDING_SLOT_EMPTY;
                *(int*)&s->data[4] = PENDING_SLOT_EMPTY;
                *(int*)&s->data[5] = PENDING_SLOT_EMPTY;
            }
        } else {
            ticked = false;
        }
    } else {
        ticked = false;
    }

    if (ticked) {
        if (--self->hold_timer <= 0) {
            self->hold_timer = 0;
        }
        if (force != 0) {
            start = true;
        } else if (slot->handled == 0 && FUN_00049094(force & 0xff) != 0 && self->hold_timer <= 0) {
            start = true;
        }

        if (start && slot->id != PENDING_SLOT_EMPTY) {
            if (force != 0) {
                self->copy = *slot;
                FUN_0017db50(self);
                slot->handled = 1;
                self->copy.handled = 1;
            } else {
                self->copy = *slot;
                if (FUN_00048fc8(FUN_0017db50, self) != 0) {
                    slot->handled = 1;
                    self->copy.handled = 1;
                }
            }
        }
    }
}
