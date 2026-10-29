/* Screen object driven by a phase counter, with three text boxes and three text buffers. */
#ifndef HST_PHASE_SCREEN_H
#define HST_PHASE_SCREEN_H

#include "hst/types.h"

/* Number of text boxes and of text buffers owned by the screen. */
#define PHASE_BOX_COUNT 3
#define PHASE_BUFFER_SIZE 0x400

/* Text box widget: it shows the text of the buffer set at 0xf8. */
typedef struct TextBox {
  char pad00[0xf8];
  void *buffer;       /* 0xf8 text buffer shown by the box */
  char padfc[0x138 - 0xfc];
  u32 unk138;         /* 0x138 cleared whenever the buffer is replaced */
} TextBox;

typedef struct PhaseScreen {
  char pad00[0x54];
  int phase;                                          /* 0x54 current phase, 0..4 */
  int frame;                                          /* 0x58 frames spent in the phase */
  char pad5c[4];
  int unk60;                                          /* 0x60 */
  char pad64[4];
  u32 input[2];                                       /* 0x68 pad state read by the input poll */
  u8 confirm;                                         /* 0x70 confirm button pressed this frame */
  char pad71[3];
  void *unk74;                                        /* 0x74 widget shown or hidden with the phase */
  TextBox *boxes[PHASE_BOX_COUNT];                    /* 0x78 */
  u32 unk84[5];                                       /* 0x84..0x97 */
  u32 buffer_mode;                                    /* 0x98 */
  char buffers[PHASE_BOX_COUNT][PHASE_BUFFER_SIZE];   /* 0x9c */
} PhaseScreen;

#endif
