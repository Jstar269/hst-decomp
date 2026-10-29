/* HSTMATCH module=hstp_trans_main.prx start=0x000df55c end=0x000df5b4 symbol=FUN_000df55c lang=c99 */
/* Clone of src/eboot/FUN_000db59c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_000df4ac();

/* Deleting destructor: run the destructor body, free the memory when delete_flag is positive. */
int FUN_000df55c(int self,short delete_flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_000df4ac(self,-1);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
