/* HSTMATCH module=hstp_trans_main.prx start=0x00049084 end=0x000490c8 symbol=FUN_00049084 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: expressed the byte selector as a switch and materialized the helper result before comparison; exact match verified; names and types await human review. */
typedef unsigned char bool;
typedef unsigned char undefined;
extern int DAT_00375e90;
extern undefined DAT_003ba480;
extern int FUN_002c75b8();
bool FUN_00049084(void)
{
  int expected;
  int result;
  switch (DAT_003ba480) {
    case 0: expected = -1; break;
    default: expected = DAT_00375e90; break;
  }
  result = FUN_002c75b8();
  return result == expected;
}
