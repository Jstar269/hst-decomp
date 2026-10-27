/* HSTMATCH module=hstp_trans_main.prx start=0x0005848c end=0x000584d0 symbol=FUN_0005848c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct SlotTable {
    char pad[0xe0];
    void **slots;       /* 0xe0 */
    unsigned int count; /* 0xe4 */
} SlotTable;

/* Bounds-checked slot read: the stored pointer, or 0 for a bad index or an empty slot. */
void *FUN_0005848c(SlotTable *table, int index)
{
    if (index >= 0 && (unsigned int)index < table->count) {
        void *p = table->slots[index];
        if (p != 0) {
            return p;
        }
    }
    return 0;
}
