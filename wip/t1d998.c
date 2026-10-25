/* HSTMATCH module=EBOOT.BIN start=0x0001d998 end=0x0001dbf8 symbol=FUN_0001d998 lang=c99 */
typedef unsigned int u32;
extern int FUN_00022518(); extern int FUN_000224f8(); extern int FUN_00022668();
extern float DAT_002bc410[];
void FUN_0001d998(float *o)
{
  float q[4], A[4], B[4], C[4], D[4], P[4], X[4], Y[4], Z[4];
  float m[16];
  float f;
  int i;
  FUN_00022518(q);
  A[0] = q[0]; A[1] = q[1]; A[2] = q[2]; A[3] = q[3];
  q[3] = 0.0f; A[3] = 0.0f;
  f = q[2] < 0.0f ? -q[2] : q[2];
  if (f < 0.999999f) {
    B[0] = 0.0f; B[1] = 0.0f; B[2] = 0.0f; B[3] = 1.0f;
    FUN_000224f8(P, B, A);
    C[0] = P[0]; C[1] = P[1]; C[2] = P[2]; C[3] = P[3];
    FUN_000224f8(X, A, C);
    Y[0] = X[0]; Y[1] = X[1]; Y[2] = X[2]; Y[3] = X[3];
    FUN_00022518(C, C);
    C[3] = 0.0f; Y[3] = 0.0f;
    FUN_00022518(D, Y);
    m[0] = C[0]; m[1] = C[1]; m[2] = C[2]; m[3] = C[3];
    m[4] = D[0]; m[5] = D[1]; m[6] = D[2]; m[7] = 0.0f;
    m[8] = A[0]; m[9] = A[1]; m[10] = A[2]; m[11] = A[3];
    m[12] = 0.0f; m[13] = 0.0f; m[14] = 0.0f; m[15] = 1.0f;
  } else {
    FUN_00022668(q[2] < 0.0f ? 1.5707964f : -1.5707964f, m, DAT_002bc410);
  }
  for (i = 0; i < 16; i++) o[i] = m[i];
}
// near miss from lane fm11 (unreviewed)
