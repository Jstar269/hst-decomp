/* HSTMATCH module=EBOOT.BIN start=0x00096588 end=0x000966ac symbol=FUN_00096588 lang=c99 */
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

extern uchar DAT_003386b8;
extern char * DAT_00338af0;
extern undefined4 FUN_0009642c();
extern void FUN_000969c0();
extern int FUN_000c4ba0();

void FUN_00096588(int param_1, Rec *s)
{
  int ok;
  int iVar2;
  Rec *d;

  ok = DAT_003386b8 != 0;
  if (ok) {
    ok = (*(uchar *)(param_1 + 0x1b4) != 0) ^ 1;
  }
  if (((ok) && (DAT_00338af0 != 0)) && (iVar2 = FUN_0009642c(param_1,0), iVar2 != 0)) {
    iVar2 = FUN_000c4ba0(DAT_00338af0,*(int *)(param_1 + 0x148));
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
    d->k = *(int *)(DAT_00338af0 + 0x780);
    FUN_000969c0(iVar2);
  }
  return;
}
