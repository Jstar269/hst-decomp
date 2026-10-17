/* HSTMATCH module=hstp_trans_main.prx start=0x0013a348 end=0x0013a414 symbol=FUN_0013a348 lang=c++ */
/* Clone of src/eboot/update_attached_obj_0012edf0.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: unsigned char flag (lbu), nested bit tests merged into one && condition, virtual call at slot 1 through a struct with a dummy virtual; exact match verified; names and types await human review. */
struct C { virtual void d0(); virtual void m(int); };
struct G { char pad[0x8b]; char bits; };
struct Obj {
  char pad[0xe0];
  C *c;
  unsigned char flag;
};
extern G *DAT_003751d4;
extern int DAT_003da704;
extern int DAT_003e48b8;
extern "C" void FUN_00062160(C *, int);
extern "C" void FUN_0013a7a0(Obj *);
extern "C" void FUN_0016ac90(C *);

extern "C" void FUN_0013a348(Obj *self)
{
  if (DAT_003e48b8 == 1 && self->c != 0) {
    if (self->flag == 0) {
      self->flag = 1;
      FUN_00062160(self->c, DAT_003da704);
    }
    if (((int)DAT_003751d4->bits << 0x1c) >> 0x1e == 0 && ((int)DAT_003751d4->bits << 0x18) >> 0x1e == 1) {
      FUN_0013a7a0(self);
      FUN_00062160(self->c, DAT_003da704);
    }
    FUN_0016ac90(self->c);
    self->c->m(DAT_003da704);
  }
}
