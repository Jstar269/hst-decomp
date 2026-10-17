/* HSTMATCH module=hstp_trans_main.prx start=0x0013c714 end=0x0013c750 symbol=FUN_0013c714 */
/* Clone of src/eboot/FUN_0013115c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[0x78]; unsigned char busy; } Child78;
typedef struct { char pad[0x80]; Child78 *child; int pad84; int a; int b; } Parent80;
extern void FUN_0001ef14(Child78 *c, int v);

void FUN_0013c714(Parent80 *p)
{
    FUN_0001ef14(p->child, 0);
    p->child->busy = 0;
    p->a = 0;
    p->b = 0;
}
