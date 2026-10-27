/* HSTMATCH module=hstp_trans_main.prx start=0x0016841c end=0x00168620 symbol=FUN_0016841c lang=c++ data=0x00385908 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x00385908-0x0038595e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Idioms: `if (obj == 0 || F(..) != 0)` guard, `p = alloc(0x48); if (p) p = ctor(p); self->obj = p;` (see MWCC-NOTES 'Likely-branch merged store'), `delete` of a virtual-destructor object behind an explicit null test. */
struct Obj_00051ad8 {
  virtual ~Obj_00051ad8();
};

struct Self_0016841c {
  char pad00[0x34];
  Obj_00051ad8 *obj34;
  Obj_00051ad8 *obj38;
  char pad3c[4];
  float f40;
  float f44;
  float f48;
  float f4c;
  float f50;
  float f54;
  float f58;
  float f5c;
  char pad60[0x10];
  char sub70[0x100];
  char sub170[0x200];
  char buf370[1];
};

extern "C" {
extern char DAT_003b7ebc[];
extern void *FUN_00000bcc(unsigned);
extern void FUN_000143b0(char *, char *, int);
extern int FUN_00014934(char *, char *);
extern void FUN_000149a8(char *, char *);
extern void FUN_0001c684(char *, int, char *);
extern void FUN_0001c73c(char *);
extern Obj_00051ad8 *FUN_000518d4(void *);
extern void FUN_00051ad8(Obj_00051ad8 *, char *, int);
extern void FUN_00051d38(float, Obj_00051ad8 *);
extern void FUN_00166c04(Self_0016841c *);
}

extern "C" void FUN_0016841c(Self_0016841c *self, int name, int flag)
{
  FUN_000143b0(self->buf370, "menu/loadmes/lobby/loadmes_l%02d.xb", name);
  FUN_0001c684(DAT_003b7ebc, 1, self->buf370);
  FUN_000143b0(self->buf370, "data/menu/loadmes/L%02d", name);
  if (self->obj34 == 0 || FUN_00014934(self->sub70, self->buf370) != 0) {
    if (self->obj34 != 0) {
      delete self->obj34;
      self->obj34 = 0;
    }
    Obj_00051ad8 *p = (Obj_00051ad8 *)FUN_00000bcc(0x48);
    if (p != 0) {
      p = FUN_000518d4(p);
    }
    self->obj34 = p;
    FUN_00051ad8(p, self->buf370, 0);
    FUN_00051d38(3000.0f, self->obj34);
    FUN_000149a8(self->sub70, self->buf370);
    self->f40 = 0.0f;
    self->f44 = 0.0f;
    self->f48 = 0.0f;
    self->f4c = 1.0f;
  }
  if (flag != 0) {
    FUN_000143b0(self->buf370, "data/menu/loadmes/L_f%02d", name);
    if (self->obj38 == 0 || FUN_00014934(self->sub170, self->buf370) != 0) {
      if (self->obj38 != 0) {
        delete self->obj38;
        self->obj38 = 0;
      }
      Obj_00051ad8 *p = (Obj_00051ad8 *)FUN_00000bcc(0x48);
      if (p != 0) {
        p = FUN_000518d4(p);
      }
      self->obj38 = p;
      FUN_00051ad8(p, self->buf370, 0);
      FUN_00051d38(3000.0f, self->obj38);
      FUN_000149a8(self->sub170, self->buf370);
      self->f50 = 0.0f;
      self->f54 = 0.0f;
      self->f58 = 0.0f;
      self->f5c = 1.0f;
    }
  }
  if (flag != 0) {
    FUN_00166c04(self);
  }
  FUN_0001c73c(DAT_003b7ebc);
}
