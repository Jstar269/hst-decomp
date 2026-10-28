/* HSTMATCH module=EBOOT.BIN start=0x000ffcfc end=0x000ffd28 symbol=FUN_000ffcfc lang=c99 */
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
u16 FUN_000ffcfc(Self *self, int i)
{
    Ent *t = self->tbl;

    return t != 0 ? (u16)(t[i].f6 - t[i].f2) : self->f0c;
}
