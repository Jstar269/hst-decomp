/* HSTMATCH module=EBOOT.BIN start=0x000c0d14 end=0x000c0fb8 symbol=FUN_000c0d14 lang=c99 rodata=0x002c00f8 */
/* Hand-written reconstruction from disassembly; exact match verified. */
#include "hst/data_pack.h"

enum {
    PACK_MODE_WITH_TABLES = 4,   /* allocates the two work tables */
    PACK_MODE_FLAGGED = 9,       /* sets unk694 without tables */
    PACK_FIRST_HIGH_MODE = 5     /* modes below this set unk44 */
};

extern int DAT_00338ad0;

void FUN_000c1624(PackTransform *tf);
void *FUN_00000a90(unsigned int size);
void FUN_000114c0(void *dest, int val, unsigned int size);
void FUN_000c0fb8(DataPack *self, int layout);

/* Stores the mode and optional transform, then runs the per-mode set-up. */
int FUN_000c0d14(DataPack *self, int mode, const PackTransform *tf)
{
    DAT_00338ad0 = 0;
    self->mode = mode;
    if (tf != 0) {
        self->tf.r[0] = tf->r[0];
        self->tf.r[1] = tf->r[1];
        self->tf.r[2] = tf->r[2];
        self->tf.r[3] = tf->r[3];
        self->tf.pos = tf->pos;
    } else {
        FUN_000c1624(&self->tf);
    }

    if (self->mode < PACK_FIRST_HIGH_MODE) {
        self->unk44 = 1;
    } else {
        self->unk44 = 0;
    }

    switch (self->mode) {
    case 0:
        FUN_000c0fb8(self, 1);
        break;
    case 5:
        FUN_000c0fb8(self, 2);
        break;
    case 1:
        FUN_000c0fb8(self, 1);
        break;
    case 6:
        FUN_000c0fb8(self, 2);
        break;
    case 2:
        FUN_000c0fb8(self, 1);
        break;
    case 7:
        FUN_000c0fb8(self, 2);
        break;
    case 3:
        FUN_000c0fb8(self, 1);
        break;
    case 8:
        FUN_000c0fb8(self, 2);
        break;
    case PACK_MODE_WITH_TABLES:
        self->unk694 = 1;
        self->table72c = FUN_00000a90(self->items.count * 0x50);
        FUN_000114c0(self->table72c, 0, self->items.count * 0x50);
        self->table76c = FUN_00000a90(self->items.count * 0x18);
        FUN_000114c0(self->table76c, 0, self->items.count * 0x18);
        FUN_000c0fb8(self, 3);
        break;
    case PACK_MODE_FLAGGED:
        self->unk694 = 1;
        FUN_000c0fb8(self, 6);
        break;
    case 10:
        FUN_000c0fb8(self, 7);
        break;
    case 11:
        FUN_000c0fb8(self, 7);
        break;
    case 12:
        FUN_000c0fb8(self, 7);
        break;
    case 13:
        FUN_000c0fb8(self, 7);
        break;
    }

    return 1;
}
