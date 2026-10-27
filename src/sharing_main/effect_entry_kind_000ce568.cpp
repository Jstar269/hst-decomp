/* HSTMATCH module=hstp_trans_main.prx start=0x000ce568 end=0x000ce7dc symbol=FUN_000ce568 lang=c++ rodata=0x002d0630 */
/* Hand-written reconstruction from the disassembly (Effect.cpp debug build: asserts at lines 1531 and 1586 through the empty variadic stub FUN_000cb244; jump-table bodies written in retail address order); exact match verified; names and types await human review. */
extern "C" void FUN_000cb244(...);
extern char DAT_0037c690[];
extern char DAT_0037cd88[];
extern char DAT_0037c6c8[];

#define HST_ASSERT(cond, text, line) do { if (!(cond)) { FUN_000cb244(DAT_0037c690, text, DAT_0037c6c8, line); for (;;) {} } } while (0)

struct Player {
  char pad0[0x3c];
  int state;
  char pad40[0x4d8 - 0x40];
  unsigned char flag;
  char pad4d9[0x4e4 - 0x4d9];
  int mode;
  int kind;
};
struct Game {
  char pad0[0x70];
  Player *players[4];
};
extern "C" Game *DAT_003e19f0;

struct Entry {
  int mode;
  int kind;
  int a;
  int b;
};
struct Effect {
  char pad0[0x84];
  Entry e[4];
};

extern "C" void FUN_000ce568(Effect *self, int idx)
{
  Player *p = DAT_003e19f0->players[idx];
  if (p != 0) {
    if (p->state == 3) {
      self->e[idx].mode = 0;
      self->e[idx].kind = 1;
    } else {
      self->e[idx].mode = p->mode;
      self->e[idx].kind = p->kind;
    }
    switch (self->e[idx].kind) {
    case 0:
      switch (self->e[idx].mode) {
      case 0:
        if (p->flag != 0) {
          self->e[idx].a = 6;
          self->e[idx].b = 16;
        } else {
          self->e[idx].a = 8;
          self->e[idx].b = 18;
        }
        break;
      case 1:
        self->e[idx].a = 1;
        self->e[idx].b = 11;
        break;
      case 2:
        self->e[idx].a = 2;
        self->e[idx].b = 12;
        break;
      default:
        HST_ASSERT(false, DAT_0037cd88, 1531);
      }
      break;
    case 1:
      self->e[idx].a = 5;
      self->e[idx].b = 15;
      break;
    case 7:
      self->e[idx].a = 3;
      self->e[idx].b = 13;
      break;
    case 8:
    case 9:
    case 10:
      self->e[idx].a = 7;
      if (self->e[idx].mode == 0) {
        self->e[idx].b = 17;
      } else {
        self->e[idx].b = 45;
      }
      break;
    case 2:
      self->e[idx].a = 4;
      self->e[idx].b = 14;
      break;
    case 3:
      self->e[idx].a = 0;
      self->e[idx].b = 10;
      break;
    case 4:
      self->e[idx].a = 9;
      self->e[idx].b = 19;
      break;
    case 5:
      self->e[idx].a = 9;
      self->e[idx].b = 46;
      break;
    case 6:
      self->e[idx].a = 1;
      self->e[idx].b = 47;
      break;
    case 11:
      self->e[idx].a = 3;
      self->e[idx].b = 13;
      break;
    case 12:
      self->e[idx].a = 3;
      self->e[idx].b = 48;
      break;
    default:
      HST_ASSERT(false, DAT_0037cd88, 1586);
    }
  }
}
