/* HSTMATCH module=EBOOT.BIN start=0x000a74f8 end=0x000a7590 symbol=FUN_000a74f8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float fabsf(float);

extern float DAT_0034129c;
extern int DAT_00341284;
extern void *FUN_000b3c68(void *);
extern float FUN_001640d0(void *, int, int);
extern float FUN_00164290(void *, int);

struct Obj {
  char pad[0x154];
  int idx;
};

float FUN_000a74f8(struct Obj *self)
{
  float offset = FUN_001640d0(FUN_000b3c68(self), self->idx, 0) * 0.01f + DAT_0034129c * 0.01f;
  return fabsf(offset + (0.01f * FUN_00164290(FUN_000b3c68(self), self->idx)) * (float)DAT_00341284);
}
