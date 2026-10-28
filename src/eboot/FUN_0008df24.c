/* HSTMATCH module=EBOOT.BIN start=0x0008df24 end=0x0008e01c symbol=FUN_0008df24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ball.h"

extern u8 DAT_0030722c;
extern u8 DAT_00307238;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_0001f0f0();
extern void FUN_000510c0();
extern void FUN_00056cb0();
extern int FUN_0006e024();
extern int * FUN_00091280();
extern void FUN_000c24a8();
extern void FUN_0005aeac();

/* Ball deleting destructor: tears down members in reverse order, then both bases; frees when flags > 0. */
Ball * FUN_0008df24(Ball *ball, short flags)
{
  BallVec *vec;

  if (ball != (Ball *)0x0) {
    ball->vtable = &DAT_0030722c;
    ball->vtable1e0 = &DAT_00307238;
    FUN_00000788(ball->slots, FUN_0005aeac, sizeof(BallSlot), BALL_SLOT_COUNT);
    FUN_000510c0(ball->obj450, -1);
    FUN_0006e024(ball->obj448, -1);
    FUN_00056cb0(ball->sound, -1);
    if ((char *)ball + 0x26c != (char *)0) {
      vec = &ball->vecB;
      if ((vec != (BallVec *)0x0) && (vec != (BallVec *)0x0)) {
        FUN_00091280(vec, 0);
      }
      vec = &ball->vecA;
      if ((vec != (BallVec *)0x0) && (vec != (BallVec *)0x0)) {
        FUN_00091280(vec, 0);
      }
    }
    FUN_0001f0f0(&ball->vtable1e0, 0);
    FUN_000c24a8(ball, 0);
    if (0 < flags) {
      FUN_00000a00(ball);
    }
  }
  return ball;
}
