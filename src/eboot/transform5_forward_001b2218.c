/* HSTMATCH module=EBOOT.BIN start=0x001b2218 end=0x001b2240 symbol=FUN_001b2218 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_001b2240(int, int, int, int, int, int, float, float, float, float);
extern float DAT_002e9908, DAT_002e990c, DAT_002e9910, DAT_002e9914;

/* Positional update with the default blend values (four globals) and no explicit position. */
int FUN_001b2218(int self, int handle_ref, int ref_pos, int out_volume, int fold)
{
    return FUN_001b2240(self, handle_ref, ref_pos, out_volume, fold, 0,
                        DAT_002e9908, DAT_002e990c, DAT_002e9910, DAT_002e9914);
}
