/* HSTMATCH module=hstp_trans_main.prx start=0x0015bb94 end=0x0015bbd4 symbol=FUN_0015bb94 */
/* Clone of src/eboot/FUN_0014fb68.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
typedef struct { int pad0, pad4; int a; int b; } Src14f;
typedef struct { int pad0, pad4, pad8; void *h; } Dst14f;
extern void FUN_002985fc(void *h, int a1, int a2, int a3, int a4, int a5, int a6, int a7);

int FUN_0015bb94(Src14f *s, Dst14f *d)
{
    FUN_002985fc(d->h, 0, 0, 0, s->a, s->b, 0, 0);
    return 0;
}
