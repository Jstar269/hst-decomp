/* HSTMATCH module=EBOOT.BIN start=0x000ba78c end=0x000ba96c symbol=FUN_000ba78c lang=c++ data=0x002d4e68 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: each slot release keeps a redundant second null test (`if (p != 0) { if (p != 0) ... }`) -
   retail carries three tests per slot (outer guard, redundant guard, and delete's own test), and MWCC folds
   away a single guard. The net teardown is written as sequential early-return guards, which is what puts the
   continuation out of line and leaves `beqzl v0,<success>`. Data: its string literals (6 strings, 0x002d4e68-0x002d4f1a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

extern "C" void FUN_000009e4(void *);
extern "C" void FUN_000ba3ac(char *, ...);
extern "C" void FUN_000bae04(void *);
extern "C" void FUN_000baac8(void *);
extern "C" int FUN_002b7d78(void);
extern "C" int FUN_002b7e40(void);
extern "C" int FUN_002b7d90(void);

struct Obj {
  virtual ~Obj();
};

struct Net {
  char pad0[0x180];
  void *f180;
  void *f184;
  void *f188;
  char pad1[0x1dc - 0x18c];
  Obj *f1dc[0x10];
  unsigned char f21c[0x10];
  Obj *f22c[0x10];
  Obj *f26c;
};

extern "C" int FUN_000ba78c(Net *self)
{
  int i;
  int mode;
  Obj *p;
  char *base;

  if (self->f188 != 0) {
    if (self->f188 != 0) {
      FUN_000009e4(self->f188);
      self->f188 = 0;
    }
  }
  if (self->f184 != 0) {
    if (self->f184 != 0) {
      FUN_000009e4(self->f184);
      self->f184 = 0;
    }
  }
  if (self->f180 != 0) {
    if (self->f180 != 0) {
      FUN_000009e4(self->f180);
      self->f180 = 0;
    }
  }

  for (i = 0, base = (char *)self; i < 0x10; i++, base += 4) {
    p = *(Obj **)(base + 0x1dc);
    if (p != 0) {
      if (p != 0) {
        delete p;
        *(Obj **)(base + 0x1dc) = 0;
      }
    }
    p = *(Obj **)(base + 0x22c);
    if (p != 0) {
      if (p != 0) {
        delete p;
        *(Obj **)(base + 0x22c) = 0;
      }
    }
  }

  if (self->f26c != 0) {
    if (self->f26c != 0) {
      delete self->f26c;
      self->f26c = 0;
    }
  }
  FUN_000bae04(self);
  FUN_000baac8(self);

  mode = FUN_002b7d78();
  if (mode != 0) {
    FUN_000ba3ac("sceNetAdhocctlTerm() failed(0x%X)\n",mode);
    return 0;
  }
  FUN_000ba3ac("sceNetAdhocctlTerm() success\n");
  mode = FUN_002b7e40();
  if (mode != 0) {
    FUN_000ba3ac("sceNetAdhocTerm() failed(0x%X)\n",mode);
    return 0;
  }
  FUN_000ba3ac("sceNetAdhocTerm() success\n");
  mode = FUN_002b7d90();
  if (mode != 0) {
    FUN_000ba3ac("sceNetTerm() failed(0x%X)\n",mode);
    return 0;
  }
  FUN_000ba3ac("sceNetTerm() success\n");
  return 1;
}
