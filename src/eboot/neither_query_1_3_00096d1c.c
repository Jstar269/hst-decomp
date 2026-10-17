/* HSTMATCH module=EBOOT.BIN start=0x00096d1c end=0x00096d64 symbol=FUN_00096d1c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Ghidra's byte return is really an int (no andi 0xff); `!(a || b)` gives the sltu/bnezl/xori shape. Twin of 0x96d64 (query 2 instead of 1). */
extern void *DAT_00338b44;
extern int FUN_000dbc54(void *, int);

int FUN_00096d1c(void)
{
  return !(FUN_000dbc54(DAT_00338b44, 1) || FUN_000dbc54(DAT_00338b44, 3));
}
