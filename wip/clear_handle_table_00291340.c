/* HSTMATCH module=EBOOT.BIN start=0x00291340 end=0x00291434 symbol=FUN_00291340 lang=c99 */
extern unsigned char DAT_0034a7f8;
extern int DAT_0034a7fc;
extern char DAT_002ff4e4[];
extern char DAT_002ff50c[];
extern void FUN_0028fb44(const char *, int);
extern int FUN_002b7800(int);
extern int FUN_002b7808(int, int, int, int, int);

int FUN_00291340(void)
{
  int h;
  int *p;
  int i;
  unsigned char ok;
  int r;

  if (DAT_0034a7f8 == 0) return 1;
  ok = 1;
  if (DAT_0034a7fc > 0) {
    i = 0;
    p = &DAT_0034a7fc;
    do {
      if (ok) {
        int good;
        h = *p;
        r = FUN_002b7808(h, 0, 0, 0, 0);
        if (r < 0) {
          FUN_0028fb44(DAT_002ff4e4, r);
          good = 0;
        }
        else {
          r = FUN_002b7800(h);
          if (r < 0) {
            FUN_0028fb44(DAT_002ff50c, r);
            good = 0;
          }
          else {
            good = 1;
          }
        }
        ok = good;
      }
      *p = 0;
      p++;
      i++;
    } while (i < *p);
  }
  DAT_0034a7f8 = 0;
  return ok;
}

// NEAR MISS: 60/61 words, 24 words differ.
// Ours matches retail's call sequence and log strings but schedules `ok = 1` into the blez delay
// slot (retail keeps `li v1,1` before the blez and puts `i = 0` in the slot) and emits
// `beqzl ok,SKIP` with the `*p = 0` store in the delay slot where retail has `beqz ok,SKIP` with
// `andi v0,ok,0xff` in the slot plus a second `andi` when `ok` is stored.
// Ruled out: ok as uchar/int/bool (C and C++), `ok = (unsigned char)good` vs `ok = good`,
// declaring ok at the top vs after the early return, for-loop vs do-while for the re-read bound.
// The remaining words are entirely ok's type/conversion colouring.
// near miss from lane fm2 (unreviewed)
