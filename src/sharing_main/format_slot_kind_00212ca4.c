/* HSTMATCH module=hstp_trans_main.prx start=0x00212ca4 end=0x00212d1c symbol=FUN_00212ca4 lang=c99 */
/* Clone of src/eboot/format_slot_kind_0020443c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1) corrected by hand: the or-chain on kind is a switch (case 2..5 -> 99), typed ints; exact match verified; names and types await human review. */
extern char DAT_003976d0[];
extern void FUN_000143b0(int a, char *fmt, int b, int c);

void FUN_00212ca4(int a, int b, int c, int kind)
{
  switch (kind) {
  case 2:
  case 3:
  case 4:
  case 5:
    FUN_000143b0(a, DAT_003976d0, 99, c);
    break;
  default:
    FUN_000143b0(a, DAT_003976d0, b, c);
    break;
  }
}
