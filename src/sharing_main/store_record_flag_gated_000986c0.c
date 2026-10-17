/* HSTMATCH module=hstp_trans_main.prx start=0x000986c0 end=0x000987e4 symbol=FUN_000986c0 lang=c99 */
/* Clone of src/eboot/store_record_flag_gated_00096588.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: gate flag as int (DAT != 0, then (byte != 0) ^ 1), unsigned char flag globals, the 0x39-byte record copied as typed struct (two Vec4 members assigned whole, then scalar members one by one); exact match verified; names and types await human review. */
typedef unsigned char uchar;
typedef int undefined4;
typedef struct { float x, y, z, w; } Vec4;
typedef struct {
  Vec4 a;
  Vec4 b;
  float c, d, e, f;
  int g;
  short h;
  signed char i, j;
  int k;
} Rec;

extern uchar DAT_003e19f8;
extern char * DAT_003e1e30;
extern undefined4 FUN_00098564();
extern void FUN_00098af8();
extern int FUN_000c8538();

void FUN_000986c0(int param_1, Rec *s)
{
  int ok;
  int iVar2;
  Rec *d;

  ok = DAT_003e19f8 != 0;
  if (ok) {
    ok = (*(uchar *)(param_1 + 0x1b4) != 0) ^ 1;
  }
  if (((ok) && (DAT_003e1e30 != 0)) && (iVar2 = FUN_00098564(param_1,0), iVar2 != 0)) {
    iVar2 = FUN_000c8538(DAT_003e1e30,*(int *)(param_1 + 0x148));
    d = (Rec *)(iVar2 + 0xf0);
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    d->e = s->e;
    d->f = s->f;
    d->g = s->g;
    d->h = s->h;
    d->i = s->i;
    d->j = s->j;
    d->k = s->k;
    d->k = *(int *)(DAT_003e1e30 + 0x780);
    FUN_00098af8(iVar2);
  }
  return;
}
