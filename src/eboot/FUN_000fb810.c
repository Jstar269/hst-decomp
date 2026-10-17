/* HSTMATCH module=EBOOT.BIN start=0x000fb810 end=0x000fb868 symbol=FUN_000fb810 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: stored and returned the field directly around the constructor call instead of keeping a separate result temporary; exact match verified; names and types await human review. */
extern int FUN_00000bcc(unsigned int);
extern int FUN_001fc31c(int, int);
extern void FUN_0001f21c(int, int);
int FUN_000fb810(int self) {
  if (*(int *)(self + 0x40) == 0) {
    int object = FUN_00000bcc(0x58);
    if (object != 0) object = FUN_001fc31c(object, 0);
    *(int *)(self + 0x40) = object;
    FUN_0001f21c(self, object);
  }
  return *(int *)(self + 0x40);
}
