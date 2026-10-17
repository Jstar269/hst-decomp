/* HSTMATCH module=EBOOT.BIN start=0x001c0adc end=0x001c0bcc symbol=FUN_001c0adc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: opt_loop_invariants off and opt_unroll_loops off, nested memset and ctor-clear loops; exact match verified; names and types await human review. */

#pragma opt_unroll_loops off
#pragma opt_loop_invariants off

extern void *FUN_000114c0(void *dst, int val, unsigned int size);

void *FUN_001c0adc(void *self)
{
    char *s0;
    char *s2;
    int *p;
    int i;

    FUN_000114c0((char *)self + 68, 0, 108);
    *(short *)((char *)self + 172) = -1;
    *(short *)((char *)self + 174) = -1;
    *(short *)((char *)self + 104) = -1;

    s0 = (char *)self + 200;
    do {
        s2 = s0 + 8;
        do {
            FUN_000114c0(s2, 0, 12);
            s2 += 12;
        } while (s2 < s0 + 56);
        FUN_000114c0(s0, 0, 56);
        s0 += 56;
    } while (s0 < (char *)self + 1040);

    p = (int *)self;
    i = 0;
    do {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        i += 8;
        p += 8;
    } while (i < 8464);

    *(char *)((char *)self + 188) = 1;
    *(char *)((char *)self + 189) = 0;
    *(int *)((char *)self + 192) = -1;

    return self;
}
