/* HSTMATCH module=EBOOT.BIN start=0x000c45e0 end=0x000c4708 symbol=FUN_000c45e0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: assign the vtable before deriving the element base and set the inner iterator at the loop header. */
#include "hst/types.h"

extern char DAT_00307430[];
extern char DAT_002d5ac8[];
extern u32 DAT_00338af0;
extern u32 * FUN_0001f06c();
extern u32 * FUN_00095d64();
extern u8 * FUN_00095d94();
extern u32 * FUN_00095da8();
extern u32 * FUN_00095dd8();
extern u32 * FUN_00095e10();
extern u32 * FUN_00095e40();
extern u32 * FUN_00095e70();
extern u32 * FUN_00095ea0();
extern u32 * FUN_00095ed0();
extern u32 * FUN_00095f00();
extern u32 * FUN_00095f30();
extern u32 * FUN_00095f60();
extern u32 * FUN_00095f90();
extern void FUN_000c4708(const char *, int);
extern void FUN_000c4bd4();

#define SLOT_COUNT 4
#define SLOT_WORDS 0x74                 /* each slot is 0x1d0 bytes */
#define SLOT_BYTES (SLOT_WORDS * 4)
#define SLOTS_START 0x40               /* byte offset of the first slot */
#define OBJECT_WORDS (SLOT_WORDS * SLOT_COUNT + SLOTS_START / 4)

/* Constructor: base init, then constructs the four slots (members, then the small header fields) and registers the object as the global instance. */
u32 * FUN_000c45e0(u32 *self)
{
  u32 *slot;
  u32 *member;
  
  FUN_0001f06c(self);
  slot = (u32 *)((*(u32 *)self = (u32)DAT_00307430), (char *)self + SLOTS_START);
  do {
    member = slot + 3;
    do {
      FUN_00095f90(member);
      member = member + 1;
    } while (member < slot + 5);
    FUN_00095f60(slot + 5);
    FUN_00095f30(slot + 8);
    member = slot + 0x14;
    do {
      FUN_00095f00(member);
      member = member + 3;
    } while (member < slot + 0x1a);
    FUN_00095ed0(slot + 0x1a);
    FUN_00095ea0(slot + 0x1d);
    FUN_00095e70(slot + 0x20);
    FUN_00095e40(slot + 0x2c);
    FUN_00095e10(slot + 0x38);
    FUN_00095dd8(slot + 0x3c);
    FUN_00095da8(slot + 0x4c);
    FUN_00095d94((u8 *)(slot + 0x4e));
    FUN_00095d64(slot + 0x50);
    *(u8 *)slot = 0;
    *(u8 *)((int)slot + 1) = 0;
    *(u16 *)((int)slot + 2) = 0;
    slot[1] = 0;
    slot[2] = 0;
    slot = slot + SLOT_WORDS;
  } while (slot < self + OBJECT_WORDS);
  FUN_000c4708(DAT_002d5ac8,SLOT_BYTES);
  DAT_00338af0 = (unsigned int)(self);
  FUN_000c4bd4((int)self);
  return self;
}
