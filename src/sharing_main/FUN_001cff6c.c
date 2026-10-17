/* HSTMATCH module=hstp_trans_main.prx start=0x001cff6c end=0x001cff88 symbol=FUN_001cff6c */
/* Clone of src/eboot/FUN_001c1d58.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x20]; int field; } Global20;
extern Global20 *DAT_003ea8e8;
int *FUN_001cff6c(void) { int *r = 0; Global20 *g = DAT_003ea8e8; if (g) r = &g->field; return r; }
