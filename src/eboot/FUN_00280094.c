/* HSTMATCH module=EBOOT.BIN start=0x00280094 end=0x002800a0 symbol=FUN_00280094 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x10]; int value; } V10;
extern void FUN_00253974(int kind, int value);

void FUN_00280094(V10 *v)
{
    FUN_00253974(4, v->value);
}
