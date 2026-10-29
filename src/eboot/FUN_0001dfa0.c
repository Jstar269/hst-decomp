/* HSTMATCH module=EBOOT.BIN start=0x0001dfa0 end=0x0001dfe8 symbol=FUN_0001dfa0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (Sharing twin 0x0001dbec) corrected by hand: the object is a plain `char *` and only the comparison
   casts it to `unsigned char`, so the byte store keeps the raw parameter register (`sb a1,0(a0)`) instead of the masked
   copy of the compare; exact match verified; names and types await human review. */
extern void FUN_0001dd58();

/* Stores value as the first byte when it differs; unless skip_reset is set, then either calls the helper (value 0) or sets the word at +0x84 to 0xffff. */
void FUN_0001dfa0(char *obj, int value, int skip_reset)
{
  if ((unsigned char)value == *(unsigned char *)obj) return;
  *obj = value;
  if (skip_reset == 0) {
    if (value == 0) {
      FUN_0001dd58();
    } else {
      *(unsigned *)(obj + 0x84) = 0xffff;
    }
  }
}
