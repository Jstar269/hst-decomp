/* HSTMATCH module=EBOOT.BIN start=0x0024e268 end=0x0024e2d0 symbol=FUN_0024e268 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int DAT_002fbefc;

/* const-reference Max returning the reference (retail selects between the global and a stack slot) */
static inline const int &Max(const int &a, const int &b) { return a < b ? b : a; }

#define GROUP_SIZE 0x60       /* bytes per group */
#define ENTRY_SIZE 6          /* bytes per entry */
#define ENTRY_VALUE_OFFSET 4  /* signed byte read from each entry */

/* Reads a signed byte from a table of GROUP_SIZE-byte groups of ENTRY_SIZE-byte entries, minus 1,
   floored at DAT_002fbefc.  Matching idiom: group base and entry offset built with separate `+=` statements
   (the single-expression sum gives the other addu operand order). */
extern "C" int FUN_0024e268(int table, int use_first_group, int index)
{
    unsigned char sel = (use_first_group != 0) ^ 1;
    int base = sel * GROUP_SIZE;
    base += table;
    int off = index * ENTRY_SIZE;
    off += base;
    int v = *(char *)(off + ENTRY_VALUE_OFFSET) - 1;
    return Max(v, DAT_002fbefc);
}
