/* HSTMATCH module=EBOOT.BIN start=0x001bebb0 end=0x001bec74 symbol=FUN_001bebb0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Rec { char pad[0x60]; char state; } Rec;
typedef struct Pair { unsigned char a; unsigned char b; } Pair;
typedef struct Obj { char pad[0x34c]; Pair ent[640]; } Obj;

extern int DAT_00338b08;
extern Rec *FUN_000d8c24(int, int, u32);
extern void FUN_001bf884(Obj *, int, u8);

void FUN_001bebb0(Obj *param_1, int param_2)
{
  int i;
  for (i = 0; i < 640; i++) {
    Pair *e = &param_1->ent[i];
    Rec *r = FUN_000d8c24(DAT_00338b08, 5, i);
    e->a = 0;
    e->b = 0;
    if (r != 0 && r->state >= 0) {
      if (param_2 != 0) {
        FUN_001bf884(param_1, i, 4);
      } else {
        if (r->state == 1) {
          FUN_001bf884(param_1, i, 4);
        }
      }
    }
  }
}
