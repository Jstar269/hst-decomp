/* HSTMATCH module=EBOOT.BIN start=0x001ef0fc end=0x001ef1ac symbol=FUN_001ef0fc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Self {
    char pad0[0x40];
    int mode;
    char pad1[0x514 - 0x44];
    unsigned char flag;
    char pad2[0x564 - 0x515];
    void *obj;
} Self;

extern void FUN_001f2934(Self *self);
extern void FUN_001f293c(Self *self);
extern void FUN_001f2944(Self *self);
extern void FUN_001f294c(Self *self);
extern int FUN_001f92ec(Self *self);
extern void FUN_002199c8(void *obj);

void FUN_001ef0fc(Self *self)
{
    if (self->flag == 0)
        return;

    FUN_001f2934(self);

    switch (self->mode) {
    case 1:
        FUN_001f293c(self);
        break;
    case 14:
        FUN_001f2944(self);
        break;
    case 16:
        FUN_001f294c(self);
        break;
    }

    if (FUN_001f92ec(self) != 0) {
        if (self->obj != 0)
            FUN_002199c8(self->obj);
    }
}
