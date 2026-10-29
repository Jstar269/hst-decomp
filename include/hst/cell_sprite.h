/* Sprite object drawn from a grid of square cells in a texture; shared by its show/hide/update/draw sources. */
#ifndef HST_CELL_SPRITE_H
#define HST_CELL_SPRITE_H

#define CELL_SIZE 64 /* edge of one texture cell */

typedef struct SpriteState {
  char pad00[0x60];
  float x;                 /* 0x60 */
  float y;                 /* 0x64 */
  char pad68[0x78 - 0x68];
  float unk78;             /* 0x78 */
} SpriteState;

typedef struct SpriteTexture {
  char pad00[8];
  int unk08;               /* 0x08 divided by CELL_SIZE to get cells per row */
} SpriteTexture;

typedef struct CellSprite {
  char pad00[0x54];
  unsigned char hidden;    /* 0x54 */
  char pad55[0x64 - 0x55];
  int unk64;               /* 0x64 */
  SpriteState *stateA;     /* 0x68 */
  SpriteState *stateB;     /* 0x6c */
  char pad70[8];
  unsigned int *color;     /* 0x78 packed colour written by the draw source */
  char pad7c[0xb8 - 0x7c];
  SpriteTexture *texture;  /* 0xb8 */
  void *part;              /* 0xbc object with virtual slots */
  char padc0[0xd8 - 0xc0];
  int cell;                /* 0xd8 index of the cell to draw */
  char paddc[4];
  float x;                 /* 0xe0 */
  float y;                 /* 0xe4 */
} CellSprite;

#endif
