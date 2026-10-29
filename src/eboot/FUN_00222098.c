/* HSTMATCH module=EBOOT.BIN start=0x00222098 end=0x00222134 symbol=FUN_00222098 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: supplied missing sub->fc float argument to FUN_000ee088, corrected byte flag type and float compare polarity; readability pass; exact match verified; names and types await human review. */

#define CELL_COUNT 16
#define CELL_STRIDE 0x30

typedef struct Sprite {
  char pad[8];
  int width;  /* 0x8 */
  int height; /* 0xc */
} Sprite;

/* Cell fields reach past the 0x30 stride into the next cell's bytes. */
typedef struct Cell {
  char pad[0x20];
  unsigned char shown; /* 0x20 */
  char pad21[3];
  Sprite *sprite;      /* 0x24 */
  char pad28[4];
  float alpha;         /* 0x2c */
  float unk30;         /* 0x30 */
  float unk34;         /* 0x34 */
  int unk38;           /* 0x38 */
  int unk3c;           /* 0x3c */
} Cell;

extern void FUN_000ee088(float, float, float, float, float, float, float, float, float, Sprite *, int);

/* Draw every visible cell that has a positive alpha. */
void FUN_00222098(Cell *cells)
{
  int i = 0;
  Cell *cell = cells;
  do {
    if (cell->shown != 0 && cell->alpha > 0.0f) {
      Sprite *sprite = cell->sprite;
      FUN_000ee088((float)cell->unk38, (float)cell->unk3c, cell->alpha, cell->unk34, cell->unk30, 0.0f, 0.0f, (float)sprite->width, (float)sprite->height, sprite, 0xffff);
    }
    i++;
    cell = (Cell *)((char *)cell + CELL_STRIDE);
  } while (i < CELL_COUNT);
}
