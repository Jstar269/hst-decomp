/* HSTMATCH module=hstp_trans_main.prx start=0x001fd4f8 end=0x001fd5a8 symbol=FUN_001fd4f8 lang=c99 */
/* Clone of src/eboot/mode_dispatch_teardown_001ef0fc.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Self {
    char pad0[0x40];
    int mode;
    char pad1[0x514 - 0x44];
    unsigned char flag;
    char pad2[0x564 - 0x515];
    void *obj;
} Self;

extern void FUN_00200d38(Self *self);
extern void FUN_00200d40(Self *self);
extern void FUN_00200d48(Self *self);
extern void FUN_00200d50(Self *self);
extern int FUN_002079a4(Self *self);
extern void FUN_00228ee0(void *obj);

void FUN_001fd4f8(Self *self)
{
    if (self->flag == 0)
        return;

    FUN_00200d38(self);

    switch (self->mode) {
    case 1:
        FUN_00200d40(self);
        break;
    case 14:
        FUN_00200d48(self);
        break;
    case 16:
        FUN_00200d50(self);
        break;
    }

    if (FUN_002079a4(self) != 0) {
        if (self->obj != 0)
            FUN_00228ee0(self->obj);
    }
}
