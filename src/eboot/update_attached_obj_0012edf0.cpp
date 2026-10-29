/* HSTMATCH module=EBOOT.BIN start=0x0012edf0 end=0x0012eebc symbol=FUN_0012edf0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: unsigned char flag (lbu), nested bit tests merged into one && condition, virtual call at slot 1 through a struct with a dummy virtual; readability pass; exact match verified; names and types await human review. */
/* Object attached to the camera; the second virtual slot is called with the camera object. */
struct AttachedObj { virtual void d0(); virtual void update(int); };
struct Settings { char pad[0x8b]; char bits; };  /* bits 2-3 and 4-5 hold two small mode fields */
struct CameraObj {
  char pad[0xe0];
  AttachedObj *attached;  /* 0xe0 */
  unsigned char started;  /* 0xe4 set after the first sync */
};
extern Settings *DAT_002cfc8c;
extern int DAT_003313c4;  /* the camera */
extern int DAT_0033b578;
extern "C" void FUN_000612dc(AttachedObj *, int);
extern "C" void FUN_0012f248(CameraObj *);
extern "C" void FUN_0015e704(AttachedObj *);

/* Keeps the attached object in step with the camera while the mode flag is 1. */
extern "C" void FUN_0012edf0(CameraObj *self)
{
  if (DAT_0033b578 == 1 && self->attached != 0) {
    if (self->started == 0) {
      self->started = 1;
      FUN_000612dc(self->attached, DAT_003313c4);
    }
    if (((int)DAT_002cfc8c->bits << 0x1c) >> 0x1e == 0 && ((int)DAT_002cfc8c->bits << 0x18) >> 0x1e == 1) {
      FUN_0012f248(self);
      FUN_000612dc(self->attached, DAT_003313c4);
    }
    FUN_0015e704(self->attached);
    self->attached->update(DAT_003313c4);
  }
}
