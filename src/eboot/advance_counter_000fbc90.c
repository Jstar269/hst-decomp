/* HSTMATCH module=EBOOT.BIN start=0x000fbc90 end=0x000fbcec symbol=FUN_000fbc90 lang=c99 */
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

extern Cfg *DAT_003386b0;
extern int DAT_002d8278;

void FUN_000fbc90(Self *s)
{
    if (DAT_003386b0->flag == 0) return;
    if (s->f3c == 0) return;
    if (s->f58 == 0) return;
    s->f5c = (s->f5c + 1) % (DAT_002d8278 * 6);
}
