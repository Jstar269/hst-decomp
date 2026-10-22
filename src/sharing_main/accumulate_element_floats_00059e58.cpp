/* HSTMATCH module=hstp_trans_main.prx start=0x00059e58 end=0x00059f10 symbol=FUN_00059e58 lang=c++ */
/* Clone of src/eboot/accumulate_element_floats_00059174.cpp (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Walks the elements from the index at +0x158 up to the limit at +0x15c (both inclusive), calls
   FUN_000593fc with the element's float at +0x108, the object, the index and the flag byte at +0xec,
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

extern "C" void FUN_000593fc(float, Obj *, int, unsigned char);

extern "C" void FUN_00059e58(Obj *self)
{
  unsigned char flag = 0;
  int i = self->f158;
  if (i <= self->Limit()) {
    Elem *e = (Elem *)((char *)self + i * 52);
    do {
      FUN_000593fc(e->f108, self, i, self->fEC);
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
