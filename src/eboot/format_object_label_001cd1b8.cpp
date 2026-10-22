/* HSTMATCH module=EBOOT.BIN start=0x001cd1b8 end=0x001cd284 symbol=FUN_001cd1b8 lang=c++ */
/* Hand-written reconstruction from the disassembly (the Ghidra pseudocode's two-branch null test became a ternary); exact match verified; names and types await human review. */
extern "C" {
extern char DAT_002eaa7c[];
extern char DAT_002ea308[];
extern void FUN_000149a8(char *, const char *);
extern int FUN_000143b0(char *, const char *, ...);
extern int *FUN_0014c384(int, int);
extern void FUN_0022942c(void *, char *);
}

struct Name {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
  virtual void v10();
  virtual int Kind();
};

typedef struct {
  char pad0[4];
  int handle;
  char pad1[0x30 - 8];
  int index;
} NameFields;

typedef struct {
  char pad0[0x64];
  void **names;
  char pad1[0x15c - 0x68];
  int *link;
} Owner;

extern "C" void FUN_001cd1b8(Owner *param_1, Name *param_2, const char *param_3)
{
  char buf[256];

  if (param_2->Kind() == 3) {
    NameFields *nf = (NameFields *)param_2;
    void *name = param_1->names[nf->index];
    name = name ? name : DAT_002ea308;
    FUN_000143b0(buf, DAT_002eaa7c, (const char *)name, param_3,
                 *FUN_0014c384(nf->handle, 8));
  }
  else {
    FUN_000149a8(buf, param_3);
  }
  FUN_0022942c(param_1->link + 0x34 / 4, buf);
}
