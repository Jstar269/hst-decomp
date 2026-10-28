/* HSTMATCH module=EBOOT.BIN start=0x000bb034 end=0x000bb06c symbol=FUN_000bb034 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_002b7dd8(int);
extern void FUN_000ba3ac(char *, int);
extern char DAT_002d5220;
struct S { char pad[364]; int f16c; };

int FUN_000bb034(struct S *s)
{
    int r = FUN_002b7dd8(s->f16c);
    if (r < 0) {
        FUN_000ba3ac(&DAT_002d5220, r);
        return 0;
    }
    return 1;
}
