/* HSTMATCH module=EBOOT.BIN start=0x00291868 end=0x002918f0 symbol=FUN_00291868 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: replaced raw offsets with a struct and recovered the dropped argument of FUN_002b79a8; exact match verified; names and types await human review. */
typedef struct Obj { char pad[0x14]; int fd; } Obj;

extern char DAT_002ff9bc[];
extern char DAT_002ff9dc[];
extern void FUN_0028fb44();
extern int FUN_002b78d8();
extern void FUN_002b79a8(int);

int FUN_00291868(Obj *self)
{
  Obj *local_4;
  int r;

  if (self->fd < 0) {
    FUN_0028fb44(DAT_002ff9bc);
    r = 0;
  } else {
    local_4 = self;
    if (FUN_002b78d8(self->fd, 4, &local_4) < 0) {
      FUN_0028fb44(DAT_002ff9dc, self->fd);
      if (self->fd >= 1) {
        FUN_002b79a8(self->fd);
        self->fd = -1;
      }
      r = 0;
    } else {
      r = 1;
    }
  }
  return r;
}
