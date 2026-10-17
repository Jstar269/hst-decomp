/* HSTMATCH module=hstp_trans_main.prx start=0x0025e4a0 end=0x0025e508 symbol=FUN_0025e4a0 lang=c++ */
/* Clone of src/eboot/char_table_entry_max_0024e268.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int DAT_003a4910;

/* const-reference Max returning the reference (retail selects between the global and a stack slot) */
static inline const int &Max(const int &a, const int &b) { return a < b ? b : a; }

/* Reads a signed byte from a table of 0x60-byte groups of 6-byte entries (byte at +4 of the entry), minus 1,
   floored at DAT_003a4910.  Matching idiom: group base and entry offset built with separate `+=` statements
   (the single-expression sum gives the other addu operand order). */
extern "C" int FUN_0025e4a0(int param_1, int param_2, int param_3)
{
    unsigned char sel = (param_2 != 0) ^ 1;
    int base = sel * 0x60;
    base += param_1;
    int off = param_3 * 6;
    off += base;
    int v = *(char *)(off + 4) - 1;
    return Max(v, DAT_003a4910);
}
