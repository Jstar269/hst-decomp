/* HSTMATCH module=EBOOT.BIN start=0x0005ec14 end=0x0005ed18 symbol=FUN_0005ec14 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Creates an item of 20 bytes (operator new + the out-of-line constructor FUN_0005d638) when the third
   argument is not zero, hands the item to FUN_0005ed18 and then sets the bit (index >> 5, index & 0x1f)
   of the bit set (`bits`) of the object.
   Matching idioms: the new pointer is tested with a likely branch whose delay slot already loads the
   word at +8 of the (still null) item, the result variable is assigned the item pointer before the
   +8 test (so the test's other arm is empty and the branch to the shared tail is branch-likely).
   Names provisional. */
#include "hst/types.h"
#include "hst/indexed_bits.h"

extern "C" void *FUN_00000bcc(unsigned);
extern "C" void *FUN_0005d638(void *, int, int, u32, u32, u32, u32, u32);
extern "C" void FUN_0005d818(void *, int);
extern "C" void FUN_0005ed18(void *, u32, void *);

typedef struct {
  char pad0[8];
  int unk8;
  char padC[8];
} Item;

typedef IndexedBits Self;

/* Creates an item for a non-zero kind (dropping it again when its field at +8 is zero), stores it at idx and sets the idx bit. */
extern "C" void FUN_0005ec14(Self *self, u32 idx, int kind, u32 p4, u32 p5, u32 p6, u32 p7, u32 p8)
{
  void *r = 0;
  if (kind != 0) {
    Item *p = (Item *)FUN_00000bcc(20);
    if (p != 0) {
      p = (Item *)FUN_0005d638(p, kind, self->unk8c, p4, p5, p6, p7, p8);
    }
    r = p;
    if (p->unk8 == 0) {
      FUN_0005d818(p, 1);
      r = 0;
    }
  }
  FUN_0005ed18(self, idx, r);
  self->bits[idx >> 5] |= 1u << (idx & 0x1f);
}
