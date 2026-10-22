/* HSTMATCH module=hstp_trans_main.prx start=0x00048200 end=0x00048250 symbol=FUN_00048200 lang=c99 */
/* Clone of src/eboot/counter_and_dispatch_000480a4.c (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Bumps the global counter at 0x3ba384 and calls the hook installed at 0x3ba2fc when the flag byte at
   0x3ba328 is clear. Names provisional. */
extern unsigned int DAT_003ba384;
extern void (*DAT_003ba2fc)(void);
extern unsigned char DAT_003ba328;

void FUN_00048200(void)
{
  DAT_003ba384 = DAT_003ba384 + 1;
  if (DAT_003ba2fc != 0) {
    if (DAT_003ba328 == 0) {
      DAT_003ba2fc();
    }
  }
}
