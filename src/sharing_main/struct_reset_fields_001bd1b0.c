/* HSTMATCH module=hstp_trans_main.prx start=0x001bd1b0 end=0x001bd2a8 symbol=FUN_001bd1b0 lang=c99 */
/* Clone of src/eboot/struct_reset_fields_001afad8.c (hstclone.py tag c055807): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct {
    int words[474];
    int f768;
    int f76c;
    int f770;
    int f774;
    int f778;
    int f77c;
    int f780;
    int f784;
    int f788;
    int arr[2];
    int f794;
    unsigned char b798;
    unsigned char b799;
    unsigned char b79a;
    unsigned char b79b;
    int f79c;
    int f7a0;
    int f7a4;
    int f7a8;
    int f7ac;
    int f7b0;
    int f7b4;
    int f7b8;
    int f7bc;
    int f7c0;
    int f7c4;
    int f7c8;
    int f7cc;
    int f7d0;
    float f7d4;
    int f7d8;
    unsigned char b7dc;
    unsigned char b7dd;
} Self;

Self *FUN_001bd1b0(Self *self)
{
    int i;

    for (i = 0; i < 474; i++)
        self->words[i] = 0;
    self->f768 = 0;
    self->f778 = 0;
    self->b798 = 0;
    self->f76c = 0;
    self->f77c = 0;
    self->b799 = 0;
    self->f770 = 0;
    self->f780 = 0;
    self->b79a = 0;
    self->f774 = 0;
    self->f784 = 0;
    self->b79b = 0;
    self->f788 = 0;
    {
        unsigned k = 0;

        do {
            self->arr[k] = 0;
        } while (++k < 2);
    }
    self->f794 = 0;
    self->f79c = -1;
    self->f7a0 = -1;
    self->f7a4 = -1;
    self->f7a8 = -1;
    self->f7ac = -1;
    self->f7b0 = 474;
    self->f7b4 = -1;
    self->f7b8 = 474;
    self->f7bc = -1;
    self->f7c0 = 474;
    self->f7c4 = -1;
    self->f7c8 = 474;
    self->f7cc = 474;
    self->f7d0 = -1;
    self->f7d4 = 1.0f;
    self->f7d8 = -1;
    self->b7dc = 0;
    self->b7dd = 0;
    return self;
}
// Near miss: 57/62 words; the 474-element zeroing loop and the tail field order now line up, but mwcc unrolls the 2-element loop at 0x78c instead of keeping retail's `sltiu` loop.
// near miss from lane ds8 (unreviewed)
