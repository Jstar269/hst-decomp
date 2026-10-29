/* Avatar object (character with a skeleton): the fields its constructor, destructor and mode setup touch. */
#ifndef HST_AVATAR_OBJ_H
#define HST_AVATAR_OBJ_H

typedef struct AvatarElem AvatarElem;
typedef struct AvatarSkel AvatarSkel;

typedef struct AvatarVec4 {
  float x, y, z, w;
} AvatarVec4;

/* Sub-object at 0x370 (built by its own constructor): two member containers cleared on destruction. */
typedef struct AvatarParts {
  char pad00[0x70];
  char unk70[0x14];               /* 0x70 */
  char unk84[0x1c];               /* 0x84 */
} AvatarParts;

typedef struct Avatar {
  void *vtbl;                     /* 0x000 */
  char pad004[0x4c];
  AvatarElem *elem;               /* 0x050 */
  char pad054[4];
  AvatarSkel *skel;               /* 0x058 skeleton with the bone positions */
  char pad05c[0x14];
  int unk70;                      /* 0x070 */
  char pad074[0x6c];
  void *vtbl2;                    /* 0x0e0 */
  char pad0e4[0x6c];
  int unk150;                     /* 0x150 */
  int unk154;                     /* 0x154 */
  char pad158[0x8];
  int unk160;                     /* 0x160 */
  int unk164;                     /* 0x164 */
  int unk168;                     /* 0x168 */
  int unk16c;                     /* 0x16c */
  AvatarVec4 vec170;              /* 0x170 */
  AvatarVec4 vec180;              /* 0x180 */
  int unk190;                     /* 0x190 */
  int unk194;                     /* 0x194 */
  int unk198;                     /* 0x198 */
  char pad19c[0x4];
  int unk1a0;                     /* 0x1a0 */
  int unk1a4;                     /* 0x1a4 */
  int unk1a8;                     /* 0x1a8 */
  int unk1ac;                     /* 0x1ac */
  AvatarVec4 vec1b0;              /* 0x1b0 */
  AvatarVec4 vec1c0;              /* 0x1c0 */
  AvatarVec4 vec1d0;              /* 0x1d0 */
  unsigned char unk1e0;           /* 0x1e0 */
  char pad1e1[0x3];
  int unk1e4;                     /* 0x1e4 */
  int unk1e8;                     /* 0x1e8 */
  char pad1ec[0x4];
  AvatarVec4 vec1f0;              /* 0x1f0 */
  AvatarVec4 vec200;              /* 0x200 */
  AvatarVec4 vec210;              /* 0x210 */
  unsigned char unk220;           /* 0x220 */
  unsigned char unk221;           /* 0x221 */
  char pad222[0x2];
  int unk224;                     /* 0x224 */
  char pad228[0x8];
  AvatarVec4 vec230;              /* 0x230 */
  AvatarVec4 vec240;              /* 0x240 */
  int unk250;                     /* 0x250 */
  unsigned char unk254;           /* 0x254 */
  char pad255[0x3];
  char parts258[0xc8];            /* 0x258 sub-object with its own constructor and destructor */
  float unk320;                   /* 0x320 */
  float unk324;                   /* 0x324 */
  float unk328;                   /* 0x328 */
  unsigned char unk32c;           /* 0x32c */
  unsigned char unk32d;           /* 0x32d */
  char pad32e[0x2];
  int unk330;                     /* 0x330 */
  int unk334;                     /* 0x334 */
  unsigned char unk338;           /* 0x338 */
  unsigned char unk339;           /* 0x339 */
  char pad33a[0x2];
  int unk33c;                     /* 0x33c */
  int unk340;                     /* 0x340 */
  int unk344;                     /* 0x344 */
  int unk348;                     /* 0x348 */
  unsigned char unk34c;           /* 0x34c */
  char pad34d[0x3];
  int unk350;                     /* 0x350 */
  int unk354;                     /* 0x354 */
  int unk358;                     /* 0x358 */
  int unk35c;                     /* 0x35c */
  int unk360;                     /* 0x360 */
  unsigned char unk364;           /* 0x364 */
  unsigned char unk365;           /* 0x365 */
  unsigned char unk366;           /* 0x366 */
  unsigned char unk367;           /* 0x367 */
  unsigned char unk368;           /* 0x368 */
  unsigned char unk369;           /* 0x369 */
  char pad36a[0x6];
  AvatarParts parts370;           /* 0x370 */
  unsigned char unk410;           /* 0x410 */
  char pad411[0x3];
  int unk414;                     /* 0x414 */
  int unk418;                     /* 0x418 */
  int unk41c;                     /* 0x41c */
} Avatar;

#endif
