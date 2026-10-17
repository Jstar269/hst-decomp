/* HSTMATCH module=hstp_trans_main.prx start=0x001605d0 end=0x00160624 symbol=FUN_001605d0 */
/* Clone of src/eboot/FUN_00154288.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
typedef struct { int pad0, pad4; void *a; void *b; } Pair154;
extern unsigned char DAT_003e9630;
extern char DAT_00383d74[];
extern void FUN_00158b2c(void *p);
extern void FUN_0015bb68(const char *fmt, void *b);
extern void FUN_0029a168(void *a, void *b);

int FUN_001605d0(Pair154 *s, void *p)
{
    if (DAT_003e9630) {
        FUN_00158b2c(p);
        FUN_0015bb68(DAT_00383d74, s->b);
    }
    FUN_0029a168(s->a, s->b);
    return 0;
}
