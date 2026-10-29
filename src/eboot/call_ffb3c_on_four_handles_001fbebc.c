/* HSTMATCH module=EBOOT.BIN start=0x001fbebc end=0x001fbf24 symbol=FUN_001fbebc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj {
  char pad[0x58];
  void *handle[4];   /* 0x58 */
} Obj;

extern int FUN_000487f4();
extern void FUN_000ffb3c(void *, int);
extern void FUN_00103128(Obj *);

/* If FUN_000487f4 reports true, calls FUN_000ffb3c(handle, 1) on all four handles; then FUN_00103128. */
void FUN_001fbebc(Obj *self)
{
  if (FUN_000487f4() != 0) {
    FUN_000ffb3c(self->handle[0], 1);
    FUN_000ffb3c(self->handle[1], 1);
    FUN_000ffb3c(self->handle[2], 1);
    FUN_000ffb3c(self->handle[3], 1);
  }
  FUN_00103128(self);
}
