/* HSTMATCH module=hstp_trans_main.prx start=0x000cbd8c end=0x000cbdfc symbol=FUN_000cbd8c */
/* Clone of src/eboot/FUN_000c81ec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[0x3c]; void *a; void *b; void *pad44; void *c; void *d; void *e; void *f; void *g; } Res3c;
extern void FUN_0001ef34(Res3c *r, void *h);

void FUN_000cbd8c(Res3c *r)
{
    FUN_0001ef34(r, r->a);
    FUN_0001ef34(r, r->b);
    FUN_0001ef34(r, r->c);
    FUN_0001ef34(r, r->d);
    FUN_0001ef34(r, r->e);
    FUN_0001ef34(r, r->f);
    FUN_0001ef34(r, r->g);
}
