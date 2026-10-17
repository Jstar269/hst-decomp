/* HSTMATCH module=hstp_trans_main.prx start=0x00098e9c end=0x00098ee4 symbol=FUN_00098e9c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: the flag logic is one `!(a || b)` over two calls and the byte return is really an int (no andi 0xff), as in the matched EBOOT twin src/eboot/neither_query_2_3_00096d64.c; exact match verified; names and types await human review. */
/* True when neither query 2 nor query 3 holds for the object behind DAT_003e1e84. Twin of 0x98e54 (queries 1 and 3). */
extern void *DAT_003e1e84;
extern int FUN_000dfc74(void *, int);

int FUN_00098e9c(void)
{
  return !(FUN_000dfc74(DAT_003e1e84, 2) || FUN_000dfc74(DAT_003e1e84, 3));
}
