/* HSTMATCH module=hstp_trans_main.prx start=0x0011fc88 end=0x0011fce4 symbol=FUN_0011fc88 lang=c99 */
/* Hand-written reconstruction from the disassembly (sprite.h checked accessor per the assert strings); exact match verified; names and types await human review. */
typedef struct Sprite Sprite;

typedef struct SpriteList {
  char pad[0x10];
  Sprite **items;
  int count;
} SpriteList;

extern char DAT_002d1384[];
extern char DAT_002d1350[];
extern char DAT_002d1344[];
extern void FUN_00110f4c(char *, ...);

#define ASSERT(c, line) if (!(c)) { FUN_00110f4c(DAT_002d1384, DAT_002d1350, DAT_002d1344, line); for (;;) {} }

Sprite *FUN_0011fc88(SpriteList *self, int sprite_index)
{
  ASSERT(sprite_index >= 0 && sprite_index < self->count, 1014);
  return self->items[sprite_index];
}
