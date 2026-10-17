/* HSTMATCH module=hstp_trans_main.prx start=0x001b7d3c end=0x001b7e1c symbol=FUN_001b7d3c lang=c++ */
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
void FUN_00105470(Node *, int);
int FUN_001aa91c(void);
void FUN_001b7d3c(Owner *param_1);
}

void FUN_001b7d3c(Owner *param_1)
{
  Node **p250;
  Vec2 *pos;
  Node **p264;
  Node **p278;

  FUN_001aa91c();
  pos = (Vec2 *)(FUN_001aa91c() + 0x318);
  p250 = &param_1->p250;
  p264 = &param_1->p264;
  p278 = &param_1->p278;

  if (pos->x == 0 && pos->y == 0) {
    FUN_00105470(*p250, 1);
    FUN_00105470(*p264, 1);
    FUN_00105470(*p278, 1);
    return;
  }

  FUN_00105470(*p250, 0);
  (*p250)->f24 = (*p250)->f28 + pos->GetX();
  FUN_00105470(*p264, 0);
  (*p264)->f24 = (*p264)->f28 + pos->GetY();
  FUN_00105470(*p278, 0);
}
