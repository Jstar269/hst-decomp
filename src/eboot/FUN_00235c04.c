/* HSTMATCH module=EBOOT.BIN start=0x00235c04 end=0x00235c84 symbol=FUN_00235c04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00165840();

/* Destructor: tears down the part at 0xc and the part at 0, then frees the object if delete_flag > 0. */
int FUN_00235c04(int self,short delete_flag)
{
  int part;
  
  if (self != 0) {
    part = self + 0xc;
    if ((part != 0) && (part != 0)) {
      FUN_00165840(part,0);
    }
    if ((self != 0) && (self != 0)) {
      FUN_00165840(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
