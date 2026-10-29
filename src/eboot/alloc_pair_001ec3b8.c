/* HSTMATCH module=EBOOT.BIN start=0x001ec3b8 end=0x001ec418 symbol=FUN_001ec3b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed merged-store null-checked constructor calls for both allocated objects; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/overlay_obj.h"

#define PART_A_SIZE 316
#define PART_B_SIZE 992

extern void *FUN_00000bcc(u32 size);
extern void *FUN_001eb784(void *);
extern void *FUN_001eab84(void *);

/* Allocate and construct the overlay's two parts. */
void FUN_001ec3b8(OverlayObj *self)
{
  void *a = FUN_00000bcc(PART_A_SIZE);
  if (a != 0) {
    a = FUN_001eb784(a);
  }
  self->part_a = a;

  void *b = FUN_00000bcc(PART_B_SIZE);
  if (b != 0) {
    b = FUN_001eab84(b);
  }
  self->part_b = b;
}
