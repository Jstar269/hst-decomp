/* HSTMATCH module=EBOOT.BIN start=0x0016b7d0 end=0x0016b85c symbol=FUN_0016b7d0 lang=c99 */
extern volatile int DAT_002e04a8;
extern volatile int DAT_002e04ac;
extern char DAT_00341ccc[];

void FUN_0016b7d0(int idx, int val)
{
  short v = val;
  int bound = DAT_002e04a8;
  if ((unsigned short)v < DAT_002e04a8) {
    ;
  } else {
    bound = DAT_002e04ac;
    if ((unsigned short)v > DAT_002e04ac) bound = v;
  }
  unsigned short *e = 0;
  if (idx >= 0 && idx < 15)
    e = (unsigned short *)(DAT_00341ccc + idx * 56 + 200);
  e[1] = bound;
}
// near miss 33/35 words: `volatile int` limits give retail's doubled `lw` pairs and `short v = val` (so the
// compare lands in `at`, as retail) but `short` converts with `seh a2,a1` where retail uses `andi a1,a1,0xffff`
// (unsigned-short conversion); with `unsigned short v` the compare moves to v1 and the base `lui a2,0x34`
// disappears from the entry. Guards: `idx < 0 || idx >= 15` gives bltzl, retail has `bltz` + `slti`.
// Also tried: plain (non-volatile) limits (single lw, 25-27 words), int/uint limits, three guard spellings.
// near miss from lane ds4 (unreviewed)
