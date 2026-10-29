/* Parameter blocks of the PSP system-utility dialogs (message dialog, game sharing, net configuration) filled by the utility start-up sources. */
#ifndef HST_UTILITY_PARAMS_H
#define HST_UTILITY_PARAMS_H

/* Thread priorities every dialog block starts with. */
#define UTILITY_PRIO_SOUND 0x10
#define UTILITY_PRIO_GRAPHICS 0x11
#define UTILITY_PRIO_FONT 0x12
#define UTILITY_PRIO_ACCESS 0x13

/* Header shared by all dialog blocks. */
typedef struct UtilityDialogCommon {
  unsigned int size;        /* 0x00 size of the whole block */
  int language;             /* 0x04 */
  int buttonSwap;           /* 0x08 */
  int graphicsThread;       /* 0x0c */
  int accessThread;         /* 0x10 */
  int fontThread;           /* 0x14 */
  int soundThread;          /* 0x18 */
  int result;               /* 0x1c */
  int reserved[4];          /* 0x20 */
} UtilityDialogCommon;      /* size 0x30 */

/* Message dialog block (size 0x2c4). */
enum {
  MSGDIALOG_MODE_ERROR = 0,         /* shows errorValue */
  MSGDIALOG_MODE_TEXT = 1,          /* shows message */
  MSGDIALOG_OPTION_YESNO = 0x10,    /* yes/no buttons */
  MSGDIALOG_OPTION_NO_CANCEL = 0x80 /* cancel disabled */
};

typedef struct MsgDialogParams {
  UtilityDialogCommon base; /* 0x00 */
  int unk30;                /* 0x30 */
  int mode;                 /* 0x34 MSGDIALOG_MODE_* */
  unsigned int errorValue;  /* 0x38 */
  char message[0x200];      /* 0x3c */
  unsigned int options;     /* 0x23c MSGDIALOG_OPTION_* */
  unsigned int buttonPressed; /* 0x240 */
  char pad244[0x80];
} MsgDialogParams;          /* size 0x2c4 */

/* Game sharing block (size 0x64). */
enum {
  GAMESHARING_MODE_SINGLE = 1,
  GAMESHARING_DATA_MEMORY = 2
};

typedef struct GameSharingParams {
  UtilityDialogCommon base; /* 0x00 */
  int unk30;                /* 0x30 */
  int unk34;                /* 0x34 */
  char name[8];             /* 0x38 */
  int unk40;                /* 0x40 */
  int unk44;                /* 0x44 */
  int unk48;                /* 0x48 */
  int result;               /* 0x4c */
  char *filepath;           /* 0x50 */
  int mode;                 /* 0x54 GAMESHARING_MODE_* */
  int datatype;             /* 0x58 GAMESHARING_DATA_* */
  void *data;               /* 0x5c */
  unsigned int datasize;    /* 0x60 */
} GameSharingParams;        /* size 0x64 */

/* Net configuration block (size 0x44) and its ad-hoc parameter. */
typedef struct NetconfAdhocParam {
  char name[8];             /* 0x00 */
  unsigned int timeout;     /* 0x08 */
} NetconfAdhocParam;        /* size 0x0c */

typedef struct NetconfParams {
  UtilityDialogCommon base; /* 0x00 */
  int action;               /* 0x30 */
  NetconfAdhocParam *adhocParam; /* 0x34 */
  int hotspot;              /* 0x38 */
  int hotspotConnected;     /* 0x3c */
  int wifisp;               /* 0x40 */
} NetconfParams;            /* size 0x44 */

#endif
