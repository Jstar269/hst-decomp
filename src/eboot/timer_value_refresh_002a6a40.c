/* HSTMATCH module=EBOOT.BIN start=0x002a6a40 end=0x002a6b30 symbol=FUN_002a6a40 lang=c99 */
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

extern int DAT_00300e54;
extern int DAT_00300af4[];
extern void *DAT_0034b354;
extern char DAT_0034179c;

extern void FUN_002a5ca0(Self *);
extern void FUN_001b1c44(void *, int);
extern void FUN_0010b8cc(void *, int, int);
extern int FUN_001fea10(int, int, int);
extern void FUN_00110a78(void *, int, int);
extern void FUN_000ffb3c(struct Child *, int);
extern void FUN_00103128(Self *);

/* Refresh after a count change (sound, owner update, value lookup), then apply the signed offset to the child's two values. */
void FUN_002a6a40(Self *self)
{
    int prev_count = self->count;

    FUN_002a5ca0(self);
    if (prev_count != self->count) {
        FUN_001b1c44(&DAT_0034179c, 1);
        prev_count = self->count;
        FUN_0010b8cc(self->owner, prev_count, 0);
        if (DAT_0034b354 != 0) {
            int id = DAT_00300af4[prev_count];
            int value = FUN_001fea10(18, 49, id);
            FUN_00110a78(DAT_0034b354, value, 0);
        }
    }
    if (self->offset >= 0) {
        FUN_000ffb3c(self->child, 0);
        int shifted = DAT_00300e54 + 2 - self->offset;
        struct Child *child = self->child;

        child->a = shifted;
        child->b = shifted;
    } else {
        FUN_000ffb3c(self->child, 1);
    }
    FUN_00103128(self);
}
// Near miss: 61 words vs retail's 60, 13 differ from +0x94; retail reloads self->child for the second store (a store through child may alias the field) instead of keeping it in v0.
// near miss from lane ds8 (unreviewed)
