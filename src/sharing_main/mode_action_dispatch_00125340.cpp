/* HSTMATCH module=hstp_trans_main.prx start=0x00125340 end=0x00125480 symbol=FUN_00125340 lang=c++ */
/* Clone of src/eboot/mode_action_dispatch_0011a16c.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
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
extern Slots *DAT_003e19f0;
extern Game *DAT_003e1e84;
int FUN_000dfc24();
void FUN_00125480(float, void *, int, int);
void FUN_0012663c(void *);

void FUN_00125340(void *self, int unused, int idx)
{
  int mode = DAT_003e19f0->player[idx]->f4e8;
  if (DAT_003e1e84->f5d != 0 || DAT_003e1e84->f84 != 0 || DAT_003e1e84->f5e != 0 ||
      DAT_003e1e84->f5f != 0 || FUN_000dfc24() != 0) {
    return;
  }
  switch (mode) {
    case 4:
      FUN_00125480(155.0f, self, 8, 30);
      FUN_0012663c(self);
      break;
    case 5:
      FUN_00125480(155.0f, self, 9, 30);
      FUN_0012663c(self);
      break;
    default:
      if (DAT_003e19f0->player[idx]->f4d8 != 0) {
        FUN_00125480(155.0f, self, 10, 30);
        FUN_0012663c(self);
      }
      break;
    }
}
}
