/* HSTMATCH module=hstp_trans_main.prx start=0x00265b24 end=0x00265cd4 symbol=FUN_00265b24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a/v2, via the EBOOT twin src/eboot/update_slot_items_by_flags_00255674.c) corrected by hand: typed Obj/Item/Sub structs and float-argument prototypes, the duplicated else arms merged, flags as ints with `(x != 0) ^ 1` (matching idiom) and bVar3 declared before bVar1 (register colours), Sharing globals and callees substituted from the twin; exact match verified; names and types await human review. */
/* Twin of EBOOT 0x255674. Names provisional. */
typedef struct Sub {
  char pad[0xc4];
  float fc4;
  char padc8[8];
  float fd0;
} Sub;
typedef struct Item {
  char pad[0x64];
  Sub *f64;
} Item;
typedef struct Obj {
  char pad0[4];
  unsigned char f4[4];
  int f8[21];
  unsigned char f5c[0x94];
  unsigned char ff0[8];
  int count;
  char pad1[0x1dc - 0xfc];
  int f1dc[8];
} Obj;

extern Item *DAT_003f468c[];
extern int DAT_003e1e04;
extern int DAT_003eaad8;
extern unsigned char FUN_000587ac(Sub *, int, int, float);
extern void FUN_00059ac0(Sub *, int, int);
extern void FUN_00059ba8(Sub *, int, float);
extern void FUN_00059c1c(Sub *, int, float);
extern void FUN_00059d68(Sub *, int);
extern void FUN_0005ff00(Sub *, float);
extern void FUN_00093d10(Item *, int, int, int, float);
extern void FUN_001c0ce8(int *, int);

void FUN_00265b24(Obj *param_1, int param_2)
{
  int i;
  int bVar3;
  int bVar1;
  Sub *sub;

  i = 0;
  if (0 < param_1->count) {
    do {
      bVar3 = 0;
      bVar1 = 0;
      if (((param_1->ff0[i] != 0) ^ 1) && param_1->f4[i] != 0) {
        bVar1 = 1;
      }
      if (bVar1 && param_1->f1dc[i] == 0) {
        bVar3 = 1;
      }
      if (bVar3) {
        if (DAT_003f468c[i] != 0 && DAT_003e1e04 != 0) {
          if (i == param_2) {
            if (param_1->f5c[i] == 0) {
              FUN_001c0ce8(&DAT_003eaad8, param_1->f8[i] + 0x41);
            }
          }
          FUN_00093d10(DAT_003f468c[i], 1, 0, 0, -1.0f);
          sub = DAT_003f468c[i]->f64;
          if (sub != 0) {
            FUN_000587ac(sub, 0, 1, 0.0f);
            FUN_00059ac0(sub, 0, -1);
            FUN_00059ba8(sub, -1, 1.0f);
            sub->fc4 = 1.0f;
            FUN_00059c1c(sub, -1, -1.0f);
            FUN_0005ff00(sub, -1.0f);
            FUN_00059d68(sub, -1);
            sub->fd0 = sub->fc4;
          }
        }
      }
      i++;
    } while (i < param_1->count);
  }
}
