/* HSTMATCH module=hstp_trans_main.prx start=0x000d28b0 end=0x000d2984 symbol=FUN_000d28b0 lang=c++ */
/* Clone of src/eboot/obj_ctor_virtual_000cecb4.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: base ctor receives this, virtual slot 2 call, FUN_000587ac takes a float first argument; exact match verified; names and types await human review. */
extern char DAT_003b07c4[];
extern char DAT_0037ce44[];
extern char DAT_0037ce4c[];
extern "C" void FUN_000143b0(char *, char *, int);
extern "C" void FUN_000577ec(void *);
extern "C" void FUN_00057ff4(void *, int, char *, int, int);
extern "C" void FUN_000587ac(float, void *, int, int);
extern "C" void FUN_00059ac0(void *, int, int);

struct Obj {
  virtual void v0();
  virtual void v1();
  virtual void v2(char *, int, int, int, int, int);
};

extern "C" Obj *FUN_000d28b0(Obj *self, int p2)
{
  char buf[256];
  FUN_000577ec(self);
  *(char **)self = DAT_003b07c4;
  *(int *)((char *)self + 0x1b0) = 0;
  FUN_000143b0(buf, DAT_0037ce44, p2);
  self->v2(buf, 0, 0, 0, 0, 0);
  FUN_000143b0(buf, DAT_0037ce4c, p2);
  FUN_00057ff4(self, 0, buf, 0, 0);
  FUN_000587ac(0.0f, self, 0, 0);
  FUN_00059ac0(self, 0, -1);
  *((char *)self + 0xc0) = 0;
  return self;
}
