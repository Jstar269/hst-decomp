/* HSTMATCH module=hstp_trans_main.prx start=0x001cff20 end=0x001cff6c symbol=FUN_001cff20 lang=c99 helpers=FUN_001c9440@0x001c9440-0x001c946c */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/FUN_001c1d0c.c: addresses substituted, the same-file static log stub FUN_001c9440 defined in front of it and placed at its own retail address by helpers=: knowing the stub, MWCC puts the last global store in the delay slot of the sibling `j` and uses retail's v1/t3/t2, an extern stub differs in 18 of 19 words); exact match verified; names and types await human review. */
/* Stores five seeds and logs them with "Seed, %d, %d, %d, %d, %d\n" in address order of the five
   globals, so the third and fourth arguments are printed swapped. */
extern int DAT_003eaafc;
extern int DAT_003eac0c;
extern int DAT_003ead2c;
extern int DAT_003eae4c;
extern int DAT_003eaf6c;
extern char DAT_00391f08[];

static void FUN_001c9440(...)
{
}

void FUN_001cff20(int seed1, int seed2, int seed3, int seed4, int seed5)
{
  DAT_003eaafc = seed1;
  DAT_003eac0c = seed2;
  DAT_003eae4c = seed3;
  DAT_003ead2c = seed4;
  DAT_003eaf6c = seed5;
  FUN_001c9440(DAT_00391f08, seed1, seed2, seed4, seed3, seed5);
}
