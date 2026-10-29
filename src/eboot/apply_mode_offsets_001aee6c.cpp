/* HSTMATCH module=EBOOT.BIN start=0x001aee6c end=0x001aef94 symbol=FUN_001aee6c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: both mode tests are switches (case 0/case 4 sharing a body, default else/return), typed structs with the info sub-object addressed through a pointer, shared pointer loads; readability pass; exact match verified; names and types await human review. */
enum { MODE_OFFSET = 0x3f };   /* amount subtracted from the two shorts (63.0f is set as the float value) */

struct Target { char pad[0x60]; float value; };
struct Pair { char pad[0x24]; int a; int b; };
struct Info { Pair *pair; int val; };
struct Shorts { char pad[4]; short s4; char pad2[2]; short s8; };
struct PartA {
  char pad0[0x1c];
  Target *target;
  char pad1[0x28c - 0x20];
  Info info;
  char pad2[0x3b8 - 0x294];
  Shorts *shorts;
};
struct PartB {
  char pad0[0x1c];
  Target *target1;
  char pad1[0x28 - 0x20];
  Target *target2;
};
struct Self { int pad; PartA *part_a; PartB *part_b; };
struct GameState {
  char pad0[0x11c];
  unsigned char mode;
  char pad1[0x34c - 0x11d];
  int unk34c;
};
extern "C" GameState *FUN_0019d474();
extern "C" void FUN_00102c54(Target *);

/* Apply the per-mode adjustments: modes 0 and 4 use the stored value as is, other modes use it plus one;
   a state of 2 sets the target value and lowers the shorts; modes 0 and 4 nudge the two part-B targets by +6 / -6. */
extern "C" void FUN_001aee6c(Self *self)
{
  PartA *a = self->part_a;
  unsigned char mode = FUN_0019d474()->mode;
  Info *info = &a->info;
  switch (mode) {
  case 0:
  case 4: {
    int n = info->val;
    Pair *pair = info->pair;
    pair->a = n;
    pair->b = n;
    break;
  }
  default: {
    int n = info->val + 1;
    Pair *pair = info->pair;
    pair->a = n;
    pair->b = n;
  }
  }
  if (FUN_0019d474()->unk34c == 2) {
    a->target->value = 63.0f;
    FUN_00102c54(a->target);
    Shorts *shorts = a->shorts;
    shorts->s4 = shorts->s4 - MODE_OFFSET;
    shorts->s8 = shorts->s8 - MODE_OFFSET;
  }
  PartB *b = self->part_b;
  switch (FUN_0019d474()->mode) {
  case 0:
  case 4:
    break;
  default:
    return;
  }
  b->target1->value = b->target1->value + 6.0f;
  FUN_00102c54(b->target1);
  b->target2->value = b->target2->value - 6.0f;
  FUN_00102c54(b->target2);
}
