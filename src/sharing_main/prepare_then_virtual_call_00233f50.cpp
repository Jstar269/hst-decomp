/* HSTMATCH module=hstp_trans_main.prx start=0x00233f50 end=0x00233f9c symbol=FUN_00233f50 lang=c++ */
/* Clone of src/eboot/prepare_then_virtual_call_002249dc.cpp (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC {
  virtual void slot0();
  virtual void slot1();
  virtual void slot2();
  virtual void slot3();
};

struct Obj {
  char pad0[0x54];
  unsigned char flag;
  char pad1[0x33];
  VC *member;
};

extern "C" void FUN_00108aec(Obj *);

extern "C" void FUN_00233f50(Obj *self)
{
  if (self->flag == 0) {
    FUN_00108aec(self);
    if (self->member != 0)
      self->member->slot3();
  }
}
