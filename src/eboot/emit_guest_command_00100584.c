/* HSTMATCH module=EBOOT.BIN start=0x00100584 end=0x00100614 symbol=FUN_00100584 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: preserved the narrowed flag and typed row indexing; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Display-list command words: opcode in the top byte, y << 10 | x in the rest. */
#define GE_SCISSOR1 0xd4000000U
#define GE_SCISSOR2 0xd5000000U

#define CLIP_FLAGS 0x600  /* either bit means a clip rectangle applies */
#define CLIP_FIRST 0x200  /* set: use rect[0], clear: rect[1] */

typedef struct ClipRect { short x1; short y1; short x2; short y2; } ClipRect;

typedef struct ClipOwner {
  char pad00[0x4c];
  ClipRect rect[2];         /* 0x4c */
} ClipOwner;

typedef struct ClipSource {
  char pad00[0xe];
  u16 flags;                /* 0xe */
} ClipSource;

extern void FUN_00051478();

/* Emits the scissor rectangle chosen by the source's flags. */
void FUN_00100584(ClipOwner *self,ClipSource *src)
{
  int y2;
  int x2;
  int offset;
  ClipOwner *base;
  u8 sel;
  
  if ((src->flags & CLIP_FLAGS) != 0) {
    sel = ((src->flags & CLIP_FIRST) != 0) ^ 1;
    offset = sel * sizeof(ClipRect);
    offset += (int)self;
    base = (ClipOwner *)offset;
    x2 = base->rect[0].x2;
    y2 = base->rect[0].y2;
    FUN_00051478(self,(int)base->rect[0].y1 << 10 | GE_SCISSOR1 |
                         (int)base->rect[0].x1);
    FUN_00051478(self,(int)y2 << 10 | GE_SCISSOR2 | (int)x2);
  }
}
