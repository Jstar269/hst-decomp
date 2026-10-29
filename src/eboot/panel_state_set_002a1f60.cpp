/* HSTMATCH module=EBOOT.BIN start=0x002a1f60 end=0x002a22b4 symbol=FUN_002a1f60 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: switch on a local copy of the new state with cases 0,1,2 in source order [tests come out 2,1,0], the case-0 virtual call is m1(1) because a1 already holds 1 from the previous compare, the lerp re-reads the rectangle field through a char* view so it is not CSE'd, the two Vec4 args are declared b then a); names and types await human review. */
#include "hst/letter_ui.h"

struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));
struct Glob {
  char pad0[0xc];
  int unk0c;
  char pad1[0x52 - 0x10];
  unsigned char unk52;
};

extern "C" {
extern Glob *DAT_00331b84;
void FUN_000ffb3c(void *, int);
void FUN_00102c54(void *);
void FUN_00063478(Glob *, float);
void FUN_00063830(Glob *, Vec4 *, Vec4 *, int, int, int, float, float);
}

/* Switches the panel to a new state and shows/hides its parts for it. */
extern "C" void FUN_002a1f60(LetterUi *self, int new_state)
{
  self->prev = self->state;
  self->state = new_state;
  self->unk08 = 0;
  int st = self->state;
  switch (st) {
  case LETTER_STATE_0:
    self->model->m1(1);
    {
      Glob *g = DAT_00331b84;
      g->unk0c = 0;
      g->unk52 = 0;
    }
    break;
  case LETTER_STATE_1:
    if (self->prev != 1) {
      if (self->prev == 0) {
        self->model->x = 120.0f;
        FUN_00102c54(self->model);
      }
      self->model->m1(0);
      self->key10->m1(0);
      self->key20->m1(1);
      self->key30->m1(1);
      FUN_000ffb3c(self->assign10, 0);
      FUN_000ffb3c(self->assign20, 1);
      FUN_000ffb3c(self->assign30, 1);
      FUN_000ffb3c(self->letter, 1);
      Glob *g = DAT_00331b84;
      g->unk0c = 0;
      g->unk52 = 0;
    }
    break;
  case LETTER_STATE_2: {
    self->blend = 0;
    self->unk34 = (self->envelope->left + self->envelope->right) / 2;
    self->unk36 = (self->envelope->top + self->envelope->bottom) / 2;
    LetterRect *r = self->letter;
    float t = self->blend;
    short mx = (r->left + r->right) / 2;
    r->left = (short)(int)((float)mx + t * (float)(*(short *)((char *)r + 4) - mx));
    r->right = (short)(int)((float)mx + t * (float)(*(short *)((char *)r + 8) - mx));
    short my = (r->top + r->bottom) / 2;
    r->top = (short)(int)((float)my + t * (float)(*(short *)((char *)r + 6) - my));
    r->bottom = (short)(int)((float)my + t * (float)(*(short *)((char *)r + 10) - my));
    self->model->m1(0);
    self->key10->m1(1);
    self->key20->m1(1);
    self->key30->m1(1);
    FUN_000ffb3c(self->assign10, 1);
    FUN_000ffb3c(self->assign20, 1);
    FUN_000ffb3c(self->assign30, 1);
    FUN_00063478(DAT_00331b84, 1.0f + self->model->unk20);
    Vec4 b;
    Vec4 a;
    a.w = 0.75f;
    a.x = 0;
    a.y = 0;
    a.z = 0;
    b.x = 0;
    b.y = 0;
    b.z = 0;
    b.w = 0;
    FUN_00063830(DAT_00331b84, &b, &a, 5, 0, 0, 65534.0f, -1.0f);
    break;
  }
  }
}
