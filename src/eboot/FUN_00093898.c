/* HSTMATCH module=EBOOT.BIN start=0x00093898 end=0x000938b8 symbol=FUN_00093898 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x84]; float scale; } Scaled;
typedef struct { char pad[0x58]; Scaled *s; } ScaledRef;

float FUN_00093898(ScaledRef *r)
{
    return r->s ? r->s->scale : 1.0f;
}
