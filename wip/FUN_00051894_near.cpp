/* HSTMATCH module=EBOOT.BIN start=0x00051894 end=0x00051a10 symbol=FUN_00051894 lang=c++ */
struct V { float x, y, z, w; };
struct Self { char pad00[40]; void *f40; };
extern "C" void *FUN_0003807c(void *obj, const V *a, const V *b, const V *c, const V *d, const V *col);
extern "C" void FUN_00051894(Self *self, unsigned color,
                             float A, float B, float C, float D,
                             float E, float F, float G, float H, float Z)
{
  V q4, q3, q2, q1, col;
  q4.x = C; q4.y = D; q4.z = Z; q4.w = 0.0f;
  q3.x = G; q3.y = H; q3.z = Z; q3.w = 0.0f;
  q2.x = A; q2.y = B; q2.z = 1.0f; q2.w = 0.0f;
  q1.x = E; q1.y = F; q1.z = 1.0f; q1.w = 0.0f;
  unsigned char *p = (unsigned char *)&color;
  col.w = (float)p[3] / 128.0f;
  col.z = (float)p[2] / 255.0f;
  col.y = (float)p[1] / 255.0f;
  col.x = (float)p[0] / 255.0f;
  self->f40 = FUN_0003807c(self->f40, &q4, &q3, &q2, &q1, &col);
}
// NEAR 95/95 words, 46 differ - lane dsn2, 2026-10-27 session 8 (2 compiles).
// Structure fully cracked on the first draft (95/95 words at once): four 16-byte structs built from eight float
// arguments plus one STACK float (the 9th float parameter - read as lwc1 112(sp), so the signature is
// (Self*, unsigned color, 8 floats, float Z) with Z stack-passed), a packed colour byte-viewed through
// `unsigned char *p = (unsigned char *)&color` (the store of `color` to 28(sp) is the address-taken home) and
// FUN_0003807c(self->f40, &q4, &q3, &q2, &q1, &col) - six arguments, of which the 5th and 6th ride in t0/t1,
// which is just this build's EABI (see MWCC-NOTES: args 5-8 ARE t0-t3).
// ORDER RULES that took it from 65 differ to 46: declare the structs REVERSE (q4, q3, q2, q1, col) because
// declaration order assigns the highest slot to the first-declared; assign in the matching reverse statement
// order (q4 first sets the arg-homing sequence f14,f15 -> f18,f19 -> f12,f13 -> f16,f17); and convert the colour
// bytes LAST-TO-FIRST (w = p[3]/128.0f first, then z, y, x) which also produces retail's last-store-first
// rotation into col (36,40,44 stored before 32).
// WHAT IS LEFT (46 differ, all in the four per-byte conversion blocks): retail INTERLEAVES the blocks - the
// previous byte's `div.s` lands in the next byte's `bltz` delay slot (0x51928 bltz / 0x5192c div.s) - while our
// build finishes each byte's chain before starting the next (div.s before the lbu). The first 36 words
// (0x51894..0x51920) are already word-for-word.
// NEXT STEP: get the four conversions to be one visible dependency-free group: compute all four components in a
// single statement (e.g. one local `V c = { ... }` list or an inline helper taking (p[0],p[1],p[2],p[3]) and
// returning V), which is the only shape known to make -O4,p interleave sibling chains like this; the block
// pattern is otherwise correct.
// near miss from lane dsn2 (unreviewed)
