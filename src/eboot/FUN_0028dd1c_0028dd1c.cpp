/* HSTMATCH module=EBOOT.BIN start=0x0028dd1c end=0x0028df14 symbol=FUN_0028dd1c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-a5/v17) corrected by hand: typed the four source fields as signed short to select halfword loads; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_002fef18;
extern u8 DAT_002fef24;
extern u8 DAT_00309d64;
extern char DAT_002fef1c[];
extern char DAT_002fef28[];
extern char DAT_002fef34[];
extern char DAT_002fef44[];
extern char DAT_002fef54[];
extern char DAT_002fef60[];
extern char DAT_002fef6c[];
extern char DAT_002fef78[];
extern char DAT_002fef84[];
extern char DAT_002fef90[];
extern char DAT_002fef9c[];
extern void FUN_000ffb3c(...);
struct Child;
extern Child * FUN_001026b8(...);
extern void * FUN_001039d8(...);
extern u32 * FUN_00257be0(...);
extern void FUN_0027fed8(...);
}
/* Virtual-call views of the widgets and of the object itself. */
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

/* Looked-up child node: halfword at 0x4 and a widget pointer at 0x20. */
struct Child {
  char pad0[4];
  short unk4;       /* 0x04 */
  char pad6[0x1a];
  int *unk20;       /* 0x20 */
};

/* Two 0x10-byte state blocks initialised by FUN_0027fed8. */
struct StateBlock {
  int unk0;               /* 0x0 */
  unsigned short unk4;    /* 0x4 */
  char pad6[2];
  int unk8;               /* 0x8 */
  unsigned char unkc;     /* 0xc */
  char padd[3];
};

struct ContextObj {
  int *vtable;              /* 0x0000 */
  char pad0004[0x650 - 4];
  Child *unk650;            /* 0x0650 */
  char pad0654[0x6a8 - 0x654];
  int unk6a8;               /* 0x06a8 */
  char pad06ac[0x1850 - 0x6ac];
  int unk1850;              /* 0x1850 */
  char pad1854[8];
  Child *unk185c;           /* 0x185c */
  char pad1860[4];
  Child *unk1864;           /* 0x1864 */
  Child *unk1868;           /* 0x1868 */
  StateBlock state_a;       /* 0x186c */
  StateBlock state_b;       /* 0x187c */
  int *unk188c;             /* 0x188c widget, reset with the 0x80000000 flag */
  int *unk1890;             /* 0x1890 widget, reset with the 0x80000000 flag */
  char pad1894[0x1b94 - 0x1894];
  int *unk1b94;             /* 0x1b94 */
  void *unk1b98;            /* 0x1b98 */
  Child *unk1b9c;           /* 0x1b9c */
  Child *unk1ba0;           /* 0x1ba0 */
  Child *unk1ba4;           /* 0x1ba4 */
  Child *unk1ba8;           /* 0x1ba8 */
  short unk1bac;            /* 0x1bac */
  short unk1bae;            /* 0x1bae */
  short unk1bb0;            /* 0x1bb0 */
  short unk1bb2;            /* 0x1bb2 */
  Child *unk1bb4;           /* 0x1bb4 */
  char pad1bb8[8];
};

/* Constructor: sets up the base, looks up the named child nodes and widgets, and finishes with a virtual init call. */
extern "C" ContextObj * FUN_0028dd1c(ContextObj *self)
{
  void *root;
  Child *node;
  int *widget;
  
  FUN_00257be0();
  self->vtable = (int *)&DAT_00309d64;
  self->state_a.unk0 = 0;
  self->state_a.unk4 = 0;
  self->state_a.unk8 = 0;
  self->state_a.unkc = 0;
  self->state_b.unk0 = 0;
  self->state_b.unk4 = 0;
  self->state_b.unk8 = 0;
  self->state_b.unkc = 0;
  root = FUN_001039d8(self,&DAT_002fef18,0);
  node = FUN_001026b8(root,DAT_002fef1c);
  self->unk185c = node;
  self->unk1b98 = FUN_001039d8(self,&DAT_002fef24,0);
  node = FUN_001026b8(self->unk1b98,DAT_002fef28);
  self->unk1b94 = node->unk20;
  node = FUN_001026b8(self->unk1b98,DAT_002fef34);
  self->unk1864 = node;
  node = FUN_001026b8(self->unk1b98,DAT_002fef44);
  self->unk1868 = node;
  FUN_0027fed8(&self->state_a,self->unk1864,1);
  FUN_0027fed8(&self->state_b,self->unk1868,0);
  node = FUN_001026b8(self->unk1b98,DAT_002fef54);
  widget = node->unk20;
  self->unk188c = widget;
  ((VC_0 *)(widget))->m((int)(0x80000000));
  node = FUN_001026b8(self->unk1b98,DAT_002fef60);
  widget = node->unk20;
  self->unk1890 = widget;
  ((VC_1 *)(widget))->m((int)(0x80000000));
  node = FUN_001026b8(self->unk650,DAT_002fef6c);
  self->unk1b9c = node;
  node = FUN_001026b8(self->unk650,DAT_002fef78);
  self->unk1ba0 = node;
  node = FUN_001026b8(self->unk650,DAT_002fef84);
  self->unk1ba4 = node;
  node = FUN_001026b8(self->unk650,DAT_002fef90);
  self->unk1ba8 = node;
  self->unk1bac = self->unk1b9c->unk4;
  self->unk1bae = self->unk1ba0->unk4;
  self->unk1bb0 = self->unk1ba4->unk4;
  self->unk1bb2 = self->unk1ba8->unk4;
  node = FUN_001026b8(self->unk650,DAT_002fef9c);
  self->unk1bb4 = node;
  FUN_000ffb3c(self->unk6a8,1);
  self->unk1850 = 0;
  ((VC_2 *)(self))->m();
  return self;
}
