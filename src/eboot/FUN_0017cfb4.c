/* HSTMATCH module=EBOOT.BIN start=0x0017cfb4 end=0x0017cfd0 symbol=FUN_0017cfb4 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int pad; int value; } Slot;
typedef struct { int pad; int index; Slot **slots; } SlotList;

void FUN_0017cfb4(SlotList *l, int v)
{
    l->slots[l->index]->value = v;
}
