/* HSTMATCH module=hstp_trans_main.prx start=0x00263580 end=0x002636c0 symbol=FUN_00263580 lang=c++ */
/* Clone of src/eboot/build_basis_0025322c.cpp (hstclone.py tag c015707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Builds a 4x4 orthonormal frame into out from direction b: row2 = normalize(cross(b[1], b[0])),
   row0 = normalize(cross(kVec, row2)), row1 = cross(row2, row0), row3 = b[0]. Each axis' w is cleared
   before the cross that consumes it; mwcc sinks those clears into the call's delay slot. */
struct Vec4 { float x, y, z, w; };
extern "C" void FUN_0002245c(Vec4 *dst, Vec4 *a, Vec4 *b);
extern "C" void FUN_00022520(Vec4 *dst, Vec4 *a, Vec4 *b);
extern "C" void FUN_00022540(Vec4 *dst, Vec4 *a);
extern Vec4 DAT_002cc270;

extern "C" void FUN_00263580(Vec4 *out, Vec4 *b)
{
  Vec4 rows[4];
  Vec4 a;

  FUN_0002245c(&a, b + 1, b);
  rows[2] = a;
  FUN_00022540(&rows[2], &rows[2]);
  rows[2].w = 0.0f;
  FUN_00022520(&rows[0], &DAT_002cc270, &rows[2]);
  FUN_00022540(&rows[0], &rows[0]);
  rows[0].w = 0.0f;
  FUN_00022520(&rows[1], &rows[2], &rows[0]);
  rows[3] = b[0];
  out[0] = rows[0];
  out[1] = rows[1];
  out[2] = rows[2];
  out[3] = rows[3];
}
