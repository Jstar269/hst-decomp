/* HSTMATCH module=EBOOT.BIN start=0x0011aa84 end=0x0011aaf4 symbol=FUN_0011aa84 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern "C" {
extern void FUN_00000a00(...);
}
struct Owned { virtual ~Owned(); };

/* Object holding a single owned pointer in its first word. */
struct OwnedHolder {
  Owned *owned;   /* 0x0 */
};

/* Deleting destructor: deletes the owned object, then frees the holder when delete_flag is positive. */
extern "C" OwnedHolder * FUN_0011aa84(OwnedHolder *self,short delete_flag)
{
  if (self != 0) {
    if (self->owned != 0) {
      delete self->owned;
      self->owned = 0;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
