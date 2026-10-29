/* Ad-hoc network service object (0x288 bytes, global singleton) and its start-up configuration. */
#ifndef HST_ADHOC_NET_H
#define HST_ADHOC_NET_H

enum {
  ADHOC_SLOT_COUNT = 0x10,                  /* length of the per-slot tables */
  UTILITY_MODULE_NET_COMMON = 0x100,        /* module ids for the utility loader */
  UTILITY_MODULE_NET_ADHOC = 0x101,
  ADHOC_NET_SIZE = 0x288,                   /* allocation size of one service object */
  ADHOC_MAX_PAYLOAD = 0x5a4                 /* default buffer size, also the payload size handed to the matching start call */
};

typedef struct AdhocObj AdhocObj; /* virtual object released through its destructor */

/* Start-up parameters copied into the service object (defaults are filled in when none are given). */
typedef struct AdhocConfig {
  int bufSizeA;             /* 0x00 size of the first and third working buffers */
  int bufSizeB;             /* 0x04 size of the second working buffer */
  int unk08;
  int unk0c;
  int poolSize;             /* 0x10 net memory pool size handed to the net init call */
  int unk14;
  const void *product;      /* 0x18 product info passed to the ad-hoc control init call */
  const void *groupName;    /* 0x1c group name used when connecting */
} AdhocConfig;

typedef struct AdhocNet {
  const void *vtable;       /* 0x00 */
  AdhocConfig config;       /* 0x04 */
  int unk24;
  int state;                /* 0x28 ADHOC_STATE_* */
  char pad2c[0x34 - 0x2c];
  int sema;                 /* 0x34 kernel semaphore id, -1 when none */
  char unk38[0x44 - 0x38];  /* 0x38 passed by address to the matching start call */
  int unk44;
  int unk48;
  int unk4c;
  int unk50;
  int unk54;
  char pad58[0x168 - 0x58];
  unsigned char unk168;     /* 0x168 */
  char pad169[3];
  int matchingId;           /* 0x16c matching handle, -1 when closed */
  char pad170[0x178 - 0x170];
  unsigned char unk178;     /* 0x178 */
  char pad179[3];
  int unk17c;               /* 0x17c result of the matching start call */
  void *bufB;               /* 0x180 working buffer (bufSizeB bytes) */
  void *bufA;               /* 0x184 working buffer (bufSizeA bytes) */
  void *bufC;               /* 0x188 working buffer (bufSizeA bytes) */
  int unk18c;
  int unk190;
  int unk194;
  int unk198;               /* 0x198 */
  char pad19c[0x1dc - 0x19c];
  AdhocObj *slotObj[ADHOC_SLOT_COUNT];   /* 0x1dc */
  unsigned char slotFlag[ADHOC_SLOT_COUNT]; /* 0x21c */
  AdhocObj *slotAux[ADHOC_SLOT_COUNT];   /* 0x22c */
  AdhocObj *unk26c;         /* 0x26c */
  int unk270;               /* 0x270 */
  int unk274;
  unsigned char unk278;     /* 0x278 set once start-up finished */
  char pad279[3];
  char unk27c[8];           /* 0x27c */
  int unk284;
} AdhocNet;

#endif
