/* HSTMATCH module=EBOOT.BIN start=0x000bcd8c end=0x000bce08 symbol=FUN_000bcd8c lang=c99 */

struct Obj {
  char pad[0x10];
  unsigned short f10;
  char pad2[0x28 - 0x12];
  int f28;
  char pad3[0x17c - 0x2c];
  int f17c;
  char pad4[0x190 - 0x180];
  int f190;
  int f194;
};

extern char DAT_00348ac4[];
int FUN_000bda40(char *, char *, int, int, int);

void FUN_000bcd8c(struct Obj *self)
{
  int m;
  int v;

  self->f194 = self->f190;
  m = 0xb;
  self->f28 = m;
  switch (m) {
  case 4:
  case 8:
  case 10:
    v = FUN_000bda40(DAT_00348ac4, DAT_00348ac4 + 56, self->f10, 1444, 0);
    self->f17c = v & 0xff;
    break;
  }
}
// NEAR 31/31 retail words, ours 5 (0x000bcd8c). The two stores are right (`f194 = f190`, `f28 = 0xb`)
// but retail then keeps a dead compare chain (11 vs 10, 8, 4) whose equal-arms reach a block that
// calls FUN_000bda40 and stores `ret & 0xff` into f17c. Our compiler constant-folds the test away
// because the value is a literal, so the whole guarded block disappears; retail kept it, which means
// its source reached the compare through something MWCC would not fold. Neither `if (m == 10 || m ==
// 8 || m == 4)` nor an ascending `switch (m) { case 4: case 8: case 10: }` survived. A later pass
// should try a factory/macro spelling that keeps the value opaque (e.g. reading it back through a
// differently-typed pointer) — the surrounding offsets and the call arguments are already settled:
// FUN_000bda40(DAT_00348ac4, DAT_00348ac4 + 56, self->f10, 1444, 0).
// near miss from lane fm5 (unreviewed)
