/* HSTMATCH module=EBOOT.BIN start=0x0010ba20 end=0x0010bc70 symbol=FUN_0010ba20 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: the two sound-mask objects are volatile (unused second word kept in memory) and the inline helper takes a plain struct pointer. */
typedef unsigned short ushort;

struct Item {
    char pad0[0xe];
    ushort f0e;             /* 0x0e */
};

struct Self {
    char pad0[0x10];
    struct Item **items;    /* 0x10 */
    char pad14[0xc0];       /* 0x14..0xd3 */
    int f0d4;               /* 0xd4 */
    int f0d8;               /* 0xd8 */
    char pad_dc[0x24];      /* 0xdc..0xff */
    int key100;             /* 0x100 */
    int pad104;             /* 0x104 */
    int key108;             /* 0x108 */
    char pad10c[0xc];       /* 0x10c..0x117 */
    int f118;               /* 0x118 */
};

/* Button mask pair for one direction; both words are always written. */
struct Snd {
    int mask;               /* 0x00 */
    int alt;                /* 0x04 */
};

extern void *DAT_002cfc8c;
extern void FUN_0001e23c(void *p, int a, int b);
extern int FUN_0001ea64(void *p, void *key, int mask, int n, int m);

static inline int Play(void *p, int *key, struct Snd *snd)
{
    return FUN_0001ea64(p, key, snd->mask, 2, 9);
}

int FUN_0010ba20(struct Self *self, int *cursor, int count, int wrap)
{
    struct Item *item;
    int idx;
    int mode;
    int result = 0;
    volatile struct Snd down, up;

    mode = self->f118;
    idx = self->f0d4;
    switch (mode) {
    case 1:
        item = self->items[idx];
        break;
    case 2:
        item = *(struct Item **)((char *)self->items + (idx + 2) * 4);
        break;
    case 0:
    default:
        item = *(struct Item **)((char *)self->items + (idx + 1) * 4);
        break;
    }
    if ((item->f0e & 3) != 0)
        return 0;
    if (self->f0d8 == 1) {
        down.mask = 0x10;
        down.alt = 0x10000;
        up.mask = 0x40;
        up.alt = 0x40000;
    } else {
        down.mask = 0x80;
        down.alt = 0x80000;
        up.mask = 0x20;
        up.alt = 0x20000;
    }
    if (Play(DAT_002cfc8c, &self->key100, (struct Snd *)&down) != 0) {
        if (wrap != 0) {
            *cursor = (*cursor - 1 + count) % count;
            result = 1;
        } else {
            if (*cursor > 0) {
                *cursor = *cursor - 1;
                result = 1;
            }
        }
        if (*cursor == 0) {
            FUN_0001e23c(DAT_002cfc8c, 0x80, 1);
            FUN_0001e23c(DAT_002cfc8c, 0x80, 1);
        }
    } else if (Play(DAT_002cfc8c, &self->key108, (struct Snd *)&up) != 0) {
        if (wrap != 0) {
            *cursor = (*cursor + 1) % count;
            result = 1;
        } else {
            if (*cursor < count - 1) {
                *cursor = *cursor + 1;
                result = 1;
            }
        }
        if (*cursor == count - 1) {
            FUN_0001e23c(DAT_002cfc8c, 0x20, 1);
            FUN_0001e23c(DAT_002cfc8c, 0x20, 1);
        }
    }
    return result;
}
