/* HSTMATCH module=EBOOT.BIN start=0x001734b8 end=0x0017358c symbol=FUN_001734b8 lang=c99 */
/* Hand-written reconstruction from Ghidra pseudocode: branch order (count > 0 first); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Placement {
  char pad00[0x60];
  u32 unk60;  /* 0x60 bit pattern of 322.0f */
  u32 unk64;  /* 0x64 bit pattern of 136.0f */
} Placement;

typedef struct Hud {
  char pad00[4];
  Placement **placement; /* 0x04 */
  char pad08[0x74 - 8];
  u32 unk74;     /* 0x74 bit pattern of 0.9f */
  u32 unk78;     /* 0x78 bit pattern of 0.9f */
} Hud;

typedef struct ItemDisplay {
  char pad00[0x174];
  u32 handle;    /* 0x174 */
  char pad178[0x56c - 0x178];
  int count;     /* 0x56c */
} ItemDisplay;

extern Hud *DAT_003415ac;
extern void FUN_00114168(Hud *, int, u32, int, int);
extern void FUN_00115040(Hud *, int, u32, int, int);
extern void FUN_00187294(u32, int);
extern u8 *FUN_001fea10(int, int, int);

/* With items present, reposition and scale the shared display and show one message, else show the other message. */
void FUN_001734b8(ItemDisplay *self)
{
  if (self->count > 0) {
    Hud *hud = DAT_003415ac;
    (*DAT_003415ac->placement)->unk60 = 0x43a10000;
    (*hud->placement)->unk64 = 0x43080000;
    hud = DAT_003415ac;
    DAT_003415ac->unk74 = 0x3f666666;
    hud->unk78 = 0x3f666666;
    u32 text = (unsigned int)(FUN_001fea10(0x11,5,1));
    FUN_00115040(DAT_003415ac,0,text,0,0);
    FUN_00187294(self->handle,0);
  }
  else {
    u32 text = (unsigned int)(FUN_001fea10(0x11,5,5));
    FUN_00114168(DAT_003415ac,0,text,0,0);
  }
}
