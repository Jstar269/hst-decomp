/* HSTMATCH module=EBOOT.BIN start=0x00124b98 end=0x00124bf8 symbol=FUN_00124b98 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
typedef struct TimedObj {
  char pad0[0x48];
  float unk48;     /* 0x48 */
  char pad4c[0x84 - 0x4c];
  float elapsed;   /* 0x84 */
  float duration;  /* 0x88 */
} TimedObj;

extern void FUN_00124bf8(TimedObj *, int, float *);

/* Restarts the timer with the given duration and passes the two float blocks on. */
void FUN_00124b98(float duration, TimedObj *self, float *slotA, float *slotB)
{
  self->unk48 = 0;
  FUN_00124bf8(self, 1, slotA);
  FUN_00124bf8(self, 2, slotB);
  self->elapsed = 0;
  self->duration = duration;
}
