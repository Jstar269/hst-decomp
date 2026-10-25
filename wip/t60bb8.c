/* HSTMATCH module=EBOOT.BIN start=0x00060bb8 end=0x00060e2c symbol=FUN_00060bb8 lang=c99 */
typedef unsigned int u32;
extern int FUN_00022518(); extern int FUN_000224f8(); extern int FUN_000224d8();
extern int FUN_0001d0b8(); extern int FUN_0001d164(); extern int FUN_00022570();
extern float DAT_002bc410[]; extern float DAT_002bc430[]; extern float DAT_002bc440[];
void FUN_00060bb8(u32 o, float *p2, float *q)
{
  float F[8], Q[4], S[4], R[4];
  float qq[4], m1[4], m2[4], tmp[16], t2[4];
  float f;
  m1[0] = DAT_002bc410[0]; m1[1] = DAT_002bc410[1]; m1[2] = DAT_002bc410[2]; m1[3] = DAT_002bc410[3];
  m2[0] = DAT_002bc410[4]; m2[1] = DAT_002bc410[5]; m2[2] = DAT_002bc410[6]; m2[3] = DAT_002bc410[7];
  qq[0] = DAT_002bc440[0]; qq[1] = DAT_002bc440[1]; qq[2] = DAT_002bc440[2]; qq[3] = DAT_002bc440[3];
  Q[0] = q[0]; Q[1] = q[1]; Q[2] = q[2]; Q[3] = q[3];
  FUN_00022518(F, Q);
  S[0] = F[0]; S[1] = F[1]; S[2] = F[2]; S[3] = 0.0f;
  qq[3] = 0.0f;
  f = (float)FUN_000224d8(S, DAT_002bc410 + 4);
  if ((f < 0.0f ? -f : f) <= 0.9999999f) {
    m2[0] = DAT_002bc410[4]; m2[1] = DAT_002bc410[5]; m2[2] = DAT_002bc410[6]; m2[3] = DAT_002bc410[7];
  } else {
    m2[0] = DAT_002bc430[0]; m2[1] = DAT_002bc430[1]; m2[2] = DAT_002bc430[2]; m2[3] = DAT_002bc430[3];
  }
  FUN_00022518(Q, Q);
  Q[3] = 0.0f;
  FUN_000224f8(m1, m2, Q);
  FUN_00022518(m1, m1);
  m1[3] = 0.0f;
  FUN_000224f8(m2, Q, m1);
  FUN_0001d0b8(o, t2, Q);
  FUN_0001d164(tmp, t2);
  FUN_00022570(m1, tmp, m1);
  p2[0] = m2[0]; p2[1] = m2[1]; p2[2] = m2[2]; p2[3] = m2[3];
}
// near miss from lane fm11 (unreviewed)
