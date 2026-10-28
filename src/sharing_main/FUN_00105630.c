/* HSTMATCH module=hstp_trans_main.prx start=0x00105630 end=0x0010565c symbol=FUN_00105630 lang=c99 */
/* Clone of src/eboot/FUN_000ffcfc.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned short u16;
typedef struct Ent {
    u16 f0, f2, f4, f6;
} Ent;
typedef struct Self {
    char pad0[12];
    u16 f0c;                     /* 12 */
    char pad1[80 - 14];
    Ent *tbl;                    /* 80 */
} Self;
u16 FUN_00105630(Self *self, int i)
{
    Ent *t = self->tbl;

    return t != 0 ? (u16)(t[i].f6 - t[i].f2) : self->f0c;
}
