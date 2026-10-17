/* HSTMATCH module=hstp_trans_main.prx start=0x002c00bc end=0x002c0154 symbol=FUN_002c00bc lang=c++ */
/* Clone of src/eboot/init_channel_slots_002b066c.cpp (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_00108f54(void *, int);
extern "C" void FUN_002c34e4(void *, int, Tag);
extern "C" void FUN_00108e6c(void *, float);
extern "C" void FUN_001090f4(void *, int);

extern "C" void FUN_002c00bc(Obj *self)
{
  FUN_00108f54(&self->field_3c, 1);
  self->field_90 = 1;
  int i = 0;
  Obj *cur = self;
  do {
    FUN_002c34e4((char *)cur + 0x98, *(int *)((char *)cur + 0x9c), Tag());
    i++;
    cur = (Obj *)((char *)cur + 0xc);
  } while (i < 10);

  if (self->sub_38c != 0) {
    FUN_00108e6c(self->sub_38c, 100000.0f);
    FUN_001090f4(self->sub_38c, -1);
  }
}
