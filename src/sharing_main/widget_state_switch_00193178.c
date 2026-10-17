/* HSTMATCH module=hstp_trans_main.prx start=0x00193178 end=0x001934b0 symbol=FUN_00193178 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: else-if ladder rewritten as a switch (cases written 0..4), typed Obj/RecSet/Rec/Sprite views, case 1's dropped second argument restored (1) and the state passed on to FUN_00191efc, flag bytes unsigned char with the nonzero arm first, per-loop counters declared in the for statements; exact match verified; names and types await human review. */
extern void FUN_00105470(void *w, int on);
extern void *FUN_00177e98(void);
extern void FUN_001916f8(void *self, int state, int arg);
extern void FUN_00191efc(void *self, int state, int arg);

typedef struct {
  char pad[0xe];
  unsigned short flags;
} Sprite;

typedef struct {
  Sprite *sprite;
  int pad[4];
} Rec;

typedef struct {
  char pad[0x104];
  int count;
} RecSet;

typedef struct {
  char pad0[0x2488];
  void *w2488;
  char pad1[0x24b0 - 0x248c];
  void *w24b0;
  char pad2[0x24c4 - 0x24b4];
  void *w24c4;
  char pad3[0x24d8 - 0x24c8];
  void *w24d8;
  char pad4[0x28a0 - 0x24dc];
  RecSet *set;
  Rec *recs;
} Obj;

void FUN_00193178(Obj *self, int state, int arg_a, int arg_b)
{
  unsigned char *g = (unsigned char *)FUN_00177e98() + 0x59e;
  void **p2 = &self->w2488;
  void **p7 = &self->w24b0;
  void **p6 = &self->w24c4;
  void **p5 = &self->w24d8;

  switch (state) {
  case 0:
    FUN_00105470(*p2, 0);
    FUN_00105470(*p7, 1);
    FUN_00105470(*p6, 1);
    FUN_00105470(*p5, 0);
    FUN_00191efc(self, state, arg_a);
    break;
  case 1:
    FUN_00105470(*p2, 1);
    FUN_00105470(*p7, 1);
    FUN_00105470(*p6, 1);
    FUN_00105470(*p5, 1);
    break;
  case 2:
    FUN_00105470(*p2, 0);
    FUN_00105470(*p5, 1);
    if (g[9] != 0) {
      FUN_00105470(*p7, 1);
      FUN_00105470(*p6, 0);
      for (int i = 0; i < self->set->count; i++) {
        self->recs[i].sprite->flags |= 0x8000;
      }
    } else {
      FUN_00105470(*p7, 0);
      FUN_00105470(*p6, 1);
      for (int i = 0; i < self->set->count; i++) {
        self->recs[i].sprite->flags &= 0x7fff;
      }
    }
    break;
  case 3:
    FUN_00105470(*p2, 0);
    FUN_00105470(*p5, 1);
    if (g[10] != 0) {
      FUN_00105470(*p7, 1);
      FUN_00105470(*p6, 0);
      for (int i = 0; i < self->set->count; i++) {
        self->recs[i].sprite->flags |= 0x8000;
      }
    } else {
      FUN_00105470(*p7, 0);
      FUN_00105470(*p6, 1);
      for (int i = 0; i < self->set->count; i++) {
        self->recs[i].sprite->flags &= 0x7fff;
      }
    }
    break;
  case 4:
    FUN_00105470(*p2, 1);
    FUN_00105470(*p7, 1);
    FUN_00105470(*p6, 1);
    FUN_00105470(*p5, 1);
    break;
  }
  FUN_001916f8(self, state, arg_b);
}
