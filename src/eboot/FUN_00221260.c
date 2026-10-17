/* HSTMATCH module=EBOOT.BIN start=0x00221260 end=0x00221298 symbol=FUN_00221260 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x58]; unsigned char active; char pad2[7]; int id; } State58;
extern void FUN_00103628(State58 *s, int v);

void FUN_00221260(State58 *s)
{
    FUN_00103628(s, 1);
    s->active = 1;
    s->id = -1;
}
