/* HSTMATCH module=hstp_trans_main.prx start=0x000506b8 end=0x000507f0 symbol=FUN_000506b8 lang=c99 data=0x00376964 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00376964-0x0037697d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* i3d.cpp: drop one reference of texture texID (assertion "texArray.refCnt[texID] > 0", line 1557); on the last
   reference flush (0x516a0), take the lock (0x48fb8), destruct the picture (logging "I3dPicture__Destruct %d"
   on error), decrement the texture count, free the name buffer (0x9e4), reset the entry to its built-in empty
   name slot and release the lock (0x49020). Layout shared with FUN_000505ac (the release-by-name caller). */
extern char DAT_0037638c[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_00376878[]; /* "texArray.refCnt[texID] > 0" */
extern char DAT_003763c8[]; /* "i3d.cpp" */
void FUN_0004efe0(const char *, ...);
void FUN_000516a0(void *, int);
void FUN_00048fb8(void);
void FUN_00049020(void);
int FUN_000339c0(void *);
void FUN_000009e4(void *);

typedef struct {
  char *name;
  int a;
  int b;
  int c;
} Entry;

typedef struct {
  char data[0xa0];
} Picture;

typedef struct {
  char pad0[0x204];
  Entry entries[576];
  Picture pics[576];
  char names[576][6];
  short refCnt[576];
  int count;
} TexArray;

void FUN_000506b8(TexArray *t, int texID)
{
  if (texID >= 0 && texID < 576) {
    if (!(t->refCnt[texID] > 0)) {
      FUN_0004efe0(DAT_0037638c, DAT_00376878, DAT_003763c8, 1557);
      for (;;) {
      }
    }
    if (--t->refCnt[texID] == 0) {
      Entry *e;
      int err;
      FUN_000516a0(t, 1);
      e = &t->entries[texID];
      FUN_00048fb8();
      err = FUN_000339c0(&t->pics[texID]);
      if (err != 0) {
        FUN_0004efe0("I3dPicture__Destruct %d\n", err);
      }
      t->count--;
      FUN_000009e4(e->name);
      e->name = t->names[texID];
      e->a = 0;
      e->b = 0;
      e->c = 0;
      FUN_00049020();
    }
  }
}
