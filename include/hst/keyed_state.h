/* A small state record that sits at the start of a subclass's own fields, after a 0x1b0-byte base. */
#ifndef HST_KEYED_STATE_H
#define HST_KEYED_STATE_H

typedef struct KeyedState {
  char base[0x1b0];
  unsigned int mode;     /* 0x1b0 mode; below 3 the frame is compared too */
  int key;               /* 0x1b4 -1 when unset */
  short frame;           /* 0x1b8 */
  unsigned char flag;    /* 0x1ba */
} KeyedState;

enum {
  KEYED_MODE_INITIAL = 6,    /* mode set by the constructor's reset */
  KEYED_KEY_NONE = -1
};

#endif
