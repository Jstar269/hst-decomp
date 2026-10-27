/* HSTMATCH module=EBOOT.BIN start=0x00049244 end=0x000492b8 symbol=FUN_00049244 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002d0734, DAT_002d072c; extern void FUN_002b78e8(int h); extern void FUN_00000a00(void *p);
void *FUN_00049244(void *p, short n) { if (p) { FUN_002b78e8(DAT_002d0734); DAT_002d0734 = -1; FUN_002b78e8(DAT_002d072c); DAT_002d072c = -1; if (n > 0) FUN_00000a00(p); } return p; }
