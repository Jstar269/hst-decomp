/* HSTMATCH module=EBOOT.BIN start=0x001fbebc end=0x001fbf24 symbol=FUN_001fbebc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj {
  char pad[0x58];
  void *h0;
  void *h1;
  void *h2;
  void *h3;
} Obj;

extern int FUN_000487f4();
extern void FUN_000ffb3c(void *, int);
extern void FUN_00103128(Obj *);

void FUN_001fbebc(Obj *o)
{
  if (FUN_000487f4() != 0) {
    FUN_000ffb3c(o->h0, 1);
    FUN_000ffb3c(o->h1, 1);
    FUN_000ffb3c(o->h2, 1);
    FUN_000ffb3c(o->h3, 1);
  }
  FUN_00103128(o);
}
