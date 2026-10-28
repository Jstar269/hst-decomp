/* HSTMATCH module=EBOOT.BIN start=0x0029a5b0 end=0x0029a660 symbol=FUN_0029a5b0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the global tested first is FUN_002b7d70's argument (Ghidra dropped it, so retail loads it into a0); readability pass; exact match verified; names and types await human review. */

extern int DAT_002ffcc8;
extern char DAT_002ffd3c[];
extern char DAT_002ffd74[];
extern char DAT_002ffda4[];
extern char DAT_002ffdd4[];
extern void FUN_0029a584(const char *, int);
extern int FUN_002b7d70(int);
extern int FUN_002b7d78();
extern int FUN_002b7d90();
extern int FUN_002b7e40();

/* Shuts the ad-hoc network stack down in reverse order of setup, reporting each failed step. */
void FUN_0029a5b0(void)
{
  int status;
  int handler = DAT_002ffcc8; /* handler id registered by the setup function, 0 or less when none */
  
  if (0 < handler) {
    status = FUN_002b7d70(handler);
    if (status < 0) {
      FUN_0029a584(DAT_002ffd3c,status);
    }
    DAT_002ffcc8 = -1;
  }
  status = FUN_002b7d78();
  if (status < 0) {
    FUN_0029a584(DAT_002ffd74,status);
  }
  status = FUN_002b7e40();
  if (status < 0) {
    FUN_0029a584(DAT_002ffda4,status);
  }
  status = FUN_002b7d90();
  if (status < 0) {
    FUN_0029a584(DAT_002ffdd4,status);
  }
}
