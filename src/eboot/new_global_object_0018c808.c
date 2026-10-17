/* HSTMATCH module=EBOOT.BIN start=0x0018c808 end=0x0018c848 symbol=FUN_0018c808 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the result variable is the allocation pointer itself (`p = ctor(p)` under the null check, no separate `r = 0`), which removes the extra move and gives the delay-slot nop; exact match verified; names and types await human review. */
/* Allocates a 0x979c0-byte object (operator new 0xbcc), constructs it with 0x18c704 and stores it in a global. */
extern int DAT_003415a8;
extern int FUN_00000bcc(int);
extern int FUN_0018c704(int);

void FUN_0018c808(void)
{
  int p = FUN_00000bcc(0x979c0);
  if (p != 0) {
    p = FUN_0018c704(p);
  }
  DAT_003415a8 = p;
}
