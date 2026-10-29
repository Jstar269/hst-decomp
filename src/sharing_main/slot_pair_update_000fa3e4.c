/* HSTMATCH module=hstp_trans_main.prx start=0x000fa3e4 end=0x000fa5a4 symbol=FUN_000fa3e4 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/slot_pair_update_000f4cf0.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/inp_panes.h"

extern u8 DAT_0037eacc;
extern u8 * DAT_003e1e84;
extern unsigned char DAT_003eabd3;
extern unsigned char DAT_003eacf3;
extern void FUN_000e22ec();


void FUN_000fa3e4(int self)
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

  FUN_000e22ec(DAT_003e1e84,(int *)ids,&found,&mode);
  *(u8 *)(self + 0x210) = 0;
  *(int *)(self + 0x214) = mode;
  i = 0;
  *(u8 *)(self + 0x218) = 1;
  row = (unsigned int *)(&DAT_0037eacc);
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
    if ((ids[0] == DAT_003eabd3) && (ids[1] == DAT_003eacf3)) {
      *(u8 *)(self + i + 0x204) = 0;
      *(u8 *)(self + 0x210) = 1;
      *(u8 *)(self + 0x218) = 0;
    }
    else if (ids[0] == ids[1]) {
      *(unsigned char *)(self + i + 0x204) = *(int *)(DAT_003e1e84 + 0x9c) == i;
      *(u8 *)(self + 0x210) = 1;
    }
    else {
      *(unsigned char *)(self + i + 0x204) = *(int *)(DAT_003e1e84 + 0x9c) == i;
    }
    i = i + 1;
    row = row + 3;
    cursor = cursor + 4;
    idPtr = idPtr + 1;
  } while (i < 2);
  *(u32 *)(self + 0x1f8) = 0;
}
