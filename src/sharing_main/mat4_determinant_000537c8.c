/* HSTMATCH module=hstp_trans_main.prx start=0x000537c8 end=0x000538d8 symbol=FUN_000537c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Determinant of a 4x4 float matrix by Laplace expansion into the six 2x2 minors of rows 0-1 times the complementary minors of rows 2-3; the sum keeps the retail association A + ((B + (C + (D - E))) - F) (Ghidra printed it without those parentheses). */
typedef struct Mat4 {
  float m[4][4];
} Mat4;

float FUN_000537c8(Mat4 *m)
{
  return (m->m[0][2] * m->m[1][3] - m->m[0][3] * m->m[1][2]) * (m->m[2][0] * m->m[3][1] - m->m[2][1] * m->m[3][0]) +
         ((m->m[0][1] * m->m[1][2] - m->m[0][2] * m->m[1][1]) * (m->m[2][0] * m->m[3][3] - m->m[2][3] * m->m[3][0]) +
          ((m->m[0][0] * m->m[1][3] - m->m[0][3] * m->m[1][0]) * (m->m[2][1] * m->m[3][2] - m->m[2][2] * m->m[3][1]) +
           ((m->m[0][0] * m->m[1][1] - m->m[0][1] * m->m[1][0]) * (m->m[2][2] * m->m[3][3] - m->m[2][3] * m->m[3][2]) -
            (m->m[0][0] * m->m[1][2] - m->m[0][2] * m->m[1][0]) * (m->m[2][1] * m->m[3][3] - m->m[2][3] * m->m[3][1]))) -
          (m->m[0][1] * m->m[1][3] - m->m[0][3] * m->m[1][1]) * (m->m[2][0] * m->m[3][2] - m->m[2][2] * m->m[3][0]));
}
