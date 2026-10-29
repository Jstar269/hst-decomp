/* Sound player object: the source it starts sounds from and the handle of the last one. */
#ifndef HST_SOUND_PLAYER_H
#define HST_SOUND_PLAYER_H

typedef struct SoundPlayer {
  int unk0;                     /* 0x0 */
  int source;                   /* 0x4 negative when no source is set */
  unsigned char track_last;     /* 0x8 when set, the last started handle is closed before a new one starts */
  char pad9[3];
  int last_handle;              /* 0xc handle of the last started sound, -1 when none */
} SoundPlayer;

#endif
