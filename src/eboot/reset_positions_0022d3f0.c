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

typedef struct PaneObj {
  char pad0[0x54];
  unsigned char shifted;   /* 0x54 */
  char pad1[0xbc - 0x55];
  Pos *posbc;              /* 0xbc */
  Pos *posc0;              /* 0xc0 */
  char pad2[0x210 - 0xc4];
  Rect *rect210;           /* 0x210 */
} PaneObj;

/* Places the pane positions for the shifted (flag set) or unshifted layout. */
void FUN_0022d3f0(PaneObj *o, unsigned char shifted)
{
  float fx = DAT_0034a354;
  o->shifted = shifted;
  o->posc0->x = fx;
  float fy = DAT_0034a358;
  o->posc0->y = fy;
  if (o->shifted != 0) {
    float fz = DAT_002f34a8;
    Rect *r = o->rect210;
    r->x = 0;
    r->y = (short)(int)fz;
    o->posbc->x = fx;
    o->posbc->y = fy + fz;
    FUN_00103480(o);
  } else {
    Rect *r = o->rect210;
    r->x = -50;
    r->y = 0;
    o->posbc->x = fx - 50.0f;
    o->posbc->y = fy;
    FUN_00103480(o);
  }
}

// Ruled out (head only): all 15 orders of {fx=,fy=,flag store,pc0->x=,pc0->y=} (best 5 words, this one: fx, flag, x-store, fy, y-store); locals read inline (reloads the globals, 51 words); p=o->posc0 local for the first store; inline SetX/SetY members; Ghidra raw pointer form; switch/ternary variants.
