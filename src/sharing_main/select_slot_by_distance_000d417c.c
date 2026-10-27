/* HSTMATCH module=hstp_trans_main.prx start=0x000d417c end=0x000d45a4 symbol=FUN_000d417c lang=c99 */
/* Hand-written reconstruction (port of src/eboot/select_slot_by_distance_000d0580.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Matching idioms: the whole selection is one if / else-if ladder (early returns leave dead copies of the delay-slot
   instructions); the tracker limit is the left operand (`tracker->f58 > F(tracker)`) so it is loaded before the call;
   the in-range test `d <= 376.36f && d >= 225.0f` has two identical arms, as in retail. */
typedef struct Vec4 { float x, y, z, w; } Vec4;

typedef struct Target {
  char pad[0x20];
  Vec4 v;
} Target;

typedef struct Tracker {
  char pad[0x58];
  int f58;
} Tracker;

typedef struct Game {
  char pad[0x3c];
  int mode;
  char pad2[0x88 - 0x40];
  Target *target;
  char pad3[0x9c - 0x8c];
  Tracker *tracker;
} Game;

typedef struct Flags {
  char pad[0x5e];
  unsigned char f5e;
  unsigned char f5f;
  char pad2[0x84 - 0x60];
  unsigned char f84;
} Flags;

typedef struct Cfg {
  char pad[0x1364];
  int idx;
} Cfg;

typedef struct Self {
  char pad[0x3c];
  int cur;
  int tab[22];
} Self;

extern Game *DAT_003e19f0;
extern unsigned char DAT_003e1e44;
extern Flags *DAT_003e1e84;
extern Cfg *DAT_003e95e0;
extern float FUN_00022500(Vec4 *, Vec4 *);
extern int FUN_000ce044(void);
extern int FUN_00123394(Tracker *);

void FUN_000d417c(Self *self)
{
  Game *g = DAT_003e19f0;
  Target *t = g->target;
  float d;
  int idx;

  if (g->mode == 7) {
    Vec4 v;
    v.x = t->v.x;
    v.y = t->v.y;
    v.z = t->v.z;
    v.w = t->v.w;
    d = FUN_00022500(&v, &v);
    if (DAT_003e1e44 != 0 && DAT_003e19f0->tracker->f58 > FUN_00123394(DAT_003e19f0->tracker) &&
        DAT_003e1e84->f84 == 0 && DAT_003e1e84->f5e == 0 && DAT_003e1e84->f5f == 0) {
      self->cur = self->tab[14];
    } else if (d >= 376.36f && DAT_003e19f0->tracker->f58 > FUN_00123394(DAT_003e19f0->tracker) &&
               DAT_003e1e84->f84 == 0 && DAT_003e1e84->f5e == 0 && DAT_003e1e84->f5f == 0) {
      if (FUN_000ce044() == 2) {
        idx = DAT_003e95e0->idx;
        if (idx == 9) {
          self->cur = self->tab[12];
        } else if (idx == 5) {
          self->cur = self->tab[15];
        } else if (idx == 13) {
          self->cur = self->tab[16];
        } else if (idx == 15) {
          self->cur = self->tab[17];
        } else {
          self->cur = self->tab[1];
        }
      } else if (FUN_000ce044() == 1) {
        idx = DAT_003e95e0->idx;
        if (idx == 2) {
          self->cur = self->tab[6];
        } else if (idx == 4) {
          self->cur = self->tab[7];
        } else if (idx == 7) {
          self->cur = self->tab[8];
        } else if (idx == 16) {
          self->cur = self->tab[9];
        } else if (idx == 17) {
          self->cur = self->tab[10];
        } else if (idx == 20) {
          self->cur = self->tab[11];
        }
      } else if (FUN_000ce044() == 0) {
        idx = DAT_003e95e0->idx;
        if (idx == 1) {
          self->cur = self->tab[5];
        } else if (idx == 6) {
          self->cur = self->tab[18];
        } else if (idx == 8) {
          self->cur = self->tab[19];
        } else if (idx == 14) {
          self->cur = self->tab[20];
        } else if (idx == 18) {
          self->cur = self->tab[21];
        }
      }
    } else if (d <= 225.0f) {
      self->cur = 0;
    } else if (DAT_003e19f0->tracker->f58 > FUN_00123394(DAT_003e19f0->tracker) &&
               (DAT_003e1e84->f84 != 0 || DAT_003e1e84->f5e != 0 || DAT_003e1e84->f5f != 0)) {
      self->cur = self->tab[13];
    } else if (d <= 376.36f && d >= 225.0f) {
      idx = FUN_000ce044() == 0 ? 4 : 3;
      self->cur = self->tab[idx];
    } else {
      idx = FUN_000ce044() == 0 ? 4 : 3;
      self->cur = self->tab[idx];
    }
  } else {
    Vec4 v;
    v.x = t->v.x;
    v.y = t->v.y;
    v.z = t->v.z;
    v.w = t->v.w;
    d = FUN_00022500(&v, &v);
    if (d <= 225.0f) {
      self->cur = 0;
    } else {
      self->cur = self->tab[0];
    }
  }
}
