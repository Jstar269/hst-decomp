/* HSTMATCH module=hstp_trans_main.prx start=0x001c6ccc end=0x001c6d00 symbol=FUN_001c6ccc lang=c99 */
/* Clone of src/eboot/shutdown_calls_001b8cf8.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the two numeric addresses (DAT_0039157f + 1, 0x3eaad8) are written as address-named externs (DAT_00391580, DAT_003eaad8); exact match verified; names and types await human review. */
extern char DAT_00391580[];
extern char DAT_003eaad8[];
extern void FUN_00000020(char *);
extern void FUN_00000028(void);
extern void FUN_001c1edc(char *);

void FUN_001c6ccc(void)
{
  FUN_00000020(DAT_00391580);
  FUN_001c1edc(DAT_003eaad8);
  FUN_00000028();
}
