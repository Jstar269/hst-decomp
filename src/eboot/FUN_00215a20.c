/* HSTMATCH module=EBOOT.BIN start=0x00215a20 end=0x00215a58 symbol=FUN_00215a20 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char d[0x230]; } Item230;
typedef struct { char pad[0x14]; Item230 *items; char pad2[8]; } Rec20;
typedef struct { char pad[0x158]; int rec; int pad2; int item; } Sel158;
extern Rec20 *DAT_0034a6ac;
Item230 *FUN_00215a20(Sel158 *s) { Rec20 *r = &DAT_0034a6ac[s->rec]; return &r->items[s->item]; }
