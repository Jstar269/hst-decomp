/* HSTMATCH module=EBOOT.BIN start=0x001b8fac end=0x001b8fe0 symbol=FUN_001b8fac lang=c99 */
/* Clone of src/eboot/shutdown_calls_001b8cf8.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the two numeric addresses (DAT_002e99c3 + 1, 0x34179c) are written as address-named externs (DAT_002e99c4, DAT_0034179c); exact match verified; names and types await human review. */
extern char DAT_002e99c4[];
extern char DAT_0034179c[];
extern void FUN_00000020(char *);
extern void FUN_00000028(void);
extern void FUN_001b3b34(char *);

void FUN_001b8fac(void)
{
  FUN_00000020(DAT_002e99c4);
  FUN_001b3b34(DAT_0034179c);
  FUN_00000028();
}
