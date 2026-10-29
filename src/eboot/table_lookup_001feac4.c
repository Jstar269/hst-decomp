/* HSTMATCH module=EBOOT.BIN start=0x001feac4 end=0x001fec00 symbol=FUN_001feac4 lang=c99 data=0x002ef0a0 */
/* Hand-written reconstruction from the disassembly; exact match verified (79/79 words).
   Two-level lookup: kind 2/3 -> record 0xc, kind 1 -> record 7, anything else returns the
   default string; the shared body is a static inline helper inlined twice (retail has two
   copies, and only the kind-12 copy is shared by its two case labels, which is why the
   `kind == 2 || kind == 3` spelling is wrong: it folds to a range check -- a switch
   with grouped case 2/case 3 keeps the two compares and the shared entry). The index test
   needs `int idx = id & 0xffff;` (a `short` local costs a seh before both compares) and the
   `||` guard with the in-condition assignment is what keeps `l`'s load behind the bltz and
   the andi in the branch delay slot. Names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x002ef0a0-0x002ef0ac) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
typedef struct {
    int *items;
    int count;
} List;

typedef struct {
    char pad0[8];
    int count;  /* 0x08 */
} Header;

typedef struct {
    char pad0[4];
    int ready;       /* 0x04 */
    Header *header;  /* 0x08 */
    List *list;      /* 0x0c */
} Entry;

extern char DAT_002c0e18[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e20[];
char *DAT_002ef0a8 = "TEST";
extern Entry *FUN_0018c9f4(int);

/* Entry kinds handled by FUN_001feac4. */
enum { KIND_SHORT = 1, KIND_LONG_A = 2, KIND_LONG_B = 3, TABLE_SHORT = 7, TABLE_LONG = 0xc };

static inline char *Lookup(int table, unsigned id)
{
    Entry *entry;
    int idx;
    List *l;

    entry = FUN_0018c9f4(table);
    if (entry->ready == 0)
        return DAT_002c0e20;
    if (entry->header->count <= 0)
        return DAT_002c0e1c;
    idx = id & 0xffff;
    if (idx < 0 || idx >= (l = entry->list)->count)
        return DAT_002c0e18;
    return (char *)l->items[idx];
}

char *FUN_001feac4(unsigned char kind, unsigned id)
{
    switch (kind) {
    case KIND_SHORT:
        return Lookup(TABLE_SHORT, id);
    case KIND_LONG_B:
    case KIND_LONG_A:
        return Lookup(TABLE_LONG, id);
    }
    return DAT_002ef0a8;
}
