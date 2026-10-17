/* HSTMATCH module=hstp_trans_main.prx start=0x000a9ec0 end=0x000a9f58 symbol=FUN_000a9ec0 lang=c99 */
/* Clone of src/eboot/FUN_000a74f8.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float fabsf(float);

extern float DAT_003ea5dc;
extern int DAT_003ea5c4;
extern void *FUN_000b6e80(void *);
extern float FUN_00170860(void *, int, int);
extern float FUN_00170910(void *, int);

struct Obj {
  char pad[0x154];
  int idx;
};

float FUN_000a9ec0(struct Obj *self)
{
  float a = FUN_00170860(FUN_000b6e80(self), self->idx, 0) * 0.01f + DAT_003ea5dc * 0.01f;
  return fabsf(a + (0.01f * FUN_00170910(FUN_000b6e80(self), self->idx)) * (float)DAT_003ea5c4);
}
