/* HSTMATCH module=hstp_trans_main.prx start=0x002b61d0 end=0x002b62c0 symbol=FUN_002b61d0 lang=c99 */
/* Clone of src/eboot/timer_value_refresh_002a6a40.c (hstclone.py tag c055807): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
struct Child {
    unsigned char pad0[0x24];
    int a;
    int b;
};
typedef struct {
    unsigned char pad0[0xbc];
    struct Child *child;
    unsigned char pad1[0xb8];
    void *owner;
    unsigned char pad2[0x708];
    int count;
    unsigned char pad3[0xe74];
    int offset;
} Self;

extern int DAT_003a9ef0;
extern int DAT_003a9b90[];
extern void *DAT_003f46a0;
extern char DAT_003eaad8;

extern void FUN_002b5430(Self *);
extern void FUN_001bfc3c(void *, int);
extern void FUN_00111aa4(void *, int, int);
extern int FUN_0020d1e0(int, int, int);
extern void FUN_0011988c(void *, int, int);
extern void FUN_00105470(struct Child *, int);
extern void FUN_00108a2c(Self *);

void FUN_002b61d0(Self *self)
{
    int n = self->count;

    FUN_002b5430(self);
    if (n != self->count) {
        FUN_001bfc3c(&DAT_003eaad8, 1);
        n = self->count;
        FUN_00111aa4(self->owner, n, 0);
        if (DAT_003f46a0 != 0) {
            int id = DAT_003a9b90[n];
            int v = FUN_0020d1e0(18, 49, id);
            FUN_0011988c(DAT_003f46a0, v, 0);
        }
    }
    if (self->offset >= 0) {
        FUN_00105470(self->child, 0);
        int d = DAT_003a9ef0 + 2 - self->offset;
        struct Child *c = self->child;

        c->a = d;
        c->b = d;
    } else {
        FUN_00105470(self->child, 1);
    }
    FUN_00108a2c(self);
}
// Near miss: 61 words vs retail's 60, 13 differ from +0x94; retail reloads self->child for the second store (a store through child may alias the field) instead of keeping it in v0.
// near miss from lane ds8 (unreviewed)
