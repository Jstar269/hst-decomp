/* HSTMATCH module=hstp_trans_main.prx start=0x0011398c end=0x00113a50 symbol=FUN_0011398c lang=c99 */
/* Clone of src/eboot/FUN_0010d3e4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272
#define COLOR_MID_GRAY 0x80808080 /* all four channels at half */

/* Sprite/draw state at the tail of a larger object. */
typedef struct DrawState {
  char pad00[0xd0];
  float block[10];     /* 0xd0 cleared, then two entries set to 1 */
  u32 unkf8;           /* 0xf8 */
  s16 unkfc;           /* 0xfc */
  s16 unkfe;           /* 0xfe */
  s16 unk100;          /* 0x100 */
  s16 unk102;          /* 0x102 */
  s16 unk104;          /* 0x104 */
  float scale1[4];     /* 0x108 */
  u32 color;           /* 0x118 */
  char pad11c[4];
  float scale2[4];     /* 0x120 */
  s16 x;               /* 0x130 screen rectangle */
  s16 y;               /* 0x132 */
  s16 width;           /* 0x134 */
  s16 height;          /* 0x136 */
  u32 unk138;          /* 0x138 */
  u32 unk13c;          /* 0x13c */
  u32 unk140;          /* 0x140 */
  u8 unk144;           /* 0x144 */
  u8 unk145;           /* 0x145 */
  char pad146[2];
  float unk148;        /* 0x148 */
  u8 unk14c;           /* 0x14c */
  u8 unk14d;           /* 0x14d */
} DrawState;

extern void FUN_000114c0();

/* Reset the draw state: identity scales, mid-gray colour, full-screen rectangle. */
void FUN_0011398c(DrawState *state)
{
  state->unk148 = 100000.5f;
  FUN_000114c0(state->block,0,0x28);
  state->block[3] = 1.0f;
  state->block[4] = 1.0f;
  state->unkf8 = 0;
  state->unkfc = 0;
  state->unkfe = 0;
  state->unk100 = 0;
  state->unk102 = 0;
  state->unk104 = -1;
  state->scale1[0] = 1.0f;
  state->scale1[1] = 1.0f;
  state->scale1[2] = 1.0f;
  state->scale1[3] = 1.0f;
  state->color = COLOR_MID_GRAY;
  state->scale2[0] = 1.0f;
  state->scale2[1] = 1.0f;
  state->scale2[2] = 1.0f;
  state->scale2[3] = 1.0f;
  state->x = 0;
  state->y = 0;
  state->width = SCREEN_WIDTH;
  state->height = SCREEN_HEIGHT;
  state->unk138 = 0;
  state->unk13c = 0;
  state->unk140 = 0;
  state->unk144 = 0;
  state->unk145 = 0;
  state->unk14c = 0;
  state->unk14d = 0;
  return;
}
