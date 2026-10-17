/* HSTMATCH module=EBOOT.BIN start=0x0018b8f8 end=0x0018b944 symbol=FUN_0018b8f8 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[60]; int value; char rest[0x2000 - 64]; } Slot18b;
typedef struct { Slot18b slots[4]; } Row18b;

int *FUN_0018b8f8(Row18b *rows, int row, int slot)
{
    if (row >= 0 && row < 15 && slot >= 0 && slot < 4) return &rows[row].slots[slot].value;
    return 0;
}
