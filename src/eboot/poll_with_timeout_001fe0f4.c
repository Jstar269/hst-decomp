/* HSTMATCH module=EBOOT.BIN start=0x001fe0f4 end=0x001fe178 symbol=FUN_001fe0f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: type the callback result as int and preserve its negated condition through the polling loop; readability pass; exact match verified; names and types await human review. */
#define POLL_DELAY 100000
#define POLL_MAX_TRIES 100

extern unsigned char DAT_0034a140;
extern int FUN_00049094(int);
extern void FUN_002b7958(int);

/* Without the flag, polls (up to POLL_MAX_TRIES times) until the check succeeds; with it, only sets the global flag. */
void FUN_001fe0f4(int set_flag)
{
  int not_ready;
  int tries;

  if (set_flag == 0) {
    tries = 0;
    not_ready = !FUN_00049094(1);
    while (not_ready != 0) {
      FUN_002b7958(POLL_DELAY);
      tries++;
      if (tries > POLL_MAX_TRIES)
        return;
      not_ready = !FUN_00049094(1);
    }
  } else {
    DAT_0034a140 = 1;
  }
}
