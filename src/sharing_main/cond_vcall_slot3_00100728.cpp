/* HSTMATCH module=hstp_trans_main.prx start=0x00100728 end=0x00100768 symbol=FUN_00100728 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Unless the state word at +0x3c of the object behind DAT_003e19f0 is 9, calls virtual slot 3 (vtable +0x14) of the object at +0x3c of the argument. Twin of 0x100768 (slot 1). */
struct VC_00100728 {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
};
struct Obj_00100728 {
  char pad[0x3c];
  VC_00100728 *vc;
};
struct Game_00100728 {
  char pad[0x3c];
  int mode;
};
extern Game_00100728 *DAT_003e19f0;

extern "C" void FUN_00100728(Obj_00100728 *o)
{
  if (DAT_003e19f0->mode != 9) {
    o->vc->s3();
  }
}
