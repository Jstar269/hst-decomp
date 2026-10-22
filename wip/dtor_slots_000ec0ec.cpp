/* HSTMATCH module=EBOOT.BIN start=0x000ec0ec end=0x000ec204 symbol=FUN_000ec0ec lang=c++ */
/* Hand-written reconstruction from the disassembly; near miss (29 of 70 words differ). */
/* Virtual destructor of a class that owns an array of 16 slots (each slot 96 bytes apart, the
   managed pointer at +0x40 of the slot): the vtable pointer is reset to the base vtable
   (DAT_00307728), the base destructor FUN_000ec664 is called, then every slot that still holds a
   pointer is released through its second virtual function (vtable slot 2) and cleared. Afterwards
   the sub-objects at +0x68 and +0x58 are shrunk/destroyed, the base destructor FUN_0001f0f0 runs
   and, for a non-zero flag, the object is deleted.
   Matching idioms that DID work: the slot walk needs "#pragma opt_strength_reduction off" (retail
   recomputes (i*3)<<5 and re-reads the base pointer after the virtual call), the pointer is read
   once per slot and the slot is cleared through a second access of the array, the release is a
   virtual call on the second vtable slot (t9 = vptr[1]), the third argument of FUN_000ed8c0 is an
   empty tag passed BY VALUE (move v0,zero; seb a2,v0), and the delete uses operator delete at
   0xa00 with the "flag > 0" test.
   What still differs: only the tail (from 0xec18c on). Retail tests the three checked values in
   the argument register a0 (addiu a0,s3,104 / beqzl a0 / addiu a0,s3,88 / beqz a0, then
   beqzl a0 / move a0,s3 / beqz a0) while every spelling tried here puts them in v0/v1 (an inline
   &member expression), in a saved register (a local pointer) or tests the original (s3) instead of
   the a0 copy. The null checks themselves are on member ADDRESSES (&self->c68, &self->v58) and on
   the object pointer itself, which no spelling reproduced with the a0 register choice; the branch
   form also differs (retail uses a branch-likely for the first test of each if, a plain beqz for
   the second).
   Ruled out: nested ifs vs &&, operand order, typed/void/char* casts, references, locals used once
   or several times, callee prototypes with void* parameters, and the "check the same expression
   twice" trick. */
#pragma opt_strength_reduction off

struct VC_0 { virtual ~VC_0(); };
struct Tag {};

struct V {
  void *data;
  int size;
};

struct C {
  void *p;
  int n;
};

struct Obj {
  void *vptr;
  char pad[0x54];
  V v58;
  char pad2[8];
  C c68;
};

extern "C" {
extern char DAT_00307728[];
void FUN_000ec664(int p);
void FUN_000ed8c0(C *p, int v, Tag t);
void FUN_000ed8d0(V *p, int v);
void FUN_000ed810(Obj *p, int v);
void FUN_0001f0f0(Obj *p, int v);
void FUN_00000a00(void *p);
}

extern "C" Obj *FUN_000ec0ec(Obj *self, short flag)
{
  if (self != 0) {
    self->vptr = &DAT_00307728;
    FUN_000ec664((int)self);
    int i = 0;
    do {
      VC_0 *p = *(VC_0 **)((char *)self->v58.data + i * 96 + 0x40);
      if (p != 0) {
        delete p;
        *(VC_0 **)((char *)self->v58.data + i * 96 + 0x40) = 0;
      }
      i++;
    } while (i < 16);
    FUN_000ed8c0(&self->c68, self->c68.n, Tag());
    {
      V *v = &self->v58;
      C *c = &self->c68;
      if (c != 0 && v != 0) {
        FUN_000ed8d0(v, 0);
      }
      if (v != 0 && self != 0) {
        FUN_000ed810(self, 0);
      }
    }
    FUN_0001f0f0(self, 0);
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
// near miss from lane km2 (unreviewed)
