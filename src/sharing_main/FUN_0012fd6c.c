/* HSTMATCH module=hstp_trans_main.prx start=0x0012fd6c end=0x0012fdcc symbol=FUN_0012fd6c lang=c99 */
/* Clone of src/eboot/FUN_00124b98.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
typedef struct TimedObj {
  char pad0[0x48];
  float unk48;     /* 0x48 */
  char pad4c[0x84 - 0x4c];
  float elapsed;   /* 0x84 */
  float duration;  /* 0x88 */
} TimedObj;

extern void FUN_0012fdcc(TimedObj *, int, float *);

/* Restarts the timer with the given duration and passes the two float blocks on. */
void FUN_0012fd6c(float duration, TimedObj *self, float *slotA, float *slotB)
{
  self->unk48 = 0;
  FUN_0012fdcc(self, 1, slotA);
  FUN_0012fdcc(self, 2, slotB);
  self->elapsed = 0;
  self->duration = duration;
}
