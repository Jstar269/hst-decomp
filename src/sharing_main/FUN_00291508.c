/* HSTMATCH module=hstp_trans_main.prx start=0x00291508 end=0x00291514 symbol=FUN_00291508 */
/* Clone of src/eboot/FUN_00280094.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x10]; int value; } V10;
extern void FUN_00263df4(int kind, int value);

void FUN_00291508(V10 *v)
{
    FUN_00263df4(4, v->value);
}
