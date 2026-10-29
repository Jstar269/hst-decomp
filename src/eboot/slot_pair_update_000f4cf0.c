/* HSTMATCH module=EBOOT.BIN start=0x000f4cf0 end=0x000f4eb0 symbol=FUN_000f4cf0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3, variant v0c) corrected by hand: the flag byte and the two byte globals typed unsigned char, the flag-set case laid out first and the join loads restructured as if/else-if with no else, loop locals declared counter/table/slot/cursor, the sum computed before the slot load and the join read as one load into one local; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/inp_panes.h"

extern u8 DAT_002d7cf4;
extern u8 * DAT_00338b44;
extern unsigned char DAT_0034189b;
extern unsigned char DAT_003419bb;
extern void FUN_000de100();


void FUN_000f4cf0(int self)
{
  int i;
  u32 *row;
  int cursor;
  u32 *idPtr;
  PaneItem *target;
  int sum;
  int value;
  int base;
  unsigned char found;
  u32 ids[2];
  int mode;

  FUN_000de100(DAT_00338b44,(int *)ids,&found,&mode);
  *(u8 *)(self + 0x210) = 0;
  *(int *)(self + 0x214) = mode;
  i = 0;
  *(u8 *)(self + 0x218) = 1;
  row = (unsigned int *)(&DAT_002d7cf4);
  cursor = self;
  idPtr = ids;
  do {
    base = row[0xc2];
    if (found != 0) {
      target = *(PaneItem **)(cursor + 0x168);
      target->unk24 = base + 4;
      target->unk28 = base + 4;
    }
    else if (mode == -1) {
      sum = base + *idPtr;
      target = *(PaneItem **)(cursor + 0x168);
      target->unk24 = sum;
      target->unk28 = sum;
    }
    else if (mode == 0) {
      target = *(PaneItem **)(self + 0x168);
      target->unk24 = base + 5;
      target->unk28 = base + 5;
      target = *(PaneItem **)(self + 0x16c);
      target->unk24 = base + 3;
      target->unk28 = base + 3;
    }
    else if (mode == 1) {
      target = *(PaneItem **)(self + 0x168);
      target->unk24 = base + 3;
      target->unk28 = base + 3;
      target = *(PaneItem **)(self + 0x16c);
      target->unk24 = base + 5;
      target->unk28 = base + 5;
    }
    value = (*(PaneItem **)(cursor + 0x168))->unk24;
    target = *(PaneItem **)(cursor + 0x170);
    target->unk24 = value;
    target->unk28 = value;
    if (found != 0) {
      *(u8 *)(self + i + 0x204) = 0;
      *(u8 *)(self + 0x210) = 1;
    }
    if ((ids[0] == DAT_0034189b) && (ids[1] == DAT_003419bb)) {
      *(u8 *)(self + i + 0x204) = 0;
      *(u8 *)(self + 0x210) = 1;
      *(u8 *)(self + 0x218) = 0;
    }
    else if (ids[0] == ids[1]) {
      *(unsigned char *)(self + i + 0x204) = *(int *)(DAT_00338b44 + 0x9c) == i;
      *(u8 *)(self + 0x210) = 1;
    }
    else {
      *(unsigned char *)(self + i + 0x204) = *(int *)(DAT_00338b44 + 0x9c) == i;
    }
    i = i + 1;
    row = row + 3;
    cursor = cursor + 4;
    idPtr = idPtr + 1;
  } while (i < 2);
  *(u32 *)(self + 0x1f8) = 0;
}
