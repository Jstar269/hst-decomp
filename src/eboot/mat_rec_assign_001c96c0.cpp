/* HSTMATCH module=EBOOT.BIN start=0x001c96c0 end=0x001c9750 symbol=FUN_001c96c0 lang=c++ */
/* Clone of src/eboot/mat_rec_assign_000b43e8.cpp (hstclone.py tag c40): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line memberwise copy assignment of a 68-byte record: a 4x4 float matrix (unscheduled lwc1/swc1
   pairs, one per element) followed by a 4-byte integer field (lw/sw; the C candidate with undefined4
   copied it through $f0 too). The implicit `*d = *s` copies with a block loop instead, and a loop over
   the elements is not unrolled. Names provisional. */
struct Rec_001c96c0 {
    float m[16];
    int n;
};
extern "C" Rec_001c96c0 *FUN_001c96c0(Rec_001c96c0 *d, const Rec_001c96c0 *s)
{
    d->m[0] = s->m[0]; d->m[1] = s->m[1]; d->m[2] = s->m[2]; d->m[3] = s->m[3];
    d->m[4] = s->m[4]; d->m[5] = s->m[5]; d->m[6] = s->m[6]; d->m[7] = s->m[7];
    d->m[8] = s->m[8]; d->m[9] = s->m[9]; d->m[10] = s->m[10]; d->m[11] = s->m[11];
    d->m[12] = s->m[12]; d->m[13] = s->m[13]; d->m[14] = s->m[14]; d->m[15] = s->m[15];
    d->n = s->n;
    return d;
}
