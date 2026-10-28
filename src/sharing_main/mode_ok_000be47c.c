/* HSTMATCH module=hstp_trans_main.prx start=0x000be47c end=0x000be4b4 symbol=FUN_000be47c lang=c99 */
/* Clone of src/eboot/mode_ok_000bb034.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_002c7b60(int);
extern void FUN_000bd6f0(char *, int);
extern char DAT_0037bb2c;
struct S { char pad[364]; int f16c; };

int FUN_000be47c(struct S *s)
{
    int r = FUN_002c7b60(s->f16c);
    if (r < 0) {
        FUN_000bd6f0(&DAT_0037bb2c, r);
        return 0;
    }
    return 1;
}
