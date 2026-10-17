/* HSTMATCH module=EBOOT.BIN start=0x00052d08 end=0x00052e18 symbol=FUN_00052d08 lang=c99 */
/* Clone of src/sharing_main/mat4_determinant_000537c8.c (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Determinant of a 4x4 float matrix by Laplace expansion into the six 2x2 minors of rows 0-1 times the complementary minors of rows 2-3; the sum keeps the retail association A + ((B + (C + (D - E))) - F) (Ghidra printed it without those parentheses). */
typedef struct Mat4 {
  float m[4][4];
} Mat4;

float FUN_00052d08(Mat4 *m)
{
  return (m->m[0][2] * m->m[1][3] - m->m[0][3] * m->m[1][2]) * (m->m[2][0] * m->m[3][1] - m->m[2][1] * m->m[3][0]) +
         ((m->m[0][1] * m->m[1][2] - m->m[0][2] * m->m[1][1]) * (m->m[2][0] * m->m[3][3] - m->m[2][3] * m->m[3][0]) +
          ((m->m[0][0] * m->m[1][3] - m->m[0][3] * m->m[1][0]) * (m->m[2][1] * m->m[3][2] - m->m[2][2] * m->m[3][1]) +
           ((m->m[0][0] * m->m[1][1] - m->m[0][1] * m->m[1][0]) * (m->m[2][2] * m->m[3][3] - m->m[2][3] * m->m[3][2]) -
            (m->m[0][0] * m->m[1][2] - m->m[0][2] * m->m[1][0]) * (m->m[2][1] * m->m[3][3] - m->m[2][3] * m->m[3][1]))) -
          (m->m[0][1] * m->m[1][3] - m->m[0][3] * m->m[1][1]) * (m->m[2][0] * m->m[3][2] - m->m[2][2] * m->m[3][0]));
}
