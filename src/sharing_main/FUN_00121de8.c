/* HSTMATCH module=hstp_trans_main.prx start=0x00121de8 end=0x00121eb4 symbol=FUN_00121de8 lang=c99 data=0x003801d0 */
/* Clone of src/eboot/FUN_00116ecc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x003801d0-0x0038022d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

#define REPLAY_SHOT_COUNT 9 /* 9 * 0x70 bytes = the 0x3f0 printed for sizeof(m_Shot) */

extern u8 DAT_003b1274;
extern u32 * FUN_000114c0();
extern u32 * FUN_0001ec44();
extern void FUN_00121eb4();
extern void FUN_00121f3c();

typedef struct ReplayShot {
  char pad00[0x2c];
  u32 unk2c;     /* 0x2c */
  char pad30[0x10];
  u32 unk40;     /* 0x40 */
  char pad44[0xc];
  u32 unk50;     /* 0x50 */
  u32 unk54;     /* 0x54 */
  u32 unk58;     /* 0x58 */
  u32 unk5c;     /* 0x5c */
  u8 unk60;      /* 0x60 */
  u8 unk61;      /* 0x61 */
  char pad62[0xe];
} ReplayShot;    /* 0x70 bytes */

typedef struct ReplayObj {
  const void *vtable; /* 0x00 */
  char pad04[0x38];
  u32 unk3c;          /* 0x3c */
  u8 unk40;           /* 0x40 */
  char pad41[0x3f];
  ReplayShot shots[REPLAY_SHOT_COUNT]; /* 0x80 */
} ReplayObj;

/* Constructor: base constructor, class vtable, clears every shot record, prints the record sizes. */
ReplayObj * FUN_00121de8(ReplayObj *self)
{
  ReplayShot *shot;

  FUN_0001ec44();
  self->vtable = &DAT_003b1274;
  self->unk3c = 4;
  self->unk40 = 0;
  shot = self->shots;
  do {
    shot->unk2c = 1;
    FUN_000114c0(shot,0,0x40);
    shot->unk40 = 0;
    shot->unk50 = 0;
    shot->unk54 = 0;
    shot->unk58 = 0;
    shot->unk5c = 0;
    shot->unk60 = 0;
    shot->unk61 = 0;
    shot = shot + 1;
  } while (shot < self->shots + REPLAY_SHOT_COUNT);
  FUN_00121eb4("Replay sizeof(m_Shot)   %7d\n",0x3f0);
  FUN_00121eb4("Replay sizeof(m_Player) %7d\n",0x90);
  FUN_00121eb4("Replay sizeof(m_Common) %7d\n",0x24);
  FUN_00121f3c(self);
  return self;
}
