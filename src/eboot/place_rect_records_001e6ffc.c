/* HSTMATCH module=EBOOT.BIN start=0x001e6ffc end=0x001e70e0 symbol=FUN_001e6ffc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: the nested if/else is a switch (cases 1-3 share a body), the five-argument calls are over a typed array of four 0x8c-byte records; exact match verified; names and types await human review. */
typedef struct Rec {
  char pad0[8];
  short x;
  short y;
  char pad1[0x8c - 12];
} Rec;
typedef struct Obj {
  char pad[0x1b34];
  Rec r[4];
} Obj;

extern void FUN_002177d4(Rec *, int, int, int, int, int);

void FUN_001e6ffc(Obj *o, int m)
{
  switch (m) {
  case 1:
  case 2:
  case 3:
    FUN_002177d4(&o->r[0], o->r[0].x + 0x15e, o->r[0].y, o->r[0].x, o->r[0].y, 5);
    FUN_002177d4(&o->r[3], o->r[3].x + 0x15e, o->r[3].y, o->r[3].x, o->r[3].y, 5);
    break;
  case 5:
    FUN_002177d4(&o->r[1], o->r[1].x + 0x15e, o->r[1].y, o->r[1].x, o->r[1].y, 5);
    FUN_002177d4(&o->r[2], o->r[2].x + 0x15e, o->r[2].y, o->r[2].x, o->r[2].y, 5);
    break;
  default:
    FUN_002177d4(&o->r[0], o->r[0].x + 0x15e, o->r[0].y, o->r[0].x, o->r[0].y, 5);
    break;
  }
}
