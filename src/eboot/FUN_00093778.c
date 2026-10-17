/* HSTMATCH module=EBOOT.BIN start=0x00093778 end=0x000937a0 symbol=FUN_00093778 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x58]; void *p; } Holder;
extern void FUN_00058ddc(void *p);

void FUN_00093778(Holder *x)
{
    if (x->p != 0) FUN_00058ddc(x->p);
}
