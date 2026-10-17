/* HSTMATCH module=EBOOT.BIN start=0x001c1d58 end=0x001c1d74 symbol=FUN_001c1d58 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x20]; int field; } Global20;
extern Global20 *DAT_003415a8;
int *FUN_001c1d58(void) { int *r = 0; Global20 *g = DAT_003415a8; if (g) r = &g->field; return r; }
