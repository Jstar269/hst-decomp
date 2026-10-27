/* HSTMATCH module=EBOOT.BIN start=0x00042e04 end=0x00042ecc symbol=FUN_00042e04 lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/reset_buffers_00042ee8.cpp; the leading `if (self->a == 0 || self->b == 0) return;` guard gives retail's dead copy of the likely-slot instruction and the unthreaded `b; nop`, the nested `if (a && b) {..}` is 41 words off; the members past 0x7fff are typed struct fields); exact match verified; names and types await human review. */
struct ElemA { short f0; short f2; int f4; };
struct ElemB { short f0; short f2; };

struct State {
  char pad0[0x6c];
  char buf6c[0x106c - 0x6c];
  char *p106c;
  char buf1070[0x19070 - 0x1070];
  char *p19070;
  char pad19074[0x190a0 - 0x19074];
  int count;
  ElemA *a;
  int *f190a8;
  ElemB *b;
};

extern "C" void FUN_001972fc(void);

extern "C" void FUN_00042e04(State *self)
{
  if (self->a == 0 || self->b == 0)
    return;
  self->p106c = self->buf6c;
  self->p19070 = self->buf1070;
  for (int i = 0; i < self->count; i++) {
    self->a[i].f2 = 0;
    self->b[i].f0 = 0;
  }
  FUN_001972fc();
}
