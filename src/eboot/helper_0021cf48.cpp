/* HSTMATCH module=EBOOT.BIN start=0x0021cf48 end=0x0021d02c symbol=FUN_0021cf48 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: typed the four-slot interface and materialized the 64-unit divisor; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cell_sprite.h"

extern "C" {
void FUN_000edec0(float x,float y,float param_3,float param_4,float param_5,SpriteTexture *texture,u32 *color,int cellX,int cellY);
void FUN_001031e8(CellSprite *);
}

struct VC_21cf48 {
  virtual void slot0();
  virtual void slot1();
  virtual void slot2();
  virtual void slot3();
};

/* Draws the current cell of the texture (cell index split into column/row by the cells per row). */
extern "C" void FUN_0021cf48(CellSprite *self)
{
  int width;
  u32 *color;
  int cell;
  SpriteState *state;
  int perRow;
  
  if (self->hidden == 0) {
    FUN_001031e8(self);
    if ((VC_21cf48 *)self->part != (VC_21cf48 *)0x0) {
      ((VC_21cf48 *)self->part)->slot3();
    }
    if (self->texture != 0) {
      width = self->texture->unk08;
      color = self->color;
      state = self->stateA;
      perRow = width / CELL_SIZE;
      cell = self->cell;
      *color = (unsigned char)(int)(state->unk78 * 128.0f) << 0x18 | 0x808080;
      FUN_000edec0(state->x,state->y,0.5625f,1.0f,1.0f,
                   self->texture,color,cell % perRow << 6,
                   cell / perRow << 6);
    }
  }
}
