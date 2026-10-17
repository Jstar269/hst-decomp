/* HSTMATCH module=EBOOT.BIN start=0x000c81ec end=0x000c825c symbol=FUN_000c81ec */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x3c]; void *a; void *b; void *pad44; void *c; void *d; void *e; void *f; void *g; } Res3c;
extern void FUN_0001f21c(Res3c *r, void *h);

void FUN_000c81ec(Res3c *r)
{
    FUN_0001f21c(r, r->a);
    FUN_0001f21c(r, r->b);
    FUN_0001f21c(r, r->c);
    FUN_0001f21c(r, r->d);
    FUN_0001f21c(r, r->e);
    FUN_0001f21c(r, r->f);
    FUN_0001f21c(r, r->g);
}
