/* HSTMATCH module=EBOOT.BIN start=0x00057838 end=0x0005787c symbol=FUN_00057838 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct SlotTable {
    char pad[0xe0];
    void **slots;       /* 0xe0 */
    unsigned int count; /* 0xe4 */
} SlotTable;

/* Bounds-checked slot read: the stored pointer, or 0 for a bad index or an empty slot. */
void *FUN_00057838(SlotTable *table, int index)
{
    if (index >= 0 && (unsigned int)index < table->count) {
        void *p = table->slots[index];
        if (p != 0) {
            return p;
        }
    }
    return 0;
}
