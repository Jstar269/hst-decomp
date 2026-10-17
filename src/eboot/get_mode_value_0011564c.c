/* HSTMATCH module=EBOOT.BIN start=0x0011564c end=0x001156ac symbol=FUN_0011564c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Obj_0011564c {
    char pad_00[0x68];
    int mode;       /* 0x68 */
    int flags;      /* 0x6c */
    char pad_70[0xd];
    unsigned char val; /* 0x7d */
    char pad_7e[0xa];
    int state;      /* 0x88 */
};

unsigned char FUN_0011564c(struct Obj_0011564c *self)
{
    if ((self->flags & 8) != 0) {
        if (self->state > 0 && self->state < 3) {
            return 0;
        }
    }
    switch (self->mode) {
    case 3:
    case 4:
        return self->val;
    }
    return 0;
}
