/* HSTMATCH module=hstp_trans_main.prx start=0x0005a484 end=0x0005a59c symbol=FUN_0005a484 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v1) corrected by hand: typed the 0x84-byte record as float[32] plus two chars and kept the 32 explicit element assignments (a loop or whole-struct assignment compiles to a copy loop); exact match verified; names and types await human review. */
typedef struct S { float f[32]; char a; char b; } S;

S *FUN_0005a484(S *d, const S *s)
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
  d->f[13] = s->f[13];
  d->f[14] = s->f[14];
  d->f[15] = s->f[15];
  d->f[16] = s->f[16];
  d->f[17] = s->f[17];
  d->f[18] = s->f[18];
  d->f[19] = s->f[19];
  d->f[20] = s->f[20];
  d->f[21] = s->f[21];
  d->f[22] = s->f[22];
  d->f[23] = s->f[23];
  d->f[24] = s->f[24];
  d->f[25] = s->f[25];
  d->f[26] = s->f[26];
  d->f[27] = s->f[27];
  d->f[28] = s->f[28];
  d->f[29] = s->f[29];
  d->f[30] = s->f[30];
  d->f[31] = s->f[31];
  d->a = s->a;
  d->b = s->b;
  return d;
}
