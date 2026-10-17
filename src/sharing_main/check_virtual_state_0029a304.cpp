/* HSTMATCH module=hstp_trans_main.prx start=0x0029a304 end=0x0029a384 symbol=FUN_0029a304 lang=c++ */
/* Clone of src/eboot/check_virtual_state_00288b68.cpp (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
  virtual int slot0();
  virtual int slot1();
  virtual int slot2();
  virtual int slot3();
  virtual int slot4();
  virtual int slot5();
  virtual int slot6();
  virtual int slot7();
  virtual int slot8();
  virtual int slot9();
  virtual int slot10();
  virtual int slot11();
  char pad[0x5c];
  int *member;
};

extern "C" void FUN_0029a410(Obj *);

extern "C" bool FUN_0029a304(Obj *self)
{
  int mode = self->slot11();
  bool accepted = mode == 2;
  if (!accepted) {
    mode = self->slot11();
    accepted = mode == 3;
  }

  if (accepted) {
    if (self->member == 0)
      FUN_0029a410(self);
    return *(unsigned char *)((char *)self->member + 0x7d) != 0xff;
  }
  return false;
}
