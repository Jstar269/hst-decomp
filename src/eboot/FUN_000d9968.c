/* HSTMATCH module=EBOOT.BIN start=0x000d9968 end=0x000d99b8 symbol=FUN_000d9968 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_00004138();

/* Destroy obj (destructor called with -1), free it when flag > 0. */
int FUN_000d9968(int obj,short flag)
{
  if ((obj != 0) && (FUN_00004138(obj,0xffffffff), 0 < flag)) {
    FUN_00000a00(obj);
  }
  return obj;
}
