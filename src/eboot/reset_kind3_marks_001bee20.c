/* HSTMATCH module=EBOOT.BIN start=0x001bee20 end=0x001bef18 symbol=FUN_001bee20 lang=c99 */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/reset_kind3_marks_001ccb74.c); exact match verified; names and types await human review. */
typedef struct Rec { char pad[0x60]; char state; } Rec;
typedef struct Obj { char pad[0xd4c]; unsigned char mark[640]; } Obj;

extern int DAT_00338b08;
extern Rec *FUN_000d8c24(int, int, int);
extern int FUN_001bb944(Obj *, int, int);
extern void FUN_001bf9b8(Obj *, int, int);

void FUN_001bee20(Obj *param_1, int param_2)
{
  int i;
  for (i = 0; i < 640; i++) {
    Rec *r = FUN_000d8c24(DAT_00338b08, 3, i);
    param_1->mark[i] = 0;
    if (r != 0 && r->state >= 0) {
      if (param_2 != 0) {
        FUN_001bf9b8(param_1, i, 5);
      } else if (i == 0) {
        FUN_001bf9b8(param_1, i, 5);
      } else if (r->state == 1) {
        FUN_001bf9b8(param_1, i, 5);
      } else if (FUN_001bb944(param_1, 3, i) != 0) {
        FUN_001bf9b8(param_1, i, 5);
      }
    }
  }
}
