/* HSTMATCH module=EBOOT.BIN start=0x00294f8c end=0x00295068 symbol=FUN_00294f8c lang=c99 */

struct Obj {
  char pad[0x24];
  int f24;
  char pad2[0x32c - 0x28];
  int f32c;
  unsigned char f330;
};

extern char DAT_002cae44[];
extern char DAT_002cae5c[];
extern char DAT_002cacc8[];
extern char DAT_002caca4[];
extern char DAT_002cac94[];
void FUN_00294684(char *, ...);
int FUN_002b79a8(void);
int FUN_002b7768(int, void *);
int FUN_002b7738(int);

void FUN_00294f8c(struct Obj *self)
{
  int fd;
  int r;
  char buf[8];

  if (self->f24 >= 0) {
    r = FUN_002b79a8();
    if (r != 0) {
      FUN_00294684(DAT_002cae5c);
    }
    else {
      FUN_00294684(DAT_002cae44, self->f24);
    }
    self->f24 = -1;
  }
  fd = self->f32c;
  if (fd >= 0) {
    if (self->f330 != 0) {
      r = FUN_002b7768(self->f32c, buf);
      if (r < 0) {
        FUN_00294684(DAT_002cacc8, r);
      }
      self->f330 = 0;
    }
    r = FUN_002b7738(self->f32c);
    if (r != 0) {
      FUN_00294684(DAT_002caca4);
    }
    self->f32c = -1;
  }
  FUN_00294684(DAT_002cac94);
}
// NEAR 55/55 words (was 52/55): the two blocks are independent (`if (f24 >= 0) {...}` then
// `fd = self->f32c; if (fd >= 0) {...}`), and running the second one off a single `fd` local makes
// the frame and the whole block layout match retail's length. What is left is the prologue: retail
// copies `self` to s0 FIRST and then loads `f24` into a0 (the dead argument register), uses a
// likely `bltzl` with `lw a0,812(s0)` (the f32c load) in its delay, and keeps the
// FUN_002b79a8 result in a1 (`move a1,v0`) for the test; ours loads f24 into v0, moves s0 after,
// and tests v0 directly. Same scheduling question as 0x0009f0ec's `move s1,a0`.
// Also tried (both ~54/55): the pseudocode's shared `iVar1` variable with the negative arm
// assigning `iVar1 = self->f32c` (emits `bgez`+`b` instead of `bltzl`), and its mirror.
// improved by lane fm5 (unreviewed): 52 -> 40 differing words
// near miss from lane dsn3 (unreviewed)
