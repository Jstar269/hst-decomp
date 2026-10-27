/* HSTMATCH module=EBOOT.BIN start=0x001feac4 end=0x001fec00 symbol=FUN_001feac4 lang=c99 data=0x002ef0a0 */
/* Hand-written reconstruction from the disassembly; exact match verified (79/79 words).
   Two-level lookup: kind 2/3 -> record 0xc, kind 1 -> record 7, anything else returns the
   default string; the shared body is a static inline helper inlined twice (retail has two
   copies, and only the kind-12 copy is shared by its two case labels, which is why the
   `param_1 == 2 || param_1 == 3` spelling is wrong: it folds to a range check -- a switch
   with grouped case 2/case 3 keeps the two compares and the shared entry). The index test
   needs `int idx = id & 0xffff;` (a `short` local costs a seh before both compares) and the
   `||` guard with the in-condition assignment is what keeps `l`'s load behind the bltz and
   the andi in the branch delay slot. Names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x002ef0a0-0x002ef0ac) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
typedef struct {
    int *items;
    int count;
} List;

extern char DAT_002c0e18[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e20[];
char *DAT_002ef0a8 = "TEST";
extern int FUN_0018c9f4(int);

static inline char *Lookup(int kind, unsigned id)
{
    int rec;
    int idx;
    List *l;

    rec = FUN_0018c9f4(kind);
    if (*(int *)(rec + 4) == 0)
        return DAT_002c0e20;
    if (*(int *)(*(int *)(rec + 8) + 8) <= 0)
        return DAT_002c0e1c;
    idx = id & 0xffff;
    if (idx < 0 || idx >= (l = *(List **)(rec + 0xc))->count)
        return DAT_002c0e18;
    return (char *)l->items[idx];
}

char *FUN_001feac4(unsigned char param_1, unsigned param_2)
{
    switch (param_1) {
    case 1:
        return Lookup(7, param_2);
    case 3:
    case 2:
        return Lookup(0xc, param_2);
    }
    return DAT_002ef0a8;
}
