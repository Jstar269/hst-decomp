/* HSTMATCH module=hstp_trans_main.prx start=0x00046954 end=0x0004699c symbol=FUN_00046954 lang=c99 */
/* Clone of src/eboot/set_state_flags_00046880.c (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern unsigned char DAT_003ba329;
extern unsigned char DAT_003b8ec6;

int FUN_00046954(int unused, int a1)
{
  if (a1 == 2 || a1 < 0) {
    DAT_003ba329 = 1;
    DAT_003b8ec6 = 1;
  }
  if (a1 == 1) {
    DAT_003b8ec6 = 1;
  }
  return 0;
}
