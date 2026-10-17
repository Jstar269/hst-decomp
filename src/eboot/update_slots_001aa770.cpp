/* HSTMATCH module=EBOOT.BIN start=0x001aa770 end=0x001aa850 symbol=FUN_001aa770 lang=c++ */
/* Clone of src/sharing_main/update_slots_001b7d3c.cpp (hstclone.py tag u5fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Node {
  char pad[0x24];
  int f24;
  int f28;
} Node;

struct Vec2 {
  int x;
  int y;
  int GetX() const { return x; }
  int GetY() const { return y; }
};

typedef struct Owner {
  char pad[0x250];
  Node *p250;
  char pad1[0x10];
  Node *p264;
  char pad2[0x10];
  Node *p278;
} Owner;

extern "C" {
void FUN_000ffb3c(Node *, int);
int FUN_0019d474(void);
void FUN_001aa770(Owner *param_1);
}

void FUN_001aa770(Owner *param_1)
{
  Node **p250;
  Vec2 *pos;
  Node **p264;
  Node **p278;

  FUN_0019d474();
  pos = (Vec2 *)(FUN_0019d474() + 0x318);
  p250 = &param_1->p250;
  p264 = &param_1->p264;
  p278 = &param_1->p278;

  if (pos->x == 0 && pos->y == 0) {
    FUN_000ffb3c(*p250, 1);
    FUN_000ffb3c(*p264, 1);
    FUN_000ffb3c(*p278, 1);
    return;
  }

  FUN_000ffb3c(*p250, 0);
  (*p250)->f24 = (*p250)->f28 + pos->GetX();
  FUN_000ffb3c(*p264, 0);
  (*p264)->f24 = (*p264)->f28 + pos->GetY();
  FUN_000ffb3c(*p278, 0);
}
