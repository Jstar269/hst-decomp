/* HSTMATCH module=hstp_trans_main.prx start=0x0015d108 end=0x0015d148 symbol=FUN_0015d108 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same instruction shape as the EBOOT twin src/eboot/pad_tick_001510d0.c (global DAT_003f344c, callee
   FUN_001db90c): count down a delay, then report whether the polled call returned zero. Names provisional. */
extern int DAT_003f344c;
extern int FUN_001db90c(int);

typedef struct Tick {
  int f0;
  int count;
} Tick;

int FUN_0015d108(Tick *t)
{
  int v = t->count;

  if (v > 0) {
    t->count = v - 1;
    return 0;
  }
  return !FUN_001db90c(DAT_003f344c);
}
