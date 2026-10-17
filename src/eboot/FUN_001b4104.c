/* HSTMATCH module=EBOOT.BIN start=0x001b4104 end=0x001b4130 symbol=FUN_001b4104 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x7ac]; int handle; } Owner7ac;
typedef struct { Owner7ac *owner; } Ref7ac;
extern void FUN_000628e4(int handle, int mode);

void FUN_001b4104(Ref7ac *r)
{
    int h = r->owner->handle;
    if (h >= 0) FUN_000628e4(h, 0);
}
