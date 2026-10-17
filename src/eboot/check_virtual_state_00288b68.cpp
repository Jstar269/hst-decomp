/* HSTMATCH module=EBOOT.BIN start=0x00288b68 end=0x00288be8 symbol=FUN_00288b68 lang=c++ */
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

extern "C" void FUN_00288c74(Obj *);

extern "C" bool FUN_00288b68(Obj *self)
{
  int mode = self->slot11();
  bool accepted = mode == 2;
  if (!accepted) {
    mode = self->slot11();
    accepted = mode == 3;
  }

  if (accepted) {
    if (self->member == 0)
      FUN_00288c74(self);
    return *(unsigned char *)((char *)self->member + 0x7d) != 0xff;
  }
  return false;
}
