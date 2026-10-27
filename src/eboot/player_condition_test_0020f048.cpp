/* HSTMATCH module=EBOOT.BIN start=0x0020f048 end=0x0020f540 symbol=FUN_0020f048 lang=c++ rodata=0x002c948c */
/* Hand-written reconstruction from the disassembly (written together with the exact Sharing twin src/sharing_main/player_condition_test_0021dbd8.cpp, EBOOT addresses); exact match verified; names and types await human review. */
/* Condition test by code (12..55, jump table at 0x2c948c; out-of-range codes count as true): player flags,
   the opponent's and the player's z position against -6.4008, the 0xa75a8 / 0xa8494 predicates, the ball state,
   the player's timer against DAT_00341314, and two checks on the ball's hit records (Track layout as in
   find_nearest_entry_000a7aa0.cpp; the clamped EntryList::operator[] and the Track reference bound inside the if
   give retail's unfolded `addiu v0,s0,620; lw v0,12(v0)` element reads). */
struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));

struct Entry {
  int id;
  unsigned char active;
  int f8;
  Vec4 pos;
};

struct EntryList {
  Entry *data;
  unsigned int size;
  unsigned int cap;
  Entry &operator[](unsigned int i)
  {
    if (i >= size)
      i = size - 1;
    return data[i];
  }
};

struct Track {
  EntryList pending;
  EntryList done;
};

struct Ball {
  char pad0[0x230];
  unsigned int m230;
  int pad234;
  int m238;
  int m23c;
  char pad240[0x26c - 0x240];
  Track track;
};

struct Player {
  char pad0[0x144];
  unsigned int side;
  char pad148[0x41c - 0x148];
  int timer;
  char pad420[0x4e8 - 0x420];
  int m4e8;
  char pad4ec[0x580 - 0x4ec];
  Vec4 pos;
  char pad590[0x5a8 - 0x590];
  float m5a8;
  char pad5ac[0x888 - 0x5ac];
  float m888;
  char pad88c[0x8a1 - 0x88c];
  unsigned char m8a1;
  unsigned char m8a2;
  unsigned char m8a3;
  unsigned char m8a4;
};

struct Game {
  char pad0[0x70];
  Player *players[6];
  Ball *ball;
};

extern "C" {
extern Game *DAT_003386b0;
extern float DAT_00341314;
float fabsf(float);
bool FUN_000a75a8(Player *, Ball *);
int FUN_000a8494(Player *, const Vec4 *);
}

extern "C" unsigned char FUN_0020f048(Player *self, int code)
{
  unsigned char r;
  Ball *ball;
  Player *opp;
  opp = DAT_003386b0->players[self->side ^ 1];
  ball = DAT_003386b0->ball;
  r = 0;
  bool hit = FUN_000a75a8(self, ball);
  switch (code) {
  default:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x2a:
    r = 1;
    break;
  case 0xc:
    r = opp->m4e8 == 0xb;
    break;
  case 0xd:
    r = self->m8a1;
    break;
  case 0xe:
    r = self->m8a2;
    break;
  case 0xf:
    r = self->m8a3;
    break;
  case 0x10:
    r = self->m8a4;
    break;
  case 0x11:
  case 0x32:
  case 0x33:
    r = opp->pos.z >= -6.4007998f;
    break;
  case 0x12:
    r = opp->pos.z >= -6.4007998f && self->pos.z >= -6.4007998f;
    break;
  case 0x17:
    r = hit;
    break;
  case 0x18:
    r = hit;
    break;
  case 0x19:
    r = hit;
    break;
  case 0x1a:
    r = !hit;
    break;
  case 0x1b:
    r = !hit;
    break;
  case 0x1c:
    r = !hit;
    break;
  case 0x1d:
    r = ball->m238 == 0;
    break;
  case 0x1e:
    r = ball->m238 == 0;
    break;
  case 0x1f:
    r = ball->m238 == 0;
    break;
  case 0x20:
    r = ball->m238 == 1;
    break;
  case 0x21:
    r = ball->m238 == 1;
    break;
  case 0x22:
    r = ball->m238 == 1;
    break;
  case 0x23:
    r = ball->m238 == 2;
    break;
  case 0x24:
    r = ball->m238 == 2;
    break;
  case 0x25:
    r = ball->m238 == 2;
    break;
  case 0x26:
    r = FUN_000a8494(self, &self->pos);
    break;
  case 0x27:
    r = FUN_000a8494(self, &self->pos);
    break;
  case 0x28:
    r = !FUN_000a8494(self, &self->pos);
    break;
  case 0x29:
    r = !FUN_000a8494(self, &self->pos);
    break;
  case 0x2b:
    r = (float)self->timer / DAT_00341314 > 0.5f;
    break;
  case 0x2c:
    r = (float)self->timer / DAT_00341314 > 0.5f;
    break;
  case 0x2d:
    r = (float)self->timer / DAT_00341314 > 0.5f;
    break;
  case 0x2e:
    r = (float)self->timer / DAT_00341314 >= 1.0f;
    break;
  case 0x2f:
    r = (float)self->timer / DAT_00341314 >= 1.0f;
    break;
  case 0x30:
    r = (float)self->timer / DAT_00341314 >= 1.0f;
    break;
  case 0x31:
    break;
  case 0x34:
  case 0x35:
  case 0x36:
    if ((self->side ^ 1) == ball->m230 && ball->m23c == 6 && (int)ball->track.done.size > 0) {
      Track &t = ball->track;
      if (self->m5a8 * t.done[0].pos.z > self->m888)
        r = 1;
    }
    break;
  case 0x37:
    if ((self->side ^ 1) == ball->m230 && (int)ball->track.pending.size > 0) {
      Track &t = ball->track;
      if (fabsf(t.pending[0].pos.z) > 6.4007998f && fabsf(opp->pos.z) < 6.4007998f &&
          fabsf(self->m888) < 6.4007998f)
        r = 1;
    }
    break;
  }
  return r;
}
