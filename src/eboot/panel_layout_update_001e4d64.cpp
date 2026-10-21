/* HSTMATCH module=EBOOT.BIN start=0x001e4d64 end=0x001e5050 symbol=FUN_001e4d64 lang=c++ rodata=0x002c8c98 */
/* Hand-written reconstruction from the disassembly; matching idioms: the 20-byte Slot{item,val} array at +0x2ac addressed as &self->slots[k] pointer locals, float t first parameter (f12) passed to both lookup helpers, the non-zero mode arm written first, int sum computed before the item pointer is loaded; exact match verified; names and types await human review. */
struct Item {
  char pad[0x24];
  int f24;
  int f28;
};

struct Ui {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void m8(int, short, short, short, short);
};

struct Slot {
  Item *item;
  int val;
  int pad[3];
};

struct Self {
  char pad0[0x204];
  Ui *ui;
  char pad1[0x2ac - 0x208];
  Slot slots[7];
  char pad2[0x39c - 0x338];
  short f39c;
  short pad39e;
  int f3a0;
  short f3a4;
  short pad3a6;
  int f3a8;
};

extern void *DAT_0034a77c;

extern "C" {
float FUN_0024de20(void *, float);
int FUN_0024dd40(void *, float);
void FUN_000ffb3c(Item *, int);
}

extern "C" void FUN_001e4d64(float t, Self *self, int mode)
{
  float ratio = FUN_0024de20(DAT_0034a77c, t);
  int kind = FUN_0024dd40(DAT_0034a77c, t);
  Slot *s1 = &self->slots[1];
  Slot *s2 = &self->slots[2];
  if (kind == 9) {
    FUN_000ffb3c(s1->item, 1);
    FUN_000ffb3c(s2->item, 0);
  } else {
    FUN_000ffb3c(s1->item, 0);
    FUN_000ffb3c(s2->item, 1);
    int v = s1->val + kind;
    Item *o = s1->item;
    o->f24 = v;
    o->f28 = v;
  }
  self->ui->m8(0, self->f39c, (short)(self->f3a8 - (int)(ratio * (float)(self->f3a8 - self->f3a0))), self->f3a4, (short)self->f3a8);
  Slot *s0 = &self->slots[0];
  Slot *s4 = &self->slots[4];
  Slot *s6 = &self->slots[6];
  if (mode != 0) {
    FUN_000ffb3c(s4->item, 0);
    FUN_000ffb3c(s0->item, 0);
    Item *o;
    int v;
    switch (mode) {
    case 4:
    case 15:
      v = s0->val + 1;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 2:
      v = s0->val + 2;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 8:
      v = s0->val + 3;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 5:
      v = s0->val + 4;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 9:
      v = s0->val + 5;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 7:
      v = s0->val + 6;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 3:
      v = s0->val + 7;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 11:
      v = s0->val + 8;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 12:
      v = s0->val + 10;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 16:
      v = s0->val + 11;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 6:
      v = s0->val + 13;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 13:
      v = s0->val + 14;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 14:
      v = s0->val;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    case 1:
    case 10:
    case 17:
      break;
    default:
      v = s0->val;
      o = s0->item;
      o->f24 = v;
      o->f28 = v;
      break;
    }
    FUN_000ffb3c(s6->item, 0);
  } else {
    FUN_000ffb3c(s4->item, 1);
    FUN_000ffb3c(s0->item, 1);
    FUN_000ffb3c(s6->item, 1);
  }
}
