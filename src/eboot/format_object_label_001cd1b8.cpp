/* HSTMATCH module=EBOOT.BIN start=0x001cd1b8 end=0x001cd284 symbol=FUN_001cd1b8 lang=c++ */
/* Hand-written reconstruction from the disassembly (the Ghidra pseudocode's two-branch null test became a ternary); exact match verified; names and types await human review. */
extern "C" {
extern char DAT_002eaa7c[];   /* label format string */
extern char DAT_002ea308[];   /* fallback name when the table entry is empty */
extern void FUN_000149a8(char *, const char *);
extern int FUN_000143b0(char *, const char *, ...);
extern int *FUN_0014c384(int, int);
extern void FUN_0022942c(void *, char *);
}

#define KIND_NAMED 3 /* objects of this kind are labelled with a table name */
#define LABEL_SIZE 256

/* Object with a virtual Kind() query (slot 11). */
struct Labelled {
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

/* Fields of a named object. */
typedef struct {
  char pad0[4];
  int handle;         /* 0x04 */
  char pad1[0x30 - 8];
  int index;          /* 0x30 index into the owner's name table */
} NameFields;

typedef struct {
  char pad0[0x64];
  void **names;       /* 0x64 name table */
  char pad1[0x15c - 0x68];
  int *link;          /* 0x15c; the label sink sits 0x34 bytes in */
} Owner;

/* Build the label for `obj` (table name plus text for named objects, else just the text) and hand it on. */
extern "C" void FUN_001cd1b8(Owner *owner, Labelled *obj, const char *text)
{
  char label[LABEL_SIZE];

  if (obj->Kind() == KIND_NAMED) {
    NameFields *nf = (NameFields *)obj;
    void *name = owner->names[nf->index];
    name = name ? name : DAT_002ea308;
    FUN_000143b0(label, DAT_002eaa7c, (const char *)name, text,
                 *FUN_0014c384(nf->handle, 8));
  }
  else {
    FUN_000149a8(label, text);
  }
  FUN_0022942c(owner->link + 0x34 / 4, label);
}
