/* HSTMATCH module=EBOOT.BIN start=0x000ce70c end=0x000ce72c symbol=FUN_000ce70c lang=c99 data=0x002d62bc */
/* LoadMenuParticleLists: data/menu/game_eff/particle/{texlist,motlist}.csv; see docs/DATA-TABLES.md Data: its string literals (2 strings, 0x002d62bc-0x002d630c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

extern void FUN_00067e54();

void FUN_000ce70c(void)
{
  FUN_00067e54("data/menu/game_eff/particle/texlist.csv",
               "data/menu/game_eff/particle/motlist.csv",0x10,0,0);
}
