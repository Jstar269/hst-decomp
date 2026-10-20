/* HSTMATCH module=hstp_trans_main.prx start=0x001013cc end=0x00101428 symbol=FUN_001013cc lang=c99 */
/* Clone of src/eboot/advance_counter_000fbc90.c (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0x4c]; unsigned char flag; } Cfg;
typedef struct {
    unsigned char pad0[0x3c];
    int f3c;
    unsigned char pad1[0x18];
    unsigned char f58;
    unsigned char pad2[3];
    int f5c;
} Self;

extern Cfg *DAT_003e19f0;
extern int DAT_0037f098;

void FUN_001013cc(Self *s)
{
    if (DAT_003e19f0->flag == 0) return;
    if (s->f3c == 0) return;
    if (s->f58 == 0) return;
    s->f5c = (s->f5c + 1) % (DAT_0037f098 * 6);
}
