/* HSTMATCH module=hstp_trans_main.prx start=0x0016a7f4 end=0x0016a838 symbol=FUN_0016a7f4 lang=c++ */
/* Clone of src/eboot/active_flag_virtual_call_0015e268.cpp (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* If the byte flag at +4 is set: call 0x15a118 with the word at +0x20, then virtual slot 2 (vtable +0x10) of the object at +0x40. */
struct VC_0016a7f4 {
  virtual void s0();
  virtual void s1();
  virtual void s2();
};
struct Obj_0016a7f4 {
  char pad0[4];
  unsigned char active;
  char pad1[0x1b];
  int f20;
  char pad2[0x1c];
  VC_0016a7f4 *f40;
};
extern "C" void FUN_001666f0(int);

extern "C" void FUN_0016a7f4(Obj_0016a7f4 *o)
{
  if (o->active) {
    FUN_001666f0(o->f20);
    o->f40->s2();
  }
}
