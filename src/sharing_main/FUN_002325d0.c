/* HSTMATCH module=hstp_trans_main.prx start=0x002325d0 end=0x00232608 symbol=FUN_002325d0 */
/* Clone of src/eboot/FUN_00221260.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x58]; unsigned char active; char pad2[7]; int id; } State58;
extern void FUN_00108f54(State58 *s, int v);

void FUN_002325d0(State58 *s)
{
    FUN_00108f54(s, 1);
    s->active = 1;
    s->id = -1;
}
