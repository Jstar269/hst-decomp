/* HSTMATCH module=EBOOT.BIN start=0x001c1d0c end=0x001c1d58 symbol=FUN_001c1d0c lang=c99 */
/* WIP: 19 of 19 words differ (register colours + schedule). Retail stores the 4th and 5th globals AFTER the
   call setup begins (`sw a3,19f4` between the arg moves, `sw t1,1c34` in the j delay slot) and uses v1 for the
   constant base; every source order tried stores all five first and uses v0. Semantics (store order, arg order
   `FUN(&G,a,b,d,c)`) are confirmed. */
extern int DAT_003417c4;
extern int DAT_003418d4;
extern int DAT_003419f4;
extern int DAT_00341b14;
extern int DAT_00341c34;
extern int DAT_002ea2b0[];

extern int FUN_001be424(const void *a, int b, int c, int d, int e);

int FUN_001c1d0c(int param_1, int param_2, int param_3, int param_4, int param_5)
{
  DAT_003417c4 = param_1;
  DAT_003418d4 = param_2;
  DAT_00341b14 = param_3;
  DAT_003419f4 = param_4;
  DAT_00341c34 = param_5;
  return FUN_001be424(DAT_002ea2b0, param_1, param_2, param_4, param_3);
}
// near miss from lane ds6 (unreviewed)
