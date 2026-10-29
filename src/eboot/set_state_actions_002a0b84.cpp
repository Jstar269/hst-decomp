/* HSTMATCH module=EBOOT.BIN start=0x002a0b84 end=0x002a0c60 symbol=FUN_002a0b84 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: reconstructed switch statement with empty case 4 and virtual interface calls; readability pass; exact match verified; names and types await human review. */
extern "C" void FUN_00103480();
extern "C" void FUN_00103628(void *, int);

struct SubObj {
  virtual void slot0();
  virtual void slot1(int);
  virtual void slot2();
  virtual void slot3();
  virtual void slot4();
  virtual void slot5();
  virtual void slot6();
  virtual void slot7();
  virtual void slot8();
  virtual void slot9();
  virtual void slot10();
};

struct Block78 {
  char pad[0x78];
  int unk78;  /* 0x78 */
};

struct Obj {
  char pad_0[4];
  Block78 **block_ref;   /* 0x04 */
  char pad_8[0x4c];
  int state;             /* 0x54 */
  int unk58;             /* 0x58 */
  Block78 *block;        /* 0x5c */
  char pad_60[4];
  SubObj *sub;           /* 0x64 */
};

extern "C" void FUN_002a0b84(Obj *self, int state)
{
  self->state = state;
  self->unk58 = 0;
  switch (self->state) {
  case 0:
    (*self->block_ref)->unk78 = 0;
    self->block->unk78 = 0;
    FUN_00103480();
    FUN_00103628(self, 1);
    break;
  case 1:
    FUN_00103628(self, 0);
    break;
  case 2:
    self->sub->slot1(0);
    self->sub->slot10();
    break;
  case 3:
    self->sub->slot1(1);
    break;
  case 4:
    break;
  }
}
