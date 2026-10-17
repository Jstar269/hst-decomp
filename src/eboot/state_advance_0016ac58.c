/* HSTMATCH module=EBOOT.BIN start=0x0016ac58 end=0x0016adf8 symbol=FUN_0016ac58 lang=c99 */
/* Hand-written reconstruction from the disassembly (struct with 2-float/2-short/2-uchar sub-structs assigned whole, scalar fields copied one by one, then position += velocity * dt); exact match verified; names and types await human review. */
typedef struct P2 { float x, y; } P2;
typedef struct H2 { short a, b; } H2;
typedef struct B2 { unsigned char a, b; } B2;
typedef struct S {
  float f[13];
  int i34;
  P2 uv;
  int i40;
  short s44;
  H2 hh;
  signed char c4a[7];
  B2 bb;
  signed char c53[5];
} S;

void FUN_0016ac58(float dt, S *d, S *s, float *v)
{
  d->f[0] = s->f[0];
  d->f[1] = s->f[1];
  d->f[2] = s->f[2];
  d->f[3] = s->f[3];
  d->f[4] = s->f[4];
  d->f[5] = s->f[5];
  d->f[6] = s->f[6];
  d->f[7] = s->f[7];
  d->f[8] = s->f[8];
  d->f[9] = s->f[9];
  d->f[10] = s->f[10];
  d->f[11] = s->f[11];
  d->f[12] = s->f[12];
  d->i34 = s->i34;
  d->uv = s->uv;
  d->i40 = s->i40;
  d->s44 = s->s44;
  d->hh = s->hh;
  d->c4a[0] = s->c4a[0];
  d->c4a[1] = s->c4a[1];
  d->c4a[2] = s->c4a[2];
  d->c4a[3] = s->c4a[3];
  d->c4a[4] = s->c4a[4];
  d->c4a[5] = s->c4a[5];
  d->c4a[6] = s->c4a[6];
  d->bb = s->bb;
  d->c53[0] = s->c53[0];
  d->c53[1] = s->c53[1];
  d->c53[2] = s->c53[2];
  d->c53[3] = s->c53[3];
  d->c53[4] = s->c53[4];
  d->f[0] = s->f[0] + v[0] * dt;
  d->f[1] = s->f[1] + v[1] * dt;
  d->f[2] = s->f[2] + v[2] * dt;
  d->f[3] = s->f[3] + v[3] * dt;
  d->f[4] = s->f[4] + v[4] * dt;
  d->f[5] = s->f[5] + v[5] * dt;
  d->f[6] = s->f[6] + v[6] * dt;
}
