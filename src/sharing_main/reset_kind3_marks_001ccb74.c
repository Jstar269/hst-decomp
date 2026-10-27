/* HSTMATCH module=hstp_trans_main.prx start=0x001ccb74 end=0x001ccc6c symbol=FUN_001ccb74 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Rec { char pad[0x60]; char state; } Rec;
typedef struct Obj { char pad[0xd4c]; unsigned char mark[640]; } Obj;

extern int DAT_003e1e48;
extern Rec *FUN_000dca74(int, int, int);
extern int FUN_001c972c(Obj *, int, int);
extern void FUN_001cd7f8(Obj *, int, int);

void FUN_001ccb74(Obj *param_1, int param_2)
{
  int i;
  for (i = 0; i < 640; i++) {
    Rec *r = FUN_000dca74(DAT_003e1e48, 3, i);
    param_1->mark[i] = 0;
    if (r != 0 && r->state >= 0) {
      if (param_2 != 0) {
        FUN_001cd7f8(param_1, i, 5);
      } else if (i == 0) {
        FUN_001cd7f8(param_1, i, 5);
      } else if (r->state == 1) {
        FUN_001cd7f8(param_1, i, 5);
      } else if (FUN_001c972c(param_1, 3, i) != 0) {
        FUN_001cd7f8(param_1, i, 5);
      }
    }
  }
}
