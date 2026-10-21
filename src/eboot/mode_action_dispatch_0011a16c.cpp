/* HSTMATCH module=EBOOT.BIN start=0x0011a16c end=0x0011a2ac symbol=FUN_0011a16c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: the guard chain is an early return (if (a != 0 || b != 0 || ... || f() != 0) return;) followed by the switch; the nested-if form lays the call result test out as bnez/nop instead of retail's beqzl + b END. */
struct Player {
  char pad[0x4d8];
  unsigned char f4d8;
  char pad4d9[0xf];
  int f4e8;
};
struct Slots {
  char pad[0x70];
  Player *player[1];
};
struct Game {
  char pad[0x5d];
  unsigned char f5d;
  unsigned char f5e;
  unsigned char f5f;
  char pad60[0x24];
  unsigned char f84;
};
extern "C" {
extern Slots *DAT_003386b0;
extern Game *DAT_00338b44;
int FUN_000dbc04();
void FUN_0011a2ac(float, void *, int, int);
void FUN_0011b468(void *);

void FUN_0011a16c(void *self, int unused, int idx)
{
  int mode = DAT_003386b0->player[idx]->f4e8;
  if (DAT_00338b44->f5d != 0 || DAT_00338b44->f84 != 0 || DAT_00338b44->f5e != 0 ||
      DAT_00338b44->f5f != 0 || FUN_000dbc04() != 0) {
    return;
  }
  switch (mode) {
    case 4:
      FUN_0011a2ac(155.0f, self, 8, 30);
      FUN_0011b468(self);
      break;
    case 5:
      FUN_0011a2ac(155.0f, self, 9, 30);
      FUN_0011b468(self);
      break;
    default:
      if (DAT_003386b0->player[idx]->f4d8 != 0) {
        FUN_0011a2ac(155.0f, self, 10, 30);
        FUN_0011b468(self);
      }
      break;
    }
}
}
