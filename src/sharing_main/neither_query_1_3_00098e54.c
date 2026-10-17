/* HSTMATCH module=hstp_trans_main.prx start=0x00098e54 end=0x00098e9c symbol=FUN_00098e54 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: the flag logic is one `!(a || b)` over two calls and the byte return is really an int (no andi 0xff), as in the matched EBOOT twin src/eboot/neither_query_1_3_00096d1c.c; exact match verified; names and types await human review. */
/* True when neither query 1 nor query 3 holds for the object behind DAT_003e1e84. Twin of 0x98e9c (queries 2 and 3). */
extern void *DAT_003e1e84;
extern int FUN_000dfc74(void *, int);

int FUN_00098e54(void)
{
  return !(FUN_000dfc74(DAT_003e1e84, 1) || FUN_000dfc74(DAT_003e1e84, 3));
}
