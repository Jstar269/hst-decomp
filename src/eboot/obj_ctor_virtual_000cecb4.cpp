/* HSTMATCH module=EBOOT.BIN start=0x000cecb4 end=0x000ced88 symbol=FUN_000cecb4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: base ctor receives this, virtual slot 2 call, FUN_00057b58 takes a float first argument; readability pass; exact match verified; names and types await human review. */
extern char DAT_003074f8[];
extern char DAT_002d6374[];
extern char DAT_002d637c[];
extern "C" void FUN_000143b0(char *, char *, int);
extern "C" void FUN_00056b98(void *);
extern "C" void FUN_000573a0(void *, int, char *, int, int);
extern "C" void FUN_00057b58(float, void *, int, int);
extern "C" void FUN_00058ddc(void *, int, int);

#define PATH_BUF_SIZE 256
#define NO_INDEX (-1)

/* Model object: slot 2 of its vtable opens the first resource file. */
struct Obj {
  virtual void v0();
  virtual void v1();
  virtual void v2(char *, int, int, int, int, int);
  char pad04[0xbc];
  char unkc0;        /* 0xc0 cleared by the constructor */
  char padc1[0xef];
  int unk1b0;        /* 0x1b0 cleared by the constructor */
};

/* Constructor: builds the two resource paths from the base name (the two format strings are "%s.i3r" and "%s.i3m"), opens both and resets the state. */
extern "C" Obj *FUN_000cecb4(Obj *self, int base_name)
{
  char path[PATH_BUF_SIZE];
  FUN_00056b98(self);
  *(char **)self = DAT_003074f8;
  self->unk1b0 = 0;
  FUN_000143b0(path, DAT_002d6374, base_name);
  self->v2(path, 0, 0, 0, 0, 0);
  FUN_000143b0(path, DAT_002d637c, base_name);
  FUN_000573a0(self, 0, path, 0, 0);
  FUN_00057b58(0.0f, self, 0, 0);
  FUN_00058ddc(self, 0, NO_INDEX);
  self->unkc0 = 0;
  return self;
}
