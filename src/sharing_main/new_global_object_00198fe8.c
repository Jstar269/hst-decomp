/* HSTMATCH module=hstp_trans_main.prx start=0x00198fe8 end=0x00199028 symbol=FUN_00198fe8 lang=c99 */
/* Clone of src/eboot/new_global_object_0018c808.c (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the result variable is the allocation pointer itself (`p = ctor(p)` under the null check, no separate `r = 0`), which removes the extra move and gives the delay-slot nop; exact match verified; names and types await human review. */
/* Allocates a 0x979c0-byte object (operator new 0xbcc), constructs it with 0x18c704 and stores it in a global. */
extern int DAT_003ea8e8;
extern int FUN_00000bcc(int);
extern int FUN_00198ee4(int);

void FUN_00198fe8(void)
{
  int p = FUN_00000bcc(0x979c0);
  if (p != 0) {
    p = FUN_00198ee4(p);
  }
  DAT_003ea8e8 = p;
}
