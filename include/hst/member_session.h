/* Session object of the member-packet sources: a 16-entry member table, packet buffer and mode. */
#ifndef HST_MEMBER_SESSION_H
#define HST_MEMBER_SESSION_H

enum { MEMBER_MAX = 16 };

/* Six-byte member name / key compared as a unit. */
typedef struct MemberName {
  char c[6];
} MemberName;

typedef struct MemberSlot {
  MemberName name;      /* 0x0 */
  unsigned char used;   /* 0x6 slot is occupied */
} MemberSlot;

typedef struct MemberPos {
  float x;
  float y;
} MemberPos;

typedef struct MemberSession {
  char pad00[0x10];
  unsigned short unk10; /* 0x10 */
  char pad12[0x28 - 0x12];
  int mode;             /* 0x28 */
  char pad2c[0x38 - 0x2c];
  MemberName key;       /* 0x38 name searched for in the table */
  char unk3e[0x58 - 0x3e]; /* 0x3e */
  MemberSlot members[MEMBER_MAX]; /* 0x58 */
  int values[MEMBER_MAX]; /* 0xc8 */
  char pad108[0x178 - 0x108];
  unsigned char unk178; /* 0x178 */
  char pad179[3];
  int unk17c;           /* 0x17c */
  char pad180[4];
  void *packet;         /* 0x184 packet buffer */
  char pad188[0x190 - 0x188];
  int count;            /* 0x190 number of received entries */
  int prev_count;       /* 0x194 */
  int found;            /* 0x198 index of the matching member, -1 if none */
  char pad19c[0x21c - 0x19c];
  unsigned char flags[MEMBER_MAX]; /* 0x21c */
  char pad22c[0x27c - 0x22c];
  MemberPos pos;        /* 0x27c */
} MemberSession;

#endif
