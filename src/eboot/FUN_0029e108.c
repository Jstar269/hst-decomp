/* HSTMATCH module=EBOOT.BIN start=0x0029e108 end=0x0029e160 symbol=FUN_0029e108 lang=c99 helpers=FUN_0029a584@0x0029a584-0x0029a5b0 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/near_miss_0029e108.c, completed with its same-file static helper FUN_0029a584 defined in front of it and placed at its own retail address by helpers=); returns the second status (Ghidra's void was wrong: the result stays live in v0 across the stub); exact match verified; names and types await human review. */

extern char DAT_002cb5e8[];
extern char DAT_002cb63c[];
static void FUN_0029a584(...)
{
}
extern int FUN_002b7cc0();

int FUN_0029e108(void)
{
  int iVar1;
  
  iVar1 = FUN_002b7cc0(0x101);
  if (iVar1 < 0) {
    FUN_0029a584(DAT_002cb63c,iVar1);
  }
  iVar1 = FUN_002b7cc0(0x100);
  if (iVar1 < 0) {
    FUN_0029a584(DAT_002cb5e8,iVar1);
  }
  return iVar1;
}
