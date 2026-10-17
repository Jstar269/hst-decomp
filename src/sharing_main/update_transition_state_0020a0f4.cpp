/* HSTMATCH module=hstp_trans_main.prx start=0x0020a0f4 end=0x0020a188 symbol=FUN_0020a0f4 lang=c++ */
/* Clone of src/eboot/update_transition_state_001fb9dc.cpp (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed C++ virtual method calls and inverted branch polarity; exact match verified; names and types await human review. */
struct Obj {
  virtual void slot0();
  virtual void slot1(int);
  virtual void slot2(int);

  int field_4;
  int field_8;
  int field_12;
  int field_16;
  int field_20;
};

extern "C" void FUN_0020a0f4(Obj *self)
{
  if (self->field_4 != self->field_16 && --self->field_12 <= 0) {
    int v = self->field_16;
    self->slot2(self->field_4);
    self->field_20 = self->field_4;
    self->field_4 = v;
    self->field_8 = 0;
    self->field_12 = 0;
    self->slot1(v);
  } else {
    self->field_8++;
  }
}
