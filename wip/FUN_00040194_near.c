/* HSTMATCH module=EBOOT.BIN start=0x00040194 end=0x000401ec symbol=FUN_00040194 lang=c */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); names and types await human review. */

extern float DAT_002bbff0;
extern float DAT_002bbff4;

void FUN_00040194(float *out, unsigned short rgb, float alpha)
{
  float b;
  float r;
  float g;

  b = (float)(int)((unsigned)rgb >> 11) * DAT_002bbff0;
  r = (float)(rgb & 0x1f) * DAT_002bbff0;
  g = (float)((rgb >> 5) & 0x3f) * DAT_002bbff4;
  out[3] = alpha;
  out[0] = r;
  out[1] = g;
  out[2] = b;
}

/* Lane dsn2 shape map (7 compiles; 22/22 words - the SAME instruction multiset as retail, 20-21 positions differ).
   What matches: the andi-0xffff entry mask, all three field extractions (andi 0x1f / ext 5,6 / srl 0xb), the three
   cvt.s.w, the two constant loads (two lui, one per DAT_), the three mul.s, the store rotation [3],[0],[1],[2] with
   [2] in the jr delay slot, and the exact word count.
   What does not: MWCC -O4,p here INTERLEAVES (extract -> convert -> mul -> store per element, K1 hoisted to the top);
   retail BATCHES (all extracts, all mtc1, all cvt, both constants, all three mul, then all four stores). Statement
   grouping (separate convert/multiply statements), int locals for the fields, an int cast on the >>11 term and
   permuting the term order (r,g,b / b,r,g) all leave the batching unchanged; the statement order only moves which
   element is scheduled first. Not reachable by source spelling in 7 compiles.
   Source lessons that ARE solid: (a) `unsigned short` param gives the retail andi-0xffff entry mask, but `x >> 11`
   on it promotes to int and emits `sra` - write `(float)(int)((unsigned)x >> 11)` for retail's `srl` while keeping
   the cheap cvt (a plain `(float)((unsigned)x >> 11)` triggers MWCC's unsigned->float doubling sequence);
   (b) the stores must be written last-store-first ([3] then [0],[1],[2]) to get the retail store rotation with [2]
   in the delay slot - writing 0,1,2,3 gives the rotation shifted the other way. */
// near miss from lane dsn2 (unreviewed)
