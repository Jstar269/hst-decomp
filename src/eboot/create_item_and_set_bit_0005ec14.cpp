/* HSTMATCH module=EBOOT.BIN start=0x0005ec14 end=0x0005ed18 symbol=FUN_0005ec14 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Creates an item of 20 bytes (operator new + the out-of-line constructor FUN_0005d638) when the third
   argument is not zero, hands the item to FUN_0005ed18 and then sets the bit (index >> 5, index & 0x1f)
   of the bit set whose array pointer is at +0xb4 of the object.
   Matching idioms: the new pointer is tested with a likely branch whose delay slot already loads the
   word at +8 of the (still null) item, the result variable is assigned the item pointer before the
   +8 test (so the test's other arm is empty and the branch to the shared tail is branch-likely).
   Names provisional. */
typedef unsigned int uint;

extern "C" void *FUN_00000bcc(unsigned);
extern "C" void *FUN_0005d638(void *, int, int, uint, uint, uint, uint, uint);
extern "C" void FUN_0005d818(void *, int);
extern "C" void FUN_0005ed18(void *, uint, void *);

typedef struct {
  char pad0[8];
  int f8;
  char padC[8];
} Obj;

typedef struct {
  char pad0[0x8c];
  int f8c;
  char pad90[0x24];
  uint *fB4;
} Self;

extern "C" void FUN_0005ec14(Self *self, uint idx, int p3, uint p4, uint p5, uint p6, uint p7, uint p8)
{
  void *r = 0;
  if (p3 != 0) {
    Obj *p = (Obj *)FUN_00000bcc(20);
    if (p != 0) {
      p = (Obj *)FUN_0005d638(p, p3, self->f8c, p4, p5, p6, p7, p8);
    }
    r = p;
    if (p->f8 == 0) {
      FUN_0005d818(p, 1);
      r = 0;
    }
  }
  FUN_0005ed18(self, idx, r);
  self->fB4[idx >> 5] |= 1u << (idx & 0x1f);
}
