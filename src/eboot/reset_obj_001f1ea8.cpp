/* HSTMATCH module=EBOOT.BIN start=0x001f1ea8 end=0x001f20d8 symbol=FUN_001f1ea8 lang=c++ data=0x002ee864 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ee864-0x002ee883) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/prize_screen.h"


extern "C" {
void FUN_001ef3f8(const char *s, ...);
void FUN_001f4bfc(PrizeScreen *self);

extern void *DAT_003313c4;
extern char *DAT_003402a0;
extern void *DAT_003415d4;
extern char DAT_0034179c;
extern char DAT_00341d7d;
extern char DAT_00341d7e;
extern int DAT_0034a678;

void FUN_001b3ea4(void *dat, float f);
void FUN_001f9528(PrizeScreen *self);
void FUN_000114c0(void *dst, int val, int size);
void FUN_0005bbd4(void *dat, float f0, float f1, float f2, float f3, float f4, float f5);
void FUN_0005c7a4(void *dat, int zero, void *dst);
void FUN_001f2f08(PrizeScreen *self);
void *FUN_00219184(void *a, int b);
void FUN_000478d4(int a, int b);
void FUN_001f47a4(PrizeScreen *self);
}

struct Base {
    virtual ~Base();
};

#define REMATCH_FRAME 20          /* frame of the screen at which the reset runs */
#define COUNTER_LIMIT 0x60000000  /* the new_count is shifted down when it grows past this */
#define GAME_MODE_RESET 42        /* value of the global that gets the two bytes set to -1 */

/* Per-frame update: on the first frame clears the new_count, and at the reset frame resets the screen state
   (new_count, flags, camera-like values, owned objects) before the shared per-frame helpers run. */
extern "C" void FUN_001f1ea8(PrizeScreen *self) {
    if (self->unk44 == 0) {
        self->unk8174 = 0;
        FUN_001b3ea4(&DAT_0034179c, 0.5f);
    }

    if (++self->unk8174 == REMATCH_FRAME) {
        FUN_001ef3f8("-------- REMATCH ------------\n");

        int new_count = self->unk51c + 1;
        self->unk51c = new_count;
        if (new_count > COUNTER_LIMIT) {
            self->unk51c = new_count >> 2;
        }

        FUN_001f9528(self);
        FUN_000114c0(self->unk54, 0, PRIZE_BLOCK_BYTES);

        switch (DAT_0034a678) {
        case GAME_MODE_RESET:
            DAT_00341d7d = (char)-1;
            DAT_00341d7e = (char)-1;
            break;
        }
        self->unk516 = 1;

        self->active = 0;

        PrizeInner *inner = self->inner;
        FUN_0005bbd4(DAT_003313c4, 0.0f, 0.0f, 480.0f, 272.0f, 240.0f, 136.0f);
        FUN_0005c7a4(DAT_003313c4, 0, &inner->unkf0);

        if (DAT_003402a0 != 0) {
            DAT_003402a0[5140] = 1;
            DAT_003402a0[5141] = 1;
        }

        self->unk590 = 0;
        FUN_001f2f08(self);

        if (self->unk510 != 0) {
            delete (Base *)self->unk510;
            self->unk510 = 0;
        }

        if (DAT_003415d4 != 0) {
            delete (Base *)DAT_003415d4;
            DAT_003415d4 = 0;
        }

        inner = self->inner;
        Base *owned = (Base *)inner->unk90;
        if (owned != 0) {
            delete owned;
            inner->unk90 = 0;
        }

        void *obj = self->obj;
        if (obj != 0) {
            FUN_00219184(obj, 1);
            self->obj = 0;
        }

        FUN_000478d4(1, 0);
    }
    FUN_001f4bfc(self);
    FUN_001f47a4(self);
}
