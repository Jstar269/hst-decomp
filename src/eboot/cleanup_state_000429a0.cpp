/* HSTMATCH module=EBOOT.BIN start=0x000429a0 end=0x00042a90 symbol=FUN_000429a0 lang=c++ */
/* Clone of src/sharing_main/cleanup_state_000429c8.cpp (hstclone.py tag u6cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v16) corrected by hand: modeled the state offsets and virtual cleanup slot; exact match verified; names and types await human review. */

struct Obj {
  virtual void cleanup(int);
};
typedef struct State {
  char pad19074[0x19074];
  Obj *object;
  char pad19078[0x0c];
  int field19084;
  char pad19088[0x18];
  int field190a0;
  int *field190a4;
  int *field190a8;
  int *field190ac;
} State;
extern "C" void FUN_000009e4(int *);

extern "C" void FUN_000429a0(int param_1)
{
  State *self = (State *)param_1;
  int *p;
  Obj *obj;
  
  if (self->field190ac != 0) {
    FUN_000009e4(self->field190ac);
    self->field190ac = 0;
  }
  if (self->field190a8 != 0) {
    FUN_000009e4(self->field190a8);
    self->field190a8 = 0;
  }
  p = self->field190a4;
  if (p != 0) {
    if (p != 0) {
      FUN_000009e4((int *)((char *)p - 0x10));
    }
    self->field190a4 = 0;
  }
  obj = self->object;
  if (obj != 0) {
    if (obj != 0) {
      obj->cleanup(1);
    }
    self->object = 0;
  }
  self->field19084 = 0;
  self->field190a0 = 0;
}
