/* HSTMATCH module=hstp_trans_main.prx start=0x00105e28 end=0x00105e6c symbol=FUN_00105e28 lang=c99 */
/* Clone of src/eboot/FUN_001004f4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Display-list command words: opcode in the top byte, y << 10 | x in the rest. */
#define GE_SCISSOR1 0xd4000000U
#define GE_SCISSOR2 0xd5000000U
#define CLIP_FLAGS 0x600  /* either bit means a clip rectangle applies */
#define FULL_SCISSOR2 (GE_SCISSOR2 | (0x110 << 10) | 0x1e0) /* 480 x 272 screen */

typedef struct ClipSource {
  char pad00[0xe];
  u16 flags;                /* 0xe */
} ClipSource;

extern void FUN_00051e18();

/* Emits a full-screen scissor when the source asks for clipping. */
void FUN_00105e28(u32 list,ClipSource *src)
{
  if ((src->flags & CLIP_FLAGS) != 0) {
    FUN_00051e18(list,GE_SCISSOR1);
    FUN_00051e18(list,FULL_SCISSOR2);
  }
}
