/* HSTMATCH module=EBOOT.BIN start=0x002b066c end=0x002b0704 symbol=FUN_002b066c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: added empty Tag temporary by value and float parameter for subobject configuration; exact match verified; names and types await human review. */
struct Tag {};

struct Elem {
  char pad[4];
  int arg;
  char pad2[4];
};

struct Obj {
  char pad_0[0x3c];
  char field_3c[0x54];
  char field_90;
  char pad_91[7];
  Elem items[10];
  char pad_110[0x27c];
  void *sub_38c;
};

extern "C" void FUN_00103628(void *, int);
extern "C" void FUN_002b3a24(void *, int, Tag);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);

extern "C" void FUN_002b066c(Obj *self)
{
  FUN_00103628(&self->field_3c, 1);
  self->field_90 = 1;
  int i = 0;
  Obj *cur = self;
  do {
    FUN_002b3a24((char *)cur + 0x98, *(int *)((char *)cur + 0x9c), Tag());
    i++;
    cur = (Obj *)((char *)cur + 0xc);
  } while (i < 10);

  if (self->sub_38c != 0) {
    FUN_00103540(self->sub_38c, 100000.0f);
    FUN_001037c8(self->sub_38c, -1);
  }
}
