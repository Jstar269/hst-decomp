/* HSTMATCH module=EBOOT.BIN start=0x001793e8 end=0x0017947c symbol=FUN_001793e8 lang=c++ rodata=0x002c1fa8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: `#pragma opt_strength_reduction off` keeps the loop index multiply (retail recomputes i*0xc each pass). */
#include "hst/list_host.h"

#pragma opt_strength_reduction off

/* Number of records for the given kind (kind 0: sum of the weights in the row table); 0 for unknown kinds. */
extern "C" int FUN_001793e8(ListHost *host, int kind)
{
  int total;
  switch (kind) {
  case 0: {
    unsigned int count = host->rowCount;
    total = 0;
    int i = 0;
    if (count != 0) {
      const StatRow *rows = host->rows;
      do {
        total += rows[i].weight;
        i++;
      } while (i < count);
    }
    break;
  }
  case 1: total = host->list1a.size; break;
  case 2: total = host->list2a.size; break;
  case 3:
  case 4: total = host->list3.size; break;
  case 5: total = host->unk1a8; break;
  default: total = 0; break;
  }
  return total;
}
