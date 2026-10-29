/* Screen manager (global DAT_003415ac) and the small objects the dialog/progress sources reach through it. */
#ifndef HST_SCREEN_MGR_H
#define HST_SCREEN_MGR_H

/* Page object; only its flag halfword is read here. */
typedef struct ScreenPage {
  char pad0[0xe];
  unsigned short flags;         /* 0x0e */
} ScreenPage;

typedef struct PageList {
  char pad0[0x10];
  ScreenPage **pages;           /* 0x10 pages[0] is the page on top */
} PageList;

/* Progress bar widget: value range at 0x1c/0x20. */
typedef struct ProgressBar {
  char pad0[0x1c];
  float minVal;                 /* 0x1c */
  float maxVal;                 /* 0x20 */
} ProgressBar;

typedef struct ScreenMgr {
  char pad0[0x54];
  PageList *pageList;           /* 0x54 */
  char pad58[0xc];
  ProgressBar *bar;             /* 0x64 */
  int mode;                     /* 0x68 */
} ScreenMgr;

/* Message/notice object: a flag byte, a text buffer and a ready flag after it. */
typedef struct NoticeObj {
  char pad0[4];
  unsigned char unk4;           /* 0x04 */
  char text[0xc0];              /* 0x05 */
  unsigned char unkc5;          /* 0xc5 set when the notice is queued */
} NoticeObj;

#endif
