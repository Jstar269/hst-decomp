/* Ad-hoc net-play context shared by the net task, its match state and the bundle reader. */
#ifndef HST_NET_ADHOC_H
#define HST_NET_ADHOC_H

typedef struct RefObj RefObj; /* virtual object released through its destructor slot */

/* Per-match state (allocated 0x1583c bytes). */
typedef struct MatchState {
  unsigned char active;      /* 0x00 set while the ad-hoc matching session runs */
  char pad1[3];
  int unk4;
  RefObj *ref;               /* 0x08 */
  int handle;                /* 0x0c descriptor, -1 when closed */
  int unk10;
  unsigned char unk14;
  unsigned char unk15;
  unsigned char unk16;
  unsigned char unk17;
  unsigned char unk18;
  char pad19[3];
  RefObj *obj1c;             /* 0x1c */
  char pad20[0x7420 - 0x20];
  int unk7420;
  char pad7424[0xe424 - 0x7424];
  int unke424;
  char pade428[0x15828 - 0xe428];
  int unk15828;
  int unk1582c;
  int unk15830;              /* initialised to INT_MAX */
  int unk15834;
  int unk15838;
} MatchState;

/* Net context owned by the net task (0x2c bytes). */
typedef struct NetCtx {
  unsigned char active;      /* 0x00 set while the network is up */
  char pad1[3];
  int count;                 /* 0x04 frame counter, cleared when a bundle read finishes */
  int mode;                  /* 0x08 bundle-read mode */
  MatchState *match;         /* 0x0c */
  void *buf10;               /* 0x10 */
  void *buf14;               /* 0x14 */
  void *buf18;               /* 0x18 */
  void *bundle;              /* 0x1c buffer the bundle is read into */
  int bundleSize;            /* 0x20 size of the bundle file */
  unsigned char unk24;
  char pad25[3];
  int unk28;
} NetCtx;

/* Task that owns the net context. */
typedef struct NetTask {
  void *vtbl;                /* 0x00 */
  char pad4[0x38];
  NetCtx *ctx;               /* 0x3c */
} NetTask;

#endif
