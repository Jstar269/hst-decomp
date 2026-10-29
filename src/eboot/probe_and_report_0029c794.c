/* HSTMATCH module=EBOOT.BIN start=0x0029c794 end=0x0029c7d0 symbol=FUN_0029c794 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_002b7748(int, void *, int);
extern void FUN_0029a584(char *, int);
extern char DAT_002cb95c;
struct S { char pad[12]; int f0c; };

/* The second argument to the notify call is load-bearing: retail's `move a1,v0` before `beqzl a1` is the
   argument move for FUN_0029a584, and the test then reuses a1. Declaring the notify as (char *) makes mwcc
   test v0 directly and the function is one word short (14/15 words). */
void FUN_0029c794(struct S *s)
{
    int r = FUN_002b7748(s->f0c, (char *)s + 32, 29696);
    if (r != 0)
        FUN_0029a584(&DAT_002cb95c, r);
}
