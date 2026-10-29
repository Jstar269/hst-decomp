/* HSTMATCH module=EBOOT.BIN start=0x002323e0 end=0x00232558 symbol=FUN_002323e0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/game_record.h"

/* matching idiom: the i == count-1 test goes through an int-returning inline helper (int->bool conversion gives retail's extra sltu); a direct bool comparison folds it. */
/* Per-slot state refresh over ten slots: four int[10] tables at +0x200/+0x228/+0x250/+0x278; the slot
   flag bytes live in the game record (the same bytes the predicates FUN_0022c8b4 (bit 0),
   FUN_0022c988 (bit 1), FUN_0022c928 (bit 2) test). Names provisional. */
extern GameRecord *DAT_003415a8;
extern int DAT_002f3668;
extern "C" int FUN_0022c928(int);
extern "C" int FUN_0022c988(int);
extern "C" int FUN_0022c8b4(int);
extern "C" int FUN_0022c1f4(int);

struct Slots {
    char pad[0x200];
    int status[RECORD_SLOT_COUNT];
    int unk228[RECORD_SLOT_COUNT];
    int unk250[RECORD_SLOT_COUNT];
    int unk278[RECORD_SLOT_COUNT];
};

/* True for the slot just below the requested one. */
static inline int IsLast(int i) { return i == DAT_002f3668 - 1; }

extern "C" void FUN_002323e0(Slots *self) {
    RecordSlots *save = &DAT_003415a8->slots;
    for (int i = 0; i < RECORD_SLOT_COUNT; i++) {
        self->unk228[i] = 0;
        bool skip = IsLast(i);
        bool flag = i == 8 && FUN_0022c928(7) && !FUN_0022c988(8);
        skip |= flag;
        if (!FUN_0022c8b4(i) || skip) {
            self->status[i] = 0;
        } else if (!FUN_0022c1f4(i)) {
            self->status[i] = 1;
        } else if (!FUN_0022c988(i)) {
            self->status[i] = 2;
        } else if (self->unk228[i] < 100) {
            self->status[i] = 3;
        } else {
            self->status[i] = 5;
        }
        bool clear = !(save->slot_flags[i] & SLOT_FLAG_BIT7);
        if (i != 0 && self->status[i] == 2 && clear) {
            self->status[i] = 4;
        }
        self->unk250[i] = 0;
        self->unk278[i] = 0;
    }
}
