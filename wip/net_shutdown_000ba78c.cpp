/* HSTMATCH module=EBOOT.BIN start=0x000ba78c end=0x000ba96c symbol=FUN_000ba78c lang=c++ */
/* NEAR MISS 120/120 words, 2 differ (0xba818: MWCC gives the loop's redundant second null test as
   `beqzl` with the f22c reload in its delay; retail has a plain `beqz` + `nop` targeting the reload).
   Structure confirmed: three sequential `if (p != 0) { FUN_000009e4(p); p = 0; }` blocks whose
   doubled null test comes from a redundant nested if, a 16-entry loop walking `(char *)self` in steps of 4
   (`*(Obj **)(base + 0x1dc)` then `*(Obj **)(base + 0x22c)`), `delete` on a class with a virtual dtor
   (vtable slot 8 with a1 = 1), and the net teardown written as sequential early-return guards
   (`if (mode != 0) { log(failed, mode); return 0; }`) - the guard body inline, the continuation out of
   line, which is what gives retail's `beqzl v0,<success>` layout. The three slot-loop tests need the
   redundant nesting (`if (p != 0) { if (p != 0) { delete p; ... } }`) to reach 120 words. */
extern "C" char s_sceNetAdhocctlTerm___success_002d4e8c[];
extern "C" char s_sceNetAdhocctlTerm___failed_0x_X_002d4e68[];
extern "C" char s_sceNetAdhocTerm___failed_0x_X__002d4eac[];
extern "C" char s_sceNetAdhocTerm___success_002d4ecc[];
extern "C" char s_sceNetTerm___failed_0x_X__002d4ee8[];
extern "C" char s_sceNetTerm___success_002d4f04[];

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
  Obj *f1dc[0x14];
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
      p = *(Obj **)(base + 0x22c);
    }
    else {
      p = *(Obj **)(base + 0x22c);
    }
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
    FUN_000ba3ac(s_sceNetAdhocctlTerm___failed_0x_X_002d4e68,mode);
    return 0;
  }
  FUN_000ba3ac(s_sceNetAdhocctlTerm___success_002d4e8c);
  mode = FUN_002b7e40();
  if (mode != 0) {
    FUN_000ba3ac(s_sceNetAdhocTerm___failed_0x_X__002d4eac,mode);
    return 0;
  }
  FUN_000ba3ac(s_sceNetAdhocTerm___success_002d4ecc);
  mode = FUN_002b7d90();
  if (mode != 0) {
    FUN_000ba3ac(s_sceNetTerm___failed_0x_X__002d4ee8,mode);
    return 0;
  }
  FUN_000ba3ac(s_sceNetTerm___success_002d4f04);
  return 1;
}
// near miss from lane fm7 (unreviewed)
