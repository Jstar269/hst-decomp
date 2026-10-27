/* HSTMATCH module=EBOOT.BIN start=0x00255d74 end=0x00255ec8 symbol=FUN_00255d74 lang=c++ */
/* Clone of src/sharing_main/slot_number_layout_00266224.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Slot idx: when the entry pane exists, sets the slot's number widget to value (FUN_0010f5d4), activates it from the pane's flag bits 0-1 (second virtual), puts the second digit pane right after the first, and for an inactive one-digit value shows the first pane and moves the second to the mean of both left edges (SetX/Width helpers as in src/sharing_main/center_two_widgets_x_0026db70.cpp). Matching idioms: `short x = a->x0;` is read before the second pane pointer and the width added after (`x += Width(a)`); that creation order gives retail's a1/a2/a3 temps, while `SetX(b, a->x0 + Width(a))` schedules the width loads first; the centre sum is `int mid = ..; mid += ..;` (one expression loads the second pane first); self->nums[idx] is re-read at each use (a `Num *&` reference makes the index addu base-first). */
struct Pane {
  char pad[4];
  short x0;
  short y0;
  short x1;
  short y1;
  short pad0c;
  unsigned short flags;
};

struct Num {
  virtual void d0();
  virtual void SetActive(bool);
  char pad04[0x10 - 4];
  Pane **panes;
};

struct Entry {
  char pad0[0xc];
  Pane *pane;
  char pad10[0xa4 - 0x10];
};

struct Self {
  Entry entries[4];
  char pad290[0x310 - 0x290];
  Num *nums[4];
};

extern "C" void FUN_000ffb3c(Pane *, bool);
extern "C" void FUN_0010f5d4(Num *, int);

static inline short Width(const Pane *r) { return r->x1 - r->x0; }

static inline void SetX(Pane *r, short x)
{
  short d = x - r->x0;
  r->x0 = x;
  r->x1 += d;
}

extern "C" void FUN_00255d74(Self *self, int idx, int value)
{
  Pane *p = self->entries[idx].pane;
  if (p != 0) {
    bool on = (p->flags & 3) != 0;
    FUN_0010f5d4(self->nums[idx], value);
    self->nums[idx]->SetActive(on);
    Pane *a = self->nums[idx]->panes[0];
    short x = a->x0;
    Pane *b = self->nums[idx]->panes[1];
    x += Width(a);
    SetX(b, x);
    if (!on && value / 10 == 0) {
      FUN_000ffb3c(self->nums[idx]->panes[0], true);
      int mid = self->nums[idx]->panes[0]->x0;
      mid += self->nums[idx]->panes[1]->x0;
      SetX(self->nums[idx]->panes[1], mid / 2);
    }
  }
}
