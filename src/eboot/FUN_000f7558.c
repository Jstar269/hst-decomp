/* HSTMATCH module=EBOOT.BIN start=0x000f7558 end=0x000f7680 symbol=FUN_000f7558 lang=c99 data=0x002d81b8 */
/* Ghidra pseudocode (hstgen.py tag a2/v0c) corrected by hand: typed helper arguments and reused the allocation result; readability pass; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002d81b8-0x002d8204) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 * FUN_000f6400();
extern void FUN_000f6774();
extern int FUN_001026b8();
extern u32 * FUN_00102e38();
extern void FUN_00103540(float param_1,int param_2);
extern void FUN_001037c8(int param_1,int param_2);
extern int FUN_001039d8();
extern void FUN_00104118();

enum { LAYOUT_SIZE = 0x54 };

/* Emoji input pane: the loaded layout, three child lookups and some default parameters. */
typedef struct EmojiPane {
  u32 *layout;      /* 0x0 */
  char pad04[0x10];
  int emoji;        /* 0x14 child "emoji" of the layout */
  int info;         /* 0x18 child "inp_info0" */
  int bg;           /* 0x1c child "inp_bg0" */
  u32 info_unk24;   /* 0x20 copy of the info child's word at 0x24 */
  u32 bg_unk24;     /* 0x24 copy of the bg child's word at 0x24 */
  char pad28[0x83c - 0x28];
  u32 unk83c[4];    /* 0x83c bit patterns of 20.0f, 0, 5.0f, 0.6f */
  char pad84c[0x860 - 0x84c];
  u32 unk860[4];    /* 0x860 bit pattern of 64.0f four times */
} EmojiPane;

/* Constructor: builds and loads the pane layout, looks up its children and sets default parameters. */
EmojiPane * FUN_000f7558(EmojiPane *self)
{
  u32 *layout;
  int child;
  
  FUN_000f6400(self);
  layout = (u32 *)FUN_00000bcc(LAYOUT_SIZE);
  if (layout != (u32 *)0x0) {
    layout = FUN_00102e38(layout);
  }
  self->layout = layout;
  FUN_00104118((int)self->layout,(u32 *)"data/menu/inpane/inp_emoji/inpaneinp_emoji.lay",0);
  FUN_00103540(3099.0f,(int)self->layout);
  FUN_001037c8((int)self->layout,-4096);
  FUN_00103540(3099.0f,(int)self->layout);
  FUN_001037c8((int)self->layout,-4096);
  FUN_000f6774((int)self,0xf);
  child = FUN_001039d8(self->layout,(u8 *)"emoji",0);
  self->emoji = child;
  child = FUN_001026b8(child,(u8 *)"inp_info0");
  self->info_unk24 = *(u32 *)(child + 0x24);
  self->info = child;
  child = FUN_001026b8(self->emoji,(u8 *)"inp_bg0");
  self->bg_unk24 = *(u32 *)(child + 0x24);
  self->bg = child;
  self->unk83c[0] = 0x41a00000;
  self->unk83c[1] = 0;
  self->unk83c[2] = 0x40a00000;
  self->unk83c[3] = 0x3f19999a;
  self->unk860[0] = 0x42800000;
  self->unk860[1] = 0x42800000;
  self->unk860[2] = 0x42800000;
  self->unk860[3] = 0x42800000;
  return self;
}
