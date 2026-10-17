/* HSTMATCH module=EBOOT.BIN start=0x00179700 end=0x0017970c symbol=FUN_00179700 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x2e0]; int field; } Inner2e0;
typedef struct { char pad[0x17c]; Inner2e0 *inner; } Outer17c;

int *FUN_00179700(Outer17c *o)
{
    return &o->inner->field;
}
