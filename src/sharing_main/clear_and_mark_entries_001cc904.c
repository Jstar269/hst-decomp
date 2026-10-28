/* HSTMATCH module=hstp_trans_main.prx start=0x001cc904 end=0x001cc9c8 symbol=FUN_001cc904 lang=c99 */
/* Clone of src/eboot/clear_and_mark_entries_001bebb0.c (hstclone.py tag c034907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Rec { char pad[0x60]; char state; } Rec;
typedef struct Pair { unsigned char a; unsigned char b; } Pair;
typedef struct Obj { char pad[0x34c]; Pair ent[640]; } Obj;

extern int DAT_003e1e48;
extern Rec *FUN_000dca74(int, int, u32);
extern void FUN_001cd610(Obj *, int, u8);

void FUN_001cc904(Obj *param_1, int param_2)
{
  int i;
  for (i = 0; i < 640; i++) {
    Pair *e = &param_1->ent[i];
    Rec *r = FUN_000dca74(DAT_003e1e48, 5, i);
    e->a = 0;
    e->b = 0;
    if (r != 0 && r->state >= 0) {
      if (param_2 != 0) {
        FUN_001cd610(param_1, i, 4);
      } else {
        if (r->state == 1) {
          FUN_001cd610(param_1, i, 4);
        }
      }
    }
  }
}
