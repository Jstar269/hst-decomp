/* HSTMATCH module=hstp_trans_main.prx start=0x00100f4c end=0x00100fa4 symbol=FUN_00100f4c lang=c99 */
/* Clone of src/eboot/FUN_000fb810.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: stored and returned the field directly around the constructor call instead of keeping a separate result temporary; exact match verified; names and types await human review. */
extern int FUN_00000bcc(unsigned int);
extern int FUN_0020aa34(int, int);
extern void FUN_0001ef34(int, int);
int FUN_00100f4c(int self) {
  if (*(int *)(self + 0x40) == 0) {
    int object = FUN_00000bcc(0x58);
    if (object != 0) object = FUN_0020aa34(object, 0);
    *(int *)(self + 0x40) = object;
    FUN_0001ef34(self, object);
  }
  return *(int *)(self + 0x40);
}
