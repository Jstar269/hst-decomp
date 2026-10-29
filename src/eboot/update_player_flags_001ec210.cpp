/* HSTMATCH module=EBOOT.BIN start=0x001ec210 end=0x001ec2f0 symbol=FUN_001ec210 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_001ec210) corrected by hand: restored the dropped fourth pointer indirection, branchless int flag, bool second parameter and inverted final ternary; exact match verified; names and types await human review. */

struct Rect { char pad[0xe]; unsigned short flags; };
struct RectList { char pad[0x10]; Rect **rects; };
struct Scene { char pad[0x54]; RectList *list; };
struct Settings { char pad[0x4c]; unsigned char flag; };
struct Notify { virtual void d0(); virtual void m(int); };
struct Pane { char pad[0x24]; int unk24; int unk28; };
struct Menu {
  char pad0[0x60];
  Notify *notify;     /* 0x60 */
  char pad64[0xc0 - 0x64];
  void *unkc0;        /* 0xc0 */
  void *unkc4;        /* 0xc4 */
  char padc8[0xd0 - 0xc8];
  Pane *pane;         /* 0xd0 */
  char padd4[0x134 - 0xd4];
  int unk134;         /* 0x134 */
};

extern "C" {
extern Settings *DAT_003386b0;
extern Scene *DAT_003415ac;
extern void FUN_000ffb3c(void *, bool);
extern void FUN_00103128(Menu *);
}

/* Refresh the menu from the selection flags: notify, toggle the two widgets and set the pane values. */
extern "C" void FUN_001ec210(Menu *self)
{
  int v;
  int b;
  Pane *pane;

  v = (*DAT_003415ac->list->rects)->flags & 3;
  b = (DAT_003386b0->flag | (unsigned char)((v != 0) ^ 1)) != 0;
  self->notify->m(b);
  FUN_000ffb3c(self->unkc0, (self->unk134 != 0) || b);
  FUN_000ffb3c(self->unkc4, (self->unk134 == 0) || b);
  v = self->unk134 != 0 ? 0 : 0x16;
  pane = self->pane;
  pane->unk24 = v;
  pane->unk28 = v;
  FUN_00103128(self);
}
