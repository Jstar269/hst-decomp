/* HSTMATCH module=hstp_trans_main.prx start=0x0008f7c8 end=0x0008f8c0 symbol=FUN_0008f7c8 lang=c99 */
/* Clone of src/eboot/FUN_0008df24.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/ball.h"

extern u8 DAT_003b04f8;
extern u8 DAT_003b0504;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_0001ed28();
extern void FUN_000519d4();
extern void FUN_00057904();
extern int FUN_0006f6ec();
extern int * FUN_00092f18();
extern void FUN_000c5c78();
extern void FUN_0005bbd8();

/* Ball deleting destructor: tears down members in reverse order, then both bases; frees when flags > 0. */
Ball * FUN_0008f7c8(Ball *ball, short flags)
{
  BallVec *vec;

  if (ball != (Ball *)0x0) {
    ball->vtable = &DAT_003b04f8;
    ball->vtable1e0 = &DAT_003b0504;
    FUN_00000788(ball->slots, FUN_0005bbd8, sizeof(BallSlot), BALL_SLOT_COUNT);
    FUN_000519d4(ball->obj450, -1);
    FUN_0006f6ec(ball->obj448, -1);
    FUN_00057904(ball->sound, -1);
    if ((char *)ball + 0x26c != (char *)0) {
      vec = &ball->vecB;
      if ((vec != (BallVec *)0x0) && (vec != (BallVec *)0x0)) {
        FUN_00092f18(vec, 0);
      }
      vec = &ball->vecA;
      if ((vec != (BallVec *)0x0) && (vec != (BallVec *)0x0)) {
        FUN_00092f18(vec, 0);
      }
    }
    FUN_0001ed28(&ball->vtable1e0, 0);
    FUN_000c5c78(ball, 0);
    if (0 < flags) {
      FUN_00000a00(ball);
    }
  }
  return ball;
}
