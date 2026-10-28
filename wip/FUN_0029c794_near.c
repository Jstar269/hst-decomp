/* HSTMATCH module=EBOOT.BIN start=0x0029c794 end=0x0029c7d0 symbol=FUN_0029c794 lang=c99 */
extern int FUN_002b7748(int, void *, int);
extern void FUN_0029a584(char *);
extern char DAT_002cb95c;
struct S { char pad[12]; int f0c; };

void FUN_0029c794(struct S *s)
{
    int r = FUN_002b7748(s->f0c, (char *)s + 32, 29696);
    if (r != 0)
        FUN_0029a584(&DAT_002cb95c);
}
// NEAR (9 words, 60 bytes): retail's guard is `beqzl a1` with `lw ra,12(sp)` already in the delay (the
// call result tested in a1, not v0) and the notify call is the last statement before the shared epilogue.
// near miss from lane dsn3 (unreviewed)
