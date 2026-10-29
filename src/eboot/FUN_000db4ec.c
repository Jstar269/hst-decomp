/* HSTMATCH module=EBOOT.BIN start=0x000db4ec end=0x000db544 symbol=FUN_000db4ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_000dae5c();

/* Deleting destructor: run the destructor body, free the memory when delete_flag is positive. */
int FUN_000db4ec(int self,short delete_flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_000dae5c(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
