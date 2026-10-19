/* HSTMATCH module=hstp_trans_main.prx start=0x002b7738 end=0x002b77ec symbol=FUN_002b7738 lang=c99 */
/* Clone of src/eboot/params_fill_call_002a7fa8.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Src {
    char pad0[0x1c];
    int f1c;
    short s20;
    short s22;
    short s24;
    short s26;
    short s28;
    char f2a;
    char f2b;
    char f2c;
    char f2d;
} Src;

struct Self {
    char pad0[0x10];
    Src *src;
    char pad1[0x1a - 0x14];
    char a1a;
    char a1c;
};

extern void FUN_002b77ec(void *self, char *a, char *b, int c, int d, int *local,
                         int e, int f, int g, int h, int i);

void FUN_002b7738(struct Self *self)
{
    Src *s = self->src;
    int u = *(int *)((char *)s + 0x1c);
    int local[6] = { 0 };

    s = self->src;
    local[0] = *(int *)((char *)s + 0x1c);
    local[1] = s->s20;
    local[2] = s->s22;
    local[3] = s->s24;
    local[4] = s->s26;
    local[5] = s->s28;

    FUN_002b77ec(self, (char *)self + 0x1a, (char *)self + 0x1c, 0, 1, local,
                 s->f2a != 0, s->f2b != 0, s->f2d == 2, s->f2c != 0, u);
}
