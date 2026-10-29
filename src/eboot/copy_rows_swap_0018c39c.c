/* HSTMATCH module=EBOOT.BIN start=0x0018c39c end=0x0018c4dc symbol=FUN_0018c39c lang=c99 */
/* Hand-written reconstruction (external matching lane): the two copies are guarded by
   `if (bufB != 0) { if (bufA != 0) {...} } else { <table check> }` so the bufB==0 block is laid
   out last; each row walk is `if (0 < height) { do { width = stride; .. } while (row >= 0 && row < height); }`
   with the stride load at the TOP of the body, which is what puts the reload in the bnezl delay slot.
   Exact match verified; names and types await human review. */
extern int DAT_0034156c[];
extern int DAT_00341530[];
extern int FUN_00051450(int);
extern void FUN_00011090(int, int, int);

typedef struct RowSurface {
    char pad0[0x48];
    int width;                          /* 0x48 pixels per row (2 bytes each) */
    int height;                         /* 0x4c rows */
    char pad50[0x7c - 0x50];
    int (*getBufA)(int index, int variant); /* 0x7c */
    int (*getBufB)(int index, int variant); /* 0x80 */
} RowSurface;

/* Copies the rows into the target's pixels from buffer A; with no buffer B they come from the table entry for `index`. */
void FUN_0018c39c(RowSurface *self, int target, int index, int variant)
{
    int bufA;
    int bufB;
    int offset;
    int width;
    int row;

    bufA = self->getBufA(index, variant);
    bufB = self->getBufB(index, variant);
    if (bufB != 0) {
        if (bufA != 0) {
            bufB = FUN_00051450(target);
            row = 0;
            if (0 < self->height) {
                do {
                    width = self->width;
                    offset = row * width * 2;
                    FUN_00011090(bufB + offset, bufA + offset, width << 1);
                    row = row + 1;
                } while (row < self->height);
            }
        }
    } else {
        if (DAT_0034156c[index] != 0) {
            bufB = DAT_00341530[index];
            bufA = FUN_00051450(target);
            row = 0;
            if (0 < self->height) {
                do {
                    width = self->width;
                    offset = row * width * 2;
                    FUN_00011090(bufA + offset, bufB + offset, width << 1);
                    row = row + 1;
                } while (row < self->height);
            }
        }
    }
}
