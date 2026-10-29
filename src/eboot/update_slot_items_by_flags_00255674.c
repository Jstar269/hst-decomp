/* HSTMATCH module=EBOOT.BIN start=0x00255674 end=0x00255824 symbol=FUN_00255674 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a/v2) corrected by hand: typed Obj/Item/Sub structs and float-argument prototypes, the duplicated else arms merged, flags as ints with `(x != 0) ^ 1` (matching idiom) and fire declared before active (register colours); exact match verified; names and types await human review. */
/* Effect object: two float fields are written. */
typedef struct Sub {
  char pad[0xc4];
  float unkc4;
  char padc8[8];
  float unkd0;
} Sub;
/* Item with a pointer to its Sub at 0x64. */
typedef struct Item {
  char pad[0x64];
  Sub *unk64;
} Item;
/* Owner with per-slot flag arrays indexed by slot (count slots). */
typedef struct Obj {
  char pad0[4];
  unsigned char unk4[4];
  int unk8[21];
  unsigned char unk5c[0x94];
  unsigned char unkf0[8];
  int count;
  char pad1[0x1dc - 0xfc];
  int unk1dc[8];
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

/* For each slot whose flags pass the test (unkf0 clear, unk4 set, unk1dc zero) and that has an item, resets the item's Sub state. */
void FUN_00255674(Obj *self, int selected)
{
  int i;
  int fire;
  int active;
  Sub *sub;

  i = 0;
  if (0 < self->count) {
    do {
      fire = 0;
      active = 0;
      if (((self->unkf0[i] != 0) ^ 1) && self->unk4[i] != 0) {
        active = 1;
      }
      if (active && self->unk1dc[i] == 0) {
        fire = 1;
      }
      if (fire) {
        if (DAT_0034b340[i] != 0 && DAT_00338ac4 != 0) {
          if (i == selected) {
            if (self->unk5c[i] == 0) {
              FUN_001b2bb8(&DAT_0034179c, self->unk8[i] + 0x41);
            }
          }
          FUN_00092078(DAT_0034b340[i], 1, 0, 0, -1.0f);
          sub = DAT_0034b340[i]->unk64;
          if (sub != 0) {
            FUN_00057b58(sub, 0, 1, 0.0f);
            FUN_00058ddc(sub, 0, -1);
            FUN_00058ec4(sub, -1, 1.0f);
            sub->unkc4 = 1.0f;
            FUN_00058f38(sub, -1, -1.0f);
            FUN_0005f110(sub, -1.0f);
            FUN_00059084(sub, -1);
            sub->unkd0 = sub->unkc4;
          }
        }
      }
      i++;
    } while (i < self->count);
  }
}
