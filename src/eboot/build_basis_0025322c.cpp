/* HSTMATCH module=EBOOT.BIN start=0x0025322c end=0x0025336c symbol=FUN_0025322c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Builds a 4x4 orthonormal frame into out from direction b: row2 = normalize(cross(b[1], b[0])),
   row0 = normalize(cross(kVec, row2)), row1 = cross(row2, row0), row3 = b[0]. Each axis' w is cleared
   before the cross that consumes it; mwcc sinks those clears into the call's delay slot. */
struct Vec4 { float x, y, z, w; };
extern "C" void FUN_00022434(Vec4 *dst, Vec4 *a, Vec4 *b);
extern "C" void FUN_000224f8(Vec4 *dst, Vec4 *a, Vec4 *b);
extern "C" void FUN_00022518(Vec4 *dst, Vec4 *a);
extern Vec4 DAT_002bc420;

extern "C" void FUN_0025322c(Vec4 *out, Vec4 *b)
{
  Vec4 rows[4];
  Vec4 a;

  FUN_00022434(&a, b + 1, b);
  rows[2] = a;
  FUN_00022518(&rows[2], &rows[2]);
  rows[2].w = 0.0f;
  FUN_000224f8(&rows[0], &DAT_002bc420, &rows[2]);
  FUN_00022518(&rows[0], &rows[0]);
  rows[0].w = 0.0f;
  FUN_000224f8(&rows[1], &rows[2], &rows[0]);
  rows[3] = b[0];
  out[0] = rows[0];
  out[1] = rows[1];
  out[2] = rows[2];
  out[3] = rows[3];
}
