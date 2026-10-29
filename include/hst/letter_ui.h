/* Letter screen panel (C++ only: the parts have virtual methods): key and assign widgets, letter and envelope parts. */
#ifndef HST_LETTER_UI_H
#define HST_LETTER_UI_H

/* Rectangle of a part, in screen units. */
struct LetterRect {
  short unk00, unk02;
  short left, top, right, bottom; /* 0x04 */
};

/* Model part or widget; the model and the key widgets share this layout. */
struct UiPart {
  virtual void m0();
  virtual void m1(int shown);
  virtual void m2();
  virtual void m3();
  virtual void m4();
  virtual void m5(int n);
  char pad04[0x1c];
  float unk20;      /* 0x20 */
  char pad24[0x3c];
  float x;          /* 0x60 */
  float y;          /* 0x64 */
};

/* Panel states passed to the state setter. */
enum { LETTER_STATE_0 = 0, LETTER_STATE_1 = 1, LETTER_STATE_2 = 2 };

struct LetterUi {
  int state;            /* 0x00 */
  int prev;             /* 0x04 previous state */
  int unk08;            /* 0x08 cleared on every state change */
  UiPart *model;        /* 0x0c */
  UiPart *key10;        /* 0x10 */
  UiPart *key20;        /* 0x14 */
  UiPart *key30;        /* 0x18 */
  void *assign10;       /* 0x1c */
  void *assign20;       /* 0x20 */
  void *assign30;       /* 0x24 */
  LetterRect *letter;   /* 0x28 */
  LetterRect *envelope; /* 0x2c */
  short unk30;          /* 0x30 */
  short unk32;          /* 0x32 */
  short unk34;          /* 0x34 */
  short unk36;          /* 0x36 */
  float blend;          /* 0x38 interpolation factor of the envelope rectangle toward its centre */
};

#endif
