/* HSTMATCH module=hstp_trans_main.prx start=0x002aff90 end=0x002b006c symbol=FUN_002aff90 lang=c++ */
/* Clone of src/eboot/set_state_actions_002a0b84.cpp (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: reconstructed switch statement with empty case 4 and virtual interface calls; exact match verified; names and types await human review. */
extern "C" void FUN_00108dac();
extern "C" void FUN_00108f54(void *, int);

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

struct Obj {
  char pad_0[4];
  int **field_4;
  char pad_8[0x4c];
  int state;
  int field_58;
  char *field_5c;
  char pad_60[4];
  SubObj *field_64;
};

extern "C" void FUN_002aff90(Obj *self, int state)
{
  self->state = state;
  self->field_58 = 0;
  switch (self->state) {
  case 0:
    *(int *)(*self->field_4 + 0x1e) = 0;
    *(int *)(self->field_5c + 0x78) = 0;
    FUN_00108dac();
    FUN_00108f54(self, 1);
    break;
  case 1:
    FUN_00108f54(self, 0);
    break;
  case 2:
    self->field_64->slot1(0);
    self->field_64->slot10();
    break;
  case 3:
    self->field_64->slot1(1);
    break;
  case 4:
    break;
  }
}
