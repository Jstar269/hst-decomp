/* HSTMATCH module=EBOOT.BIN start=0x0004d414 end=0x0004d6a0 symbol=FUN_0004d414 lang=c99 */
typedef unsigned int u32;
extern int FUN_00022418(); extern int FUN_00022498(); extern int FUN_00022434();
extern int FUN_000224d8(); extern int FUN_00022e44();
void FUN_0004d414(float *out, int b, float *m)
{
  float T[4];
  float A[4], V[4], C[4];
  if (*(float *)(b + 0x30) == 3.4028235e38f) {
    FUN_00022418(A, m, m + 4);
    T[0] = A[0]; T[1] = A[1]; T[2] = A[2];
  } else if (*(float *)(b + 0x34) < 0.0f) {
    FUN_00022498(*(float *)(b + 0x34) * m[3], V, (float *)(b + 0x20));
    FUN_00022434(C, m, V);
    T[0] = C[0]; T[1] = C[1]; T[2] = C[2];
  } else {
    float r = (float)FUN_00022e44(FUN_000224d8(m + 4, m + 4));
    float s = *(float *)(b + 0x30);
    if (s == 0.0f) {
      T[0] = m[0]; T[1] = m[1]; T[2] = m[2];
    } else if (r != 0.0f) {
      float k = s - ((float)m[3] * 0.005f) / r;
      if (k <= s * 0.95f) k = s * 0.95f;
      if (0.0f < k) {
        int i = 0;
        float *d = T;
        FUN_00022498(V, m + 4);
        FUN_00022418(C, m, V);
        T[0] = C[0]; T[1] = C[1]; T[2] = C[2];
        do {
          if ((float)m[4] == 0.0f) *d = *m;
          i++; m++; d++;
        } while (i < 3);
      } else {
        T[2] = m[2]; T[0] = m[0]; T[1] = m[1];
      }
    } else {
      T[2] = m[2]; T[0] = m[0]; T[1] = m[1];
    }
  }
  out[0] = T[0]; out[1] = T[1]; out[2] = T[2]; out[3] = 1.0f;
}
// near miss from lane fm11 (unreviewed)
