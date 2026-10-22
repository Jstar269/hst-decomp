/* HSTMATCH module=EBOOT.BIN start=0x0001dfa0 end=0x0001dfe8 symbol=FUN_0001dfa0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (Sharing twin 0x0001dbec) corrected by hand: the object is a plain `char *` and only the comparison
   casts it to `unsigned char`, so the byte store keeps the raw parameter register (`sb a1,0(a0)`) instead of the masked
   copy of the compare; exact match verified; names and types await human review. */
extern void FUN_0001dd58();

void FUN_0001dfa0(char *param_1, int param_2, int param_3)
{
  if ((unsigned char)param_2 == *(unsigned char *)param_1) return;
  *param_1 = param_2;
  if (param_3 == 0) {
    if (param_2 == 0) {
      FUN_0001dd58();
    } else {
      *(unsigned *)(param_1 + 0x84) = 0xffff;
    }
  }
}
