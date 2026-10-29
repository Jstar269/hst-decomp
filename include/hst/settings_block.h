/* Settings block of the 0x16b000 sources: a table of 15 entries and a few clamped halfword settings. */
#ifndef HST_SETTINGS_BLOCK_H
#define HST_SETTINGS_BLOCK_H

#include "hst/types.h"

#define SETTINGS_ENTRY_COUNT 15   /* entries addressable by index */
#define SETTINGS_ENTRY_SIZE 0x38  /* bytes per entry */

typedef struct SettingsEntry {
  char pad00;
  u8 unk1;                    /* 0x01 */
  s16 unk2;                   /* 0x02 */
  char pad04[SETTINGS_ENTRY_SIZE - 4];
} SettingsEntry;

typedef struct SettingsBlock {
  char pad00[4];
  SettingsEntry entries[SETTINGS_ENTRY_COUNT]; /* 0x04 */
  char pad34c[0x1034 - 0x34c];
  u16 unk1034;                /* 0x1034 clamped setting */
  u16 unk1036;                /* 0x1036 clamped setting */
  u16 unk1038;                /* 0x1038 clamped setting */
  u16 unk103a;                /* 0x103a clamped setting */
  u8 unk103c;                 /* 0x103c on/off flag */
  char pad103d;
  u16 unk103e;                /* 0x103e */
} SettingsBlock;

#endif
