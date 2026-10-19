/* HSTMATCH module=hstp_trans_main.prx start=0x000eebe4 end=0x000eec24 symbol=FUN_000eebe4 lang=c99 */
/* Clone of src/eboot/decay_timer_000e9b10.c (hstclone.py tag ds1018ar2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S {
    char pad[0x5f0];
    float f5f0;
    int f5f4;
    int f5f8;
    int f5fc;
};

void FUN_000eebe4(struct S *s)
{
    if (s->f5f4 > s->f5fc - 20) {
        s->f5f0 = s->f5f0 - 0.1f;
    }
    s->f5f4++;
}
