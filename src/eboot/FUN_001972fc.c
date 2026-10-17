/* HSTMATCH module=EBOOT.BIN start=0x001972fc end=0x00197318 symbol=FUN_001972fc */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x1bc]; int value; } Global1bc;
extern Global1bc *DAT_00341768;

void FUN_001972fc(void)
{
    if (DAT_00341768) DAT_00341768->value = 0;
}
