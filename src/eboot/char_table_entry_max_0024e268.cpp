/* HSTMATCH module=EBOOT.BIN start=0x0024e268 end=0x0024e2d0 symbol=FUN_0024e268 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int DAT_002fbefc;

/* const-reference Max returning the reference (retail selects between the global and a stack slot) */
static inline const int &Max(const int &a, const int &b) { return a < b ? b : a; }

/* Reads a signed byte from a table of 0x60-byte groups of 6-byte entries (byte at +4 of the entry), minus 1,
   floored at DAT_002fbefc.  Matching idiom: group base and entry offset built with separate `+=` statements
   (the single-expression sum gives the other addu operand order). */
extern "C" int FUN_0024e268(int param_1, int param_2, int param_3)
{
    unsigned char sel = (param_2 != 0) ^ 1;
    int base = sel * 0x60;
    base += param_1;
    int off = param_3 * 6;
    off += base;
    int v = *(char *)(off + 4) - 1;
    return Max(v, DAT_002fbefc);
}
