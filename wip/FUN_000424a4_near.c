/* HSTMATCH module=EBOOT.BIN start=0x000424a4 end=0x00042500 symbol=FUN_000424a4 lang=c */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); names and types await human review. */

unsigned *FUN_000424a4(unsigned *out, unsigned tag, float a, float b)
{
  float inv;
  unsigned *pb;

  inv = 1.0f / (b - a);
  pb = (unsigned *)&b;
  out[0] = 0xcf000000u | tag;
  out[1] = 0xcd000000u | (*pb >> 8);
  out[2] = 0xce000000u | (*(unsigned *)&inv >> 8);
  return out + 3;
}

/* Lane dsn2 shape map (3 compiles; 23/23 words - exact length and the same instruction multiset).
   Retail: f13 spilled at entry (the address of the float parameter b is taken), f0 = 1.0f, sub.s f13,f13,f12,
   div.s f0,f0,f13, f0 spilled at 4(sp), then the three tag words: out[0] = 0xcf000000 | tag built with ONE
   `ins a3,a1,0x0,0x18`; out[1] = 0xcd000000 | (bits(b) >> 8); out[2] = 0xce000000 | (bits(1/(b-a)) >> 8);
   return out + 3 (addiu v0,a0,12 before the epilogue). Note out[1] really does use the ORIGINAL b's bits, not the
   delta: the entry spill is never overwritten, so `(unsigned *)&b` is the right source spelling for it.
   What matches: the frame, the float work, both bit-pun spill slots, both `or` tag words, the return pointer.
   What does not: `0xcf000000 | tag` emits `or v0,a1,v0` where retail has `ins a3,a1,0x0,0x18` (the lane's known
   unreproducible `ins` idiom - see the 0x0003807c note in docs/MWCC-NOTES.md); adding `& 0xffffff` makes it worse
   (+2 words, sll/srl pair) and a union bitfield write made it +4 (and/or pair), so the unmasked `|` is the best
   spelling. Remaining differences after that are scheduling and which frame slots the two puns land in (ours at
   8/12(sp), retail at 0/4(sp)).
   Next step: only the `ins` lowering stands between this and EXACT; if a future lane finds the MWCC spelling that
   emits `ins` for `base | (x & 0xffffff)`, recompile this file unchanged. */
// near miss from lane dsn2 (unreviewed)
