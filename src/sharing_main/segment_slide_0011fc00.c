/* HSTMATCH module=hstp_trans_main.prx start=0x0011fc00 end=0x0011fc80 symbol=FUN_0011fc00 lang=c99 */
/* Clone of src/eboot/segment_slide_00114f38.c (hstclone.py tag c180307): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { short f0; short f2; short f4; short f6; short f8; short f10; } S;

/* Re-centre p on q: move p's 4/6/8/10 shorts by the same deltas, with the f6 step being half of the
   10-vs-6 gap difference. The `*(short *)((char *)q + 6)` form for the second read of q->f6 is load-bearing:
   reading it as `q->f6` lets mwcc keep the value live across the `d / 2` branch and it then differs by one
   word (no reload) with the whole head block permuted. */
void FUN_0011fc00(S *p, S *q)
{
    int d = (short)(q->f10 - q->f6) - (short)(p->f10 - p->f6);
    int half = d / 2;
    short nb = *(short *)((char *)q + 6) + half;
    short d4 = q->f8 - p->f4;
    p->f4 = q->f8;
    p->f8 = p->f8 + d4;
    short d6 = nb - p->f6;
    p->f6 = nb;
    p->f10 = p->f10 + d6;
}
