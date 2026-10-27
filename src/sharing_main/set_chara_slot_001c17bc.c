/* HSTMATCH module=hstp_trans_main.prx start=0x001c17bc end=0x001c189c symbol=FUN_001c17bc lang=c99 */
/* Hand-written reconstruction from the disassembly (sound_manager.cpp per the assert strings; the inlined Release() is the body of FUN_001c189c, src/sharing_main/slot_release_001c189c.c); exact match verified; names and types await human review. */
typedef struct Obj {
  char pad[0x7a8];
  int idx;
} Obj;

extern char DAT_00390e3c[];
extern char DAT_00390ed4[];
extern char DAT_00390e78[];
extern void FUN_001bd5cc(char *, ...);
extern void FUN_00063304(int, int);
extern void FUN_001be964(Obj *, int, int, int, int);

enum { eMT_CHARA_NUM = 15 };

#define ASSERT(c, line) if (!(c)) { FUN_001bd5cc(DAT_00390e3c, DAT_00390ed4, DAT_00390e78, line); for (;;) {} }

static inline int HasSlot(Obj *self)
{
  int index = self->idx + 0xb4;
  int ok = index < 0x1da;
  if (!ok) return ok;
  return *(int *)((char *)self + index * 4) != 0;
}

static inline void Release(Obj *self)
{
  if (self->idx < 0) return;
  if (HasSlot(self)) {
    int index = self->idx + 0xb4;
    int *slot = (int *)((char *)self + index * 4);
    int value = *slot;
    if (value != 0) {
      FUN_00063304(value, 1);
      *slot = 0;
    }
  }
  self->idx = -1;
}

void FUN_001c17bc(Obj **param_1, int id)
{
  Obj *self = *param_1;
  ASSERT(0 <= id && id < eMT_CHARA_NUM, 2265);
  Release(self);
  self->idx = id;
  FUN_001be964(self, id + 0xb4, 0, 0, 0);
}
