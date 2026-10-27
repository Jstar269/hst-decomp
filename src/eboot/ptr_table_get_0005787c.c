/* HSTMATCH module=EBOOT.BIN start=0x0005787c end=0x000578c0 symbol=FUN_0005787c lang=c99 */
/* Clone of src/sharing_main/ptr_table_get_000584d0.c (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Bounds-checked lookup in a pointer table at +0xe0 (count at +0xe4, unsigned compare): returns the first word of entry i or 0. Nested ifs with one shared trailing `return 0` give retail's `bltzl a1; move v0,zero` first test and the later tests branching to the separate zero block. */
typedef struct Entry {
    void *value;
} Entry;

typedef struct Owner {
    char pad0[0xe0];
    Entry **entries;  /* 0xe0 */
    unsigned count;   /* 0xe4 */
} Owner;

void *FUN_0005787c(Owner *o, int i)
{
    if (i >= 0) {
        if (i < o->count) {
            Entry *e = o->entries[i];
            if (e != 0)
                return e->value;
        }
    }
    return 0;
}
