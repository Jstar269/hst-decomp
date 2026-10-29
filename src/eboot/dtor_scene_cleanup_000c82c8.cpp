/* HSTMATCH module=EBOOT.BIN start=0x000c82c8 end=0x000c85f0 symbol=FUN_000c82c8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: FUN_00058fc0 takes -1 as its second argument (shared with the id store), FUN_0005f110(float, obj), delete[] argument, loop index/pointer in their own block-scope variables, vector clear as shrink(n, Alloc()) via a Vec cast, opt_strength_reduction off; readability pass; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#include "hst/effect_scene.h"

/* Global host object: the word at +0x44 of its sub-object at +0x90 is passed on at teardown. */
typedef struct HostSub {
  char pad00[0x44];
  u32 unk44;                  /* 0x44 */
} HostSub;
typedef struct Host {
  char pad00[0x90];
  HostSub *sub90;             /* 0x90 */
} Host;

extern "C" {
extern u8 DAT_0030759c;
extern Host * DAT_003386b0;
extern void FUN_000006e8(...);
extern void FUN_00000788(...);
extern void FUN_000009e4(void *);
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern int FUN_00053718(...);
extern int FUN_00055e48(...);
extern void FUN_00058fc0(EffectSel *, int);
extern int FUN_0005ba00(...);
extern void FUN_0005f110(float, EffectSel *);
extern int * FUN_00063e44(...);
extern void FUN_000678a0(...);
extern int * FUN_0006eb04(...);
extern void FUN_000c7ed0(...);
extern int FUN_000d5ca8(...);
extern void FUN_00056cb0(...);
extern void FUN_000c77a8(...);
extern void FUN_000c7814(...);
}
/* Word offsets of the two slot arrays inside the object. */
enum { SLOTS_A_WORD = 0x164 / 4, SLOTS_B_WORD = 0x18c / 4 };

struct Alloc {};
struct Vec { int **data; unsigned size; void shrink(int n, Alloc) { size -= n; } };
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };
struct VC_4 { virtual ~VC_4(); };
struct VC_5 { virtual ~VC_5(); };

/* Deleting destructor of the effect scene: release every owned object and array, then run the base destructor. */
extern "C" EffectScene * FUN_000c82c8(EffectScene *self,short flags)
{
  int *obj;
  void *member;
  void *ref;
  u32 index;
  
  if (self != (EffectScene *)0x0) {
    self->vtable = &DAT_0030759c;
    if (self->sel != 0) {
      self->unk1c4 = 0;
      self->unk1c8 = -1;
      EffectSel *sel = self->sel;
      if (sel != 0) {
        FUN_00058fc0(sel, -1);
        FUN_0005f110(0.0f,sel);
        sel->unkd0 = 0;
      }
    }
    if (DAT_003386b0 != 0) {
      FUN_000678a0(DAT_003386b0->sub90->unk44);
    }
    {
      int i;
      void **slot;
      i = 0;
      slot = (void **)self; /* word cursor over the object; both slot arrays are reached from it */
      do {
        obj = (int *)slot[SLOTS_A_WORD];
        if (obj != (int *)0x0) {
          delete ((VC_0 *)(obj));
          slot[SLOTS_A_WORD] = 0;
        }
        obj = (int *)slot[SLOTS_B_WORD];
        if (obj != (int *)0x0) {
          delete ((VC_1 *)(obj));
          slot[SLOTS_B_WORD] = 0;
        }
        i = i + 1;
        slot = slot + 1;
      } while (i < EFFECT_SLOT_COUNT);
    }
    if (self->unk5c != 0) {
      FUN_0005ba00(self->unk5c,1);
      self->unk5c = 0;
    }
    ref = self->unk70;
    if (ref != 0) {
      FUN_00063e44(ref,1);
      self->unk70 = 0;
    }
    obj = (int *)self->unk74;
    if (obj != (int *)0x0) {
      delete ((VC_2 *)(obj));
      self->unk74 = 0;
    }
    obj = (int *)self->unk78;
    if (obj != (int *)0x0) {
      delete ((VC_3 *)(obj));
      self->unk78 = 0;
    }
    index = 0;
    if (self->objs.size != 0) {
      do {
        obj = self->objs.data[index];
        if (obj != (int *)0x0) {
          delete ((VC_4 *)(obj));
          self->objs.data[index] = 0;
        }
        index = index + 1;
      } while (index < self->objs.size);
    }
    {
      int n = ((Vec *)&self->objs)->size;
      ((Vec *)&self->objs)->shrink(n, Alloc());
    }
    if (self->table1d0 != 0) {
      FUN_000006e8(self->table1d0,FUN_00056cb0);
      self->table1d0 = 0;
    }
    ref = self->block1d4;
    if (ref != 0) {
      FUN_000009e4(ref);
      self->block1d4 = 0;
    }
    ref = self->unk1dc;
    if (ref != 0) {
      FUN_00055e48(ref,1);
      self->unk1dc = 0;
    }
    ref = self->unk1d8;
    if (ref != 0) {
      FUN_00053718(ref,1);
      self->unk1d8 = 0;
    }
    obj = (int *)self->sel;
    if (obj != (int *)0x0) {
      delete ((VC_5 *)(obj));
      self->sel = 0;
    }
    FUN_000c7ed0(self);
    member = self->member2e0;
    if ((((member != 0) && (member != 0)) &&
        (member != 0)) && (member != 0)) {
      FUN_000d5ca8(member,0);
    }
    FUN_00000788(self->arr220,FUN_000c77a8,0xc,0x10);
    FUN_00000788(self->arr1e0,FUN_000c7814,0x10,4);
    member = &self->objs;
    if ((member != 0) && (member != 0)) {
      FUN_0006eb04(member,0);
    }
    FUN_0001f0f0(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
