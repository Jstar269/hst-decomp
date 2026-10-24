/* HSTMATCH module=EBOOT.BIN start=0x002ad938 end=0x002ad998 symbol=FUN_002ad938 lang=c99 */
extern int DAT_0034a678;
extern int FUN_0016bb88();
extern void FUN_002ad758(int,int,int);
void FUN_002ad938(void)
{
  int m = 0;
  switch (DAT_0034a678) { case 2: m = 2; break; case 0x20: m = 2; break; }
  FUN_002ad758(m, FUN_0016bb88(), 0);
}
// NEAR 1 word: switch(DAT_0034a678){case 2:m=2;break;case 0x20:m=2;break;} gives the exact beq/beql/b layout; only the last block
// differs: ours 'move s0,v0' (reuses the li v0,2 of the beql compare), retail 'li s0,2'.
// Ruled out (about 30 compiles): if/else-if and || chains (bne layout, 6-16 words), case order/fallthrough forms (2-7 words), result types
// (char/short/unsigned/long long/register), const int two, (int)2u, 3-1, temp for FUN_0016bb88, goto form, ternary on a flag.
// improved by lane sn7 (unreviewed): 6 -> 1 differing words
