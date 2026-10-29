/* HSTMATCH module=EBOOT.BIN start=0x00123470 end=0x001237e0 symbol=FUN_00123470 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/match_input.h"

/* Global match object: two words are read. */
typedef struct Match {
    char pad0[0x9c];
    int unk9c;      /* 0x9c */
    int pad_a0;
    int unka4;      /* 0xa4 */
} Match;

extern Match *DAT_00338b44;
extern int DAT_0033b494;
extern int DAT_0033b498;
extern int DAT_002da1a0;
extern int DAT_002da1a4;
extern int DAT_002da1a8;
extern unsigned int DAT_00310fc8;
extern int DAT_0034a820;

extern int FUN_000de208(Match *, int);
extern int FUN_000de268(Match *, int);
extern int FUN_000de298(Match *, int);
extern int FUN_000de238(Match *, int);
extern unsigned int FUN_002b79e8(void);
extern int FUN_00125230(MatchInput *);
extern void FUN_00124274(MatchInput *);
extern void FUN_00132124(int, int *);
extern int FUN_001252fc(MatchInput *, int);
extern int FUN_00125514(MatchInput *, int, int, int);
extern void FUN_002932b8(float, int, int);

/* Decides the mode (from the match object and the input word), then fills the globals with the value chosen by the
   helpers; with arg set and no choice made, falls back to copying the saved values. */
void FUN_00123470(MatchInput *self, int arg)
{
    int mode = 0;
    int picked;
    int flag;
    float value;
    if (DAT_00338b44->unk9c == 0) {
        if (FUN_000de208(DAT_00338b44, -1) != 0) {
            mode = 2;
        } else if (FUN_000de268(DAT_00338b44, -1) != 0) {
            mode = 1;
        } else if (FUN_000de298(DAT_00338b44, -1) != 0) {
            mode = 3;
        } else if (FUN_000de238(DAT_00338b44, -1) != 0) {
            mode = 16;
        } else if (DAT_00338b44->unka4 == 0) {
            mode = 16;
        }
    } else if (DAT_00338b44->unka4 == 1) {
        mode = 16;
    }
    if (mode == 0 && ((unsigned char)FUN_002b79e8() & 0x10) != 0) {
        mode = 16;
    }
    self->unk80 = -1;
    if (FUN_00125230(self) != 0 && self->unk7b != 0 && mode != 0) {
        self->unk8c = 1;
        flag = FUN_00125230(self);
        if (flag != 0) {
            self->unk94 = 1;
            self->unk95 = 1;
        } else {
            self->unk94 = 0;
            self->unk95 = 0;
        }
        if (mode == 16 && FUN_00125230(self) != 0 &&
            (DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3, (int)((DAT_00310fc8 >> 16) & 0x7fff) % 100 < 80)) {
            FUN_00132124(60, &picked);
            value = (float)FUN_001252fc(self, picked);
        } else {
            value = (float)FUN_00125514(self, mode, 0, arg);
        }
        if (value < 0.0f) {
            DAT_002da1a4 = DAT_002da1a0;
        } else {
            DAT_002da1a4 = DAT_002da1a0;
            DAT_002da1a8 = DAT_002da1a0;
            self->unk80 = (int)value;
        }
        int *last_slot = &DAT_0033b494;
        value = (float)FUN_00125514(self, mode, 1, arg);
        if (value < 0.0f) {
            DAT_0033b498 = DAT_0033b494;
        } else {
            int index = (int)value;
            *last_slot = index;
            DAT_0033b498 = index;
            DAT_002da1a8 = index;
            self->unk80 = index;
        }
        if (arg != 0 && DAT_0034a820 != 0) {
            FUN_002932b8(65535.0f, DAT_0034a820, 4);
        }
    } else {
        if (arg != 0) {
            if (self->unk7b != 0 && mode != 0) {
                self->unk79 = 1;
                FUN_00124274(self);
                if (self->unk79 != 0) {
                    DAT_002da1a0 = self->unk58;
                } else {
                    DAT_0033b494 = self->unk58;
                }
            }
            DAT_0033b498 = DAT_0033b494;
            DAT_002da1a4 = DAT_002da1a0;
            if (self->unk7b != 0 && mode != 0) {
                self->unk8c = 1;
            }
        }
    }
}
