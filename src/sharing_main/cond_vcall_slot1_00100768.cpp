/* HSTMATCH module=hstp_trans_main.prx start=0x00100768 end=0x001007a8 symbol=FUN_00100768 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Unless the state word at +0x3c of the object behind DAT_003e19f0 is 9, calls virtual slot 1 (vtable +0xc) of the object at +0x3c of the argument. Twin of 0x100728 (slot 3). */
struct VC_00100768 {
  virtual void s0();
  virtual void s1();
};
struct Obj_00100768 {
  char pad[0x3c];
  VC_00100768 *vc;
};
struct Game_00100768 {
  char pad[0x3c];
  int mode;
};
extern Game_00100768 *DAT_003e19f0;

extern "C" void FUN_00100768(Obj_00100768 *o)
{
  if (DAT_003e19f0->mode != 9) {
    o->vc->s1();
  }
}
