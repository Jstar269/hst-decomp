/* HSTMATCH module=EBOOT.BIN start=0x0016bb5c end=0x0016bb7c symbol=FUN_0016bb5c */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x1054]; int value; } Big1054;
extern Big1054 *FUN_0016bb88(void *a);

int FUN_0016bb5c(void *a)
{
    return FUN_0016bb88(a)->value;
}
