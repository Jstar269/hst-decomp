/* HSTMATCH module=EBOOT.BIN start=0x0015be74 end=0x0015c078 symbol=FUN_0015be74 lang=c++ */
/* Clone of src/sharing_main/load_two_slots_0016841c.cpp (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Idioms: `if (obj == 0 || F(..) != 0)` guard, `p = alloc(0x48); if (p) p = ctor(p); self->obj = p;` (see MWCC-NOTES 'Likely-branch merged store'), `delete` of a virtual-destructor object behind an explicit null test. */
struct Obj_000511c4 {
  virtual ~Obj_000511c4();
};

struct Self_0015be74 {
  char pad00[0x34];
  Obj_000511c4 *obj34;
  Obj_000511c4 *obj38;
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
extern char DAT_002de34c[];
extern char DAT_002de370[];
extern char DAT_002de388[];
extern char DAT_0030ebf4[];
extern void *FUN_00000bcc(unsigned);
extern void FUN_000143b0(char *, char *, int);
extern int FUN_00014934(char *, char *);
extern void FUN_000149a8(char *, char *);
extern void FUN_0001cad0(char *, int, char *);
extern void FUN_0001cb88(char *);
extern Obj_000511c4 *FUN_00050fc0(void *);
extern void FUN_000511c4(Obj_000511c4 *, char *, int);
extern void FUN_00051398(float, Obj_000511c4 *);
extern void FUN_0015a62c(Self_0015be74 *);
}

extern "C" void FUN_0015be74(Self_0015be74 *self, int name, int flag)
{
  FUN_000143b0(self->buf370, DAT_002de34c, name);
  FUN_0001cad0(DAT_0030ebf4, 1, self->buf370);
  FUN_000143b0(self->buf370, DAT_002de370, name);
  if (self->obj34 == 0 || FUN_00014934(self->sub70, self->buf370) != 0) {
    if (self->obj34 != 0) {
      delete self->obj34;
      self->obj34 = 0;
    }
    Obj_000511c4 *p = (Obj_000511c4 *)FUN_00000bcc(0x48);
    if (p != 0) {
      p = FUN_00050fc0(p);
    }
    self->obj34 = p;
    FUN_000511c4(p, self->buf370, 0);
    FUN_00051398(3000.0f, self->obj34);
    FUN_000149a8(self->sub70, self->buf370);
    self->f40 = 0.0f;
    self->f44 = 0.0f;
    self->f48 = 0.0f;
    self->f4c = 1.0f;
  }
  if (flag != 0) {
    FUN_000143b0(self->buf370, DAT_002de388, name);
    if (self->obj38 == 0 || FUN_00014934(self->sub170, self->buf370) != 0) {
      if (self->obj38 != 0) {
        delete self->obj38;
        self->obj38 = 0;
      }
      Obj_000511c4 *p = (Obj_000511c4 *)FUN_00000bcc(0x48);
      if (p != 0) {
        p = FUN_00050fc0(p);
      }
      self->obj38 = p;
      FUN_000511c4(p, self->buf370, 0);
      FUN_00051398(3000.0f, self->obj38);
      FUN_000149a8(self->sub170, self->buf370);
      self->f50 = 0.0f;
      self->f54 = 0.0f;
      self->f58 = 0.0f;
      self->f5c = 1.0f;
    }
  }
  if (flag != 0) {
    FUN_0015a62c(self);
  }
  FUN_0001cb88(DAT_0030ebf4);
}
