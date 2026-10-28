/* HSTMATCH module=EBOOT.BIN start=0x000400d8 end=0x00040138 symbol=FUN_000400d8 lang=c */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); names and types await human review. */

extern float DAT_002bbfe8;

static inline void set4(float *out, float r, float g, float b, float a)
{
  out[0] = r;
  out[1] = g;
  out[2] = b;
  out[3] = a;
}

void FUN_000400d8(float *out, unsigned short rgba)
{
  set4(out,
       (float)(rgba & 0xf) * DAT_002bbfe8,
       (float)((rgba >> 4) & 0xf) * DAT_002bbfe8,
       (float)((rgba >> 8) & 0xf) * DAT_002bbfe8,
       (float)((unsigned)rgba >> 12) * DAT_002bbfe8);
}

/* Lane dsn2 shape map (same family as 0x00040194; see wip/FUN_00040194_near.c). Retail: RGBA4444 -> float4 with one
   constant (DAT_002bbfe8), entry andi 0xffff, extracts srl 0xc (alpha) / andi 0xf (r) / ext 4,4 (g) / ext 8,4 (b),
   four cvt.s.w, one lwc1, four mul.s, stores [3],[0],[1],[2] with [2] in the delay slot. Same finding: -O4,p
   interleaves where retail batches; the source spelling that produced the exact 22/22-word multiset for 0x00040194
   (extract fields, convert, multiply with `(float)(int)((unsigned)v >> n)` for the top field, stores written
   last-store-first) is the shape to start from here. */
// near miss from lane dsn2 (unreviewed)
