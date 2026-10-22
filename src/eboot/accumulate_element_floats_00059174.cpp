/* HSTMATCH module=EBOOT.BIN start=0x00059174 end=0x0005922c symbol=FUN_00059174 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Walks the elements from the index at +0x158 up to the limit at +0x15c (both inclusive), calls
   FUN_00058748 with the element's float at +0x108, the object, the index and the flag byte at +0xec,
   and accumulates the float at +0x10c into +0x108 whenever it is not zero; the flag byte at +0xec
   is set when any accumulation happened.
   Matching idioms: the loop bound is read through a trivial inline getter (re-loaded every iteration),
   the index is a signed int (slt, not sltu) and the flag byte is declared before the index so that the
   index keeps the higher saved register.
   Names provisional. */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
typedef struct Obj Obj;

typedef struct Elem {
  char pad[0x108];
  float f108;
  float f10c;
} Elem;

struct Obj {
  char pad[0xec];
  unsigned char fEC;
  char pad2[0x6b];
  int f158;
  int f15c;
  int Limit() const { return f15c; }
};

extern "C" void FUN_00058748(float, Obj *, int, unsigned char);

extern "C" void FUN_00059174(Obj *self)
{
  unsigned char flag = 0;
  int i = self->f158;
  if (i <= self->Limit()) {
    Elem *e = (Elem *)((char *)self + i * 52);
    do {
      FUN_00058748(e->f108, self, i, self->fEC);
      if (e->f10c != 0.0f) {
        flag = 1;
        e->f108 = e->f108 + e->f10c;
      }
      i++;
      e = (Elem *)((char *)e + 52);
    } while (i <= self->Limit());
  }
  self->fEC = flag;
}
