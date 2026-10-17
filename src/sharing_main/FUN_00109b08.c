/* HSTMATCH module=hstp_trans_main.prx start=0x00109b08 end=0x00109b20 symbol=FUN_00109b08 */
/* Clone of src/eboot/FUN_001041dc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[0x1c]; int a; int b; } Pair1c;
extern const char DAT_0037f89c[];
extern void FUN_00109b20(Pair1c *p, const char *s, int c);

void FUN_00109b08(Pair1c *p, int a, int b, int c)
{
    p->a = a;
    p->b = b;
    FUN_00109b20(p, DAT_0037f89c, c);
}
