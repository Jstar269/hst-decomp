/* HSTMATCH module=EBOOT.BIN start=0x000d9910 end=0x000d9968 symbol=FUN_000d9910 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_000d9f40();

/* Element destructor: tear down obj, free it when flag > 0. */
int FUN_000d9910(int obj,short flag)
{
  if (obj != 0) {
    if (obj != 0) {
      FUN_000d9f40(obj,0);
    }
    if (0 < flag) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
