/* HSTMATCH module=hstp_trans_main.prx start=0x000584d0 end=0x00058514 symbol=FUN_000584d0 lang=c99 */
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

void *FUN_000584d0(Owner *o, int i)
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
