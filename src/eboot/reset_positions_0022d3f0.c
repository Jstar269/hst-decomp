/* HSTMATCH module=EBOOT.BIN start=0x0022d3f0 end=0x0022d49c symbol=FUN_0022d3f0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified (the two position globals are extern const, so retail's loads schedule above the frame save and the first store); names and types await human review. */
extern float DAT_002f34a8;
extern const float DAT_0034a354;
extern const float DAT_0034a358;
extern void FUN_00103480();

typedef struct Pos {
  char pad0[0x60];
  float x;
  float y;
} Pos;

typedef struct Rect {
  char pad0[0x11c];
  short x;
  short y;
} Rect;

typedef struct Obj {
  char pad0[0x54];
  unsigned char f54;
  char pad1[0xbc - 0x55];
  Pos *pbc;
  Pos *pc0;
  char pad2[0x210 - 0xc4];
  Rect *p210;
} Obj;

void FUN_0022d3f0(Obj *o, unsigned char flag)
{
  float fx = DAT_0034a354;
  o->f54 = flag;
  o->pc0->x = fx;
  float fy = DAT_0034a358;
  o->pc0->y = fy;
  if (o->f54 != 0) {
    float fz = DAT_002f34a8;
    Rect *r = o->p210;
    r->x = 0;
    r->y = (short)(int)fz;
    o->pbc->x = fx;
    o->pbc->y = fy + fz;
    FUN_00103480(o);
  } else {
    Rect *r = o->p210;
    r->x = -50;
    r->y = 0;
    o->pbc->x = fx - 50.0f;
    o->pbc->y = fy;
    FUN_00103480(o);
  }
}

// Ruled out (head only): all 15 orders of {fx=,fy=,flag store,pc0->x=,pc0->y=} (best 5 words, this one: fx, flag, x-store, fy, y-store); locals read inline (reloads the globals, 51 words); p=o->pc0 local for the first store; inline SetX/SetY members; Ghidra raw pointer form; switch/ternary variants.
