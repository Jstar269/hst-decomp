/* HSTMATCH module=EBOOT.BIN start=0x000c0d14 end=0x000c0fb8 symbol=FUN_000c0d14 lang=c99 rodata=0x002c00f8 */
/* Hand-written reconstruction from disassembly; exact match verified. */

struct Vec4 {
    float x, y, z, w;
};

struct Vec3 {
    float x, y, z;
};

struct Transform {
    struct Vec4 r[4];
    struct Vec3 pos;
};

struct Obj {
    char pad_00[0x3c];
    int mode;           /* 0x3c */
    char pad_40[4];     /* 0x40 */
    signed char f44;    /* 0x44 */
    char pad_45[3];     /* 0x45 */
    struct Transform tf;/* 0x48 .. 0x93 */
    char pad_94[0x600]; /* 0x94 .. 0x693 */
    int f694;           /* 0x694 */
    char pad_698[0x94]; /* 0x698 .. 0x72b */
    void *f72c;         /* 0x72c */
    char pad_730[0x3c]; /* 0x730 .. 0x76b */
    void *f76c;         /* 0x76c */
    char pad_770[0x10]; /* 0x770 .. 0x77f */
    int count;          /* 0x780 */
};

extern int DAT_00338ad0;

void FUN_000c1624(struct Transform *tf);
void *FUN_00000a90(unsigned int size);
void FUN_000114c0(void *dest, int val, unsigned int size);
void FUN_000c0fb8(struct Obj *self, int arg);

int FUN_000c0d14(struct Obj *self, int mode, const struct Transform *tf)
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

    if (self->mode < 5) {
        self->f44 = 1;
    } else {
        self->f44 = 0;
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
    case 4:
        self->f694 = 1;
        self->f72c = FUN_00000a90(self->count * 0x50);
        FUN_000114c0(self->f72c, 0, self->count * 0x50);
        self->f76c = FUN_00000a90(self->count * 0x18);
        FUN_000114c0(self->f76c, 0, self->count * 0x18);
        FUN_000c0fb8(self, 3);
        break;
    case 9:
        self->f694 = 1;
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
