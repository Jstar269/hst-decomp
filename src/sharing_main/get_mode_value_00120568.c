/* HSTMATCH module=hstp_trans_main.prx start=0x00120568 end=0x001205c8 symbol=FUN_00120568 lang=c99 */
/* Clone of src/eboot/get_mode_value_0011564c.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Obj_00120568 {
    char pad_00[0x68];
    int mode;       /* 0x68 */
    int flags;      /* 0x6c */
    char pad_70[0xd];
    unsigned char val; /* 0x7d */
    char pad_7e[0xa];
    int state;      /* 0x88 */
};

unsigned char FUN_00120568(struct Obj_00120568 *self)
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
