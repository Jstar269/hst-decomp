/* HSTMATCH module=EBOOT.BIN start=0x00255674 end=0x00255824 symbol=FUN_00255674 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a/v2) corrected by hand: typed Obj/Item/Sub structs and float-argument prototypes, the duplicated else arms merged, flags as ints with `(x != 0) ^ 1` (matching idiom) and bVar3 declared before bVar1 (register colours); exact match verified; names and types await human review. */
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

extern Item *DAT_0034b340[];
extern int DAT_00338ac4;
extern int DAT_0034179c;
extern unsigned char FUN_00057b58(Sub *, int, int, float);
extern void FUN_00058ddc(Sub *, int, int);
extern void FUN_00058ec4(Sub *, int, float);
extern void FUN_00058f38(Sub *, int, float);
extern void FUN_00059084(Sub *, int);
extern void FUN_0005f110(Sub *, float);
extern void FUN_00092078(Item *, int, int, int, float);
extern void FUN_001b2bb8(int *, int);

void FUN_00255674(Obj *param_1, int param_2)
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
        if (DAT_0034b340[i] != 0 && DAT_00338ac4 != 0) {
          if (i == param_2) {
            if (param_1->f5c[i] == 0) {
              FUN_001b2bb8(&DAT_0034179c, param_1->f8[i] + 0x41);
            }
          }
          FUN_00092078(DAT_0034b340[i], 1, 0, 0, -1.0f);
          sub = DAT_0034b340[i]->f64;
          if (sub != 0) {
            FUN_00057b58(sub, 0, 1, 0.0f);
            FUN_00058ddc(sub, 0, -1);
            FUN_00058ec4(sub, -1, 1.0f);
            sub->fc4 = 1.0f;
            FUN_00058f38(sub, -1, -1.0f);
            FUN_0005f110(sub, -1.0f);
            FUN_00059084(sub, -1);
            sub->fd0 = sub->fc4;
          }
        }
      }
      i++;
    } while (i < param_1->count);
  }
}
