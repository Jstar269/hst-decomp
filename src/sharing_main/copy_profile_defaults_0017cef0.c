/* HSTMATCH module=hstp_trans_main.prx start=0x0017cef0 end=0x0017d068 symbol=FUN_0017cef0 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/copy_profile_defaults_00170c24.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();
typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct BytePair { unsigned char first, second; } BytePair;
typedef struct ShortPair { short first, second; } ShortPair;

/* Profile record: a 0x9c-byte base followed by the default settings copied in here. */
typedef struct DataRecord {
  char pad0[0x9c];
  BytePair bytes;
  unsigned char b9e, b9f;
  signed char ba0;
  char pad1[3];
  Vec4 floats;
  float f_b4;
  int i_b8;
  short shorts[6];
} DataRecord;

/* Object that owns the profile record (reached through the root object). */
typedef struct ProfileOwner {
  char pad0[1];
  unsigned char flag1;        /* 0x01 */
  char pad2[0x528 - 2];
  DataRecord profile;         /* 0x528 */
  char pad5f0[0x61c - 0x5f0];
  int unk61c;                 /* 0x61c cleared when flag1 is set and the caller asks for it */
} ProfileOwner;
typedef struct Root { char pad[0x40]; ProfileOwner *child; } Root;

/* Menu object: only the two callbacks and the word at +0x8c are used here. */
typedef struct MenuObj {
  char pad0[0x8c];
  u32 unk8c;                  /* 0x8c */
  char pad90[0x3e8 - 0x90];
  code *unk3e8;               /* 0x3e8 callback taking the selected id */
  char pad3ec[0x540 - 0x3ec];
  code *getSelectedId;        /* 0x540 */
} MenuObj;

extern Root *DAT_003e1a08;
extern char DAT_003eab08;
extern BytePair DAT_003eaba4;
extern unsigned char DAT_003eaba6;
extern unsigned char DAT_003eaba7;
extern signed char DAT_003eaba8;
extern Vec4 DAT_003eabac;
extern float DAT_003eabbc;
extern int DAT_003eabc0;
extern short DAT_003eabc4[];
extern void FUN_00099c98();
extern void FUN_001cf8c4();

/* Notifies with the selected id, then resets the owner's profile to the built-in defaults. */
void FUN_0017cef0(MenuObj *menu, int clear_flag)
{
  u32 id;
  u32 mapped;
  id = menu->getSelectedId();
  mapped = menu->getSelectedId();
  mapped = menu->unk3e8(mapped);
  FUN_001cf8c4(0, id, mapped, 0, menu->unk8c, 0);
  if (DAT_003e1a08 != 0) {
    ProfileOwner *owner = DAT_003e1a08->child;
    DataRecord *dst = &owner->profile;
    FUN_00099c98(dst, &DAT_003eab08);
    dst->bytes = DAT_003eaba4;
    dst->b9e = DAT_003eaba6;
    dst->b9f = DAT_003eaba7;
    dst->ba0 = DAT_003eaba8;
    dst->floats = DAT_003eabac;
    dst->f_b4 = DAT_003eabbc;
    dst->i_b8 = DAT_003eabc0;
    {
      ShortPair *src = (ShortPair *)DAT_003eabc4;
      ShortPair *out = (ShortPair *)dst->shorts;
      int count = 3;
      do {
        ShortPair pair = *src;
        --count;
        *out = pair;
        ++src;
        ++out;
      } while (count > 0);
    }
    if (clear_flag != 0) {
      ProfileOwner *o = DAT_003e1a08->child;
      if (o->flag1 != 0)
        o->unk61c = 0;
    }
  }
}
