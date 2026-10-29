/* HSTMATCH module=EBOOT.BIN start=0x001340d8 end=0x00134210 symbol=FUN_001340d8 lang=c99 rodata=0x002c1620 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00134210();
extern void FUN_00134414();
extern void FUN_00134548();
extern void FUN_00134e1c();
extern void FUN_001357dc();
extern void FUN_00136080();
extern void FUN_00136a28();
extern void FUN_00136b5c();
extern void FUN_00136c90();
extern void FUN_00136e94();
extern void FUN_00136fc8();
extern void FUN_001370fc();
extern void FUN_00137300();
extern void FUN_00137308();
extern void FUN_0013743c();
extern void FUN_00137570();

/* Owner object: the current state id at +0x1364 selects the per-state handler. */
typedef struct StateOwner {
  char pad00[0x1364];
  u32 state;          /* 0x1364 */
} StateOwner;

/* Runs the handler for the owner's current state; states 0, 10, 11, 12 and 19 have none. Handler 16 takes no argument. */
void FUN_001340d8(StateOwner *owner)
{
  switch(owner->state) {
  case 0:
  case 10:
  case 0xb:
  case 0xc:
  case 0x13:
    break;
  case 1:
    FUN_00134210(owner);
    break;
  case 2:
    FUN_00134414(owner);
    break;
  case 3:
    FUN_00134548(owner);
    break;
  case 4:
    FUN_00134e1c(owner);
    break;
  case 5:
    FUN_001357dc(owner);
    break;
  case 6:
    FUN_00136080(owner);
    break;
  case 7:
    FUN_00136a28(owner);
    break;
  case 8:
    FUN_00136b5c(owner);
    break;
  case 9:
    FUN_00136c90(owner);
    break;
  case 0xd:
    FUN_00136e94(owner);
    break;
  case 0xe:
    FUN_00136fc8(owner);
    break;
  case 0xf:
    FUN_001370fc(owner);
    break;
  case 0x10:
    FUN_00137300();
    break;
  case 0x11:
    FUN_00137308(owner);
    break;
  case 0x12:
    FUN_0013743c(owner);
    break;
  case 0x14:
    FUN_00137570(owner);
    break;
  default:
    goto switchD_00134104_default;
  }
switchD_00134104_default:
  return;
}
