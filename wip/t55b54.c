/* HSTMATCH module=EBOOT.BIN start=0x00055b54 end=0x00055dc8 symbol=FUN_00055b54 lang=c99 */
typedef unsigned int u32;
extern int FUN_00022434(); extern int FUN_00022498(); extern int FUN_00022418();
extern int FUN_0004c8d8(); extern int FUN_0004d414();
extern float DAT_002bc440; extern float DAT_002bc444; extern float DAT_002bc448; extern float DAT_002bc44c;
u32 FUN_00055b54(int *p, float *out, float *m3, u32 a4, u32 a5, u32 a6, u32 a7)
{
  int x = p[0x23] ? *(int *)(p[0x23] + 0x10) : 0;
  float M[16], N[8], t[4];
  int i;
  if (x == 0) return 0;
  for (i = 0; i < 16; i++) M[i] = (float)p[0xc + i];
  for (i = 0; i < 8; i++) N[i] = m3[i];
  FUN_00022434(N, N, &M[12]);
  N[3] = m3[3];
  M[12] = DAT_002bc440; M[13] = DAT_002bc444; M[14] = DAT_002bc448; M[15] = DAT_002bc44c;
  {
    float s = 1.0f / (float)p[0x22];
    FUN_00022498(s, N, N);
    FUN_00022498(s, N + 4, N + 4);
  }
  {
    u32 v = (*(u32 (**)(int *))(*p + 0x18))(p);
    if (FUN_0004c8d8(x, out, N, M, v, p, a4, a5, a6, a7) == 0) return 0;
  }
  FUN_0004d414(t, out, m3);
  out[0] = t[0]; out[1] = t[1]; out[2] = t[2]; out[3] = t[3];
  FUN_00022498((float)p[0x22], out + 4, out + 4);
  FUN_00022418(out + 4, out + 4, (float *)(p + 0x18));
  out[7] = 0.0f;
  *(u32 *)(out + 0x10) = (u32)p;
  return 1;
}
// near miss from lane fm11 (unreviewed)
