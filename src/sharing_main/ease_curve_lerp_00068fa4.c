/* HSTMATCH module=hstp_trans_main.prx start=0x00068fa4 end=0x00069008 symbol=FUN_00068fa4 lang=c99 */
/* Clone of src/eboot/ease_curve_lerp_00067b50.c (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Interpolates between the two float arguments with an eased weight: for t < 0.5 the weight is
   0.5 * (2t)^2, otherwise 0.5 + 0.5 * (1 - (2 - 2t)^2), and the result is a + (b - a) * weight.
   The test is the float "less than" compare with the branch-likely false form (c.lt.s / bc1fl, the
   else arm out of line) and the final multiply needs the difference in a named local to get the
   retail operand order (mul.s $f0,$f0,$f1).
   Names provisional. */
float FUN_00068fa4(float a, float b, float t)
{
  float k;
  if (t < 0.5f) {
    float y = 2.0f * t;
    k = 0.5f * (y * y);
  } else {
    float x = 2.0f - 2.0f * t;
    k = 0.5f + 0.5f * (1.0f - x * x);
  }
  {
    float d = b - a;
    return a + d * k;
  }
}
