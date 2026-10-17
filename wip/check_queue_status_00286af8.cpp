/* HSTMATCH module=EBOOT.BIN start=0x00286af8 end=0x00286bc4 symbol=FUN_00286af8 lang=c++ */
/* Near miss (2 words off): Retail emits a branch-likely with xori in delay slot for boolean check:
 * retail: 00286b74 bnezl v0, 0x286b90; xori v0, v0, 1
 * ours:   00286b74 beqzl v0, 0x286b84; ... b 0x286b94; move v0, zero
 * All other instructions, stack frame, registers (s0, s1), and control flow match retail exactly.
 */

extern "C" char DAT_002fe9dc[];
extern "C" void FUN_00286acc(const char *);
extern "C" void FUN_00286db0();
extern "C" bool FUN_0014c9b8(void *, int, float);
extern "C" void FUN_00286e08(void *);

struct Sub8 {
  char pad[4];
  int field_4;
};

struct Queue {
  char pad[4];
  int *head;
  char pad2[12];
  int *curr;
};

struct Obj {
  char pad_0[8];
  Sub8 *field_8;
  Queue *queue;
  char pad_10[0x46];
  char field_56;
};

extern "C" bool FUN_00286af8(Obj *self)
{
  if (self->field_8->field_4 == 0) {
    FUN_00286acc(DAT_002fe9dc);
    return false;
  }
  FUN_00286db0();
  bool r = FUN_0014c9b8(self->field_8, 0, 1.0f);
  if (r) {
    FUN_00286e08(self);
  }
  Queue *q = self->queue;
  int bVar2 = 0;
  int *a0 = q->head;
  if (a0 != 0) {
    int ok = ((a0 != 0) ^ 1) ? 0 : ((q->curr == a0 + 1) ^ 1);
    if (ok) {
      bVar2 = 1;
    }
  }
  if (bVar2) {
    self->field_56 = 1;
  }
  return r;
}
// near miss from lane u6fr1-1 (unreviewed)
