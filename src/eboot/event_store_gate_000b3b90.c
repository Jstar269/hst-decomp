/* HSTMATCH module=EBOOT.BIN start=0x000b3b90 end=0x000b3c68 symbol=FUN_000b3b90 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003386b8 and the flag at +0x1b4 typed as bytes, the gate split into gate = DAT != 0 then gate = (flag1b4 != 0) ^ 1 with an int gate; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/chara_player.h"

/* Game object: the sound manager pointer sits at 0xa8. */
typedef struct GameSound {
  char pad00[0xa8];
  void *sound;               /* 0xa8 */
} GameSound;

/* Table of per-slot sound records. */
typedef struct SoundWorld {
  char pad00[0x780];
  u32 unk780;                /* 0x780 */
} SoundWorld;

/* Record of the sound last played for a slot. */
typedef struct SoundRecord {
  char pad00[0x68];
  int sound;                 /* 0x68 */
  char flag;                 /* 0x6c */
  char pad6d[3];
  u32 unk70;                 /* 0x70 */
} SoundRecord;

extern GameSound *DAT_003386b0;
extern u8 DAT_003386b8;
extern SoundWorld *DAT_00338af0;
extern SoundRecord * FUN_000c4ba0();
extern int FUN_001b55a0();

/* Play sound `sound` for the player and remember it (unless the player is in state 7); also log it in the slot record. */
void FUN_000b3b90(CharaPlayer *self,int sound,u32 flag)
{
  int gate;
  SoundRecord *record;

  if ((sound != SOUND_NONE) &&
     (FUN_001b55a0(DAT_003386b0->sound,self->slot,sound,
                   flag), self->state != 7)) {
    self->last_sound = sound;
    self->last_sound_flag = (char)flag;
    gate = DAT_003386b8 != 0;
    if (gate) {
      gate = (self->flag1b4 != 0) ^ 1;
    }
    if (((gate) && (DAT_00338af0 != 0)) && (sound != SOUND_NONE)) {
      record = FUN_000c4ba0(DAT_00338af0,self->slot);
      record->unk70 = DAT_00338af0->unk780;
      record->sound = sound;
      record->flag = (char)flag;
    }
  }
}
