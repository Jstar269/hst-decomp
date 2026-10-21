/* HSTMATCH module=hstp_trans_main.prx start=0x0023d4f0 end=0x0023d59c symbol=FUN_0023d4f0 lang=c99 */
/* Clone of src/eboot/reset_positions_0022d3f0.c (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (the two position globals are extern const, so retail's loads schedule above the frame save and the first store); names and types await human review. */
extern float DAT_0039bd6c;
extern const float DAT_003f3684;
extern const float DAT_003f3688;
extern void FUN_00108dac();

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

void FUN_0023d4f0(Obj *o, unsigned char flag)
{
  float fx = DAT_003f3684;
  o->f54 = flag;
  o->pc0->x = fx;
  float fy = DAT_003f3688;
  o->pc0->y = fy;
  if (o->f54 != 0) {
    float fz = DAT_0039bd6c;
    Rect *r = o->p210;
    r->x = 0;
    r->y = (short)(int)fz;
    o->pbc->x = fx;
    o->pbc->y = fy + fz;
    FUN_00108dac(o);
  } else {
    Rect *r = o->p210;
    r->x = -50;
    r->y = 0;
    o->pbc->x = fx - 50.0f;
    o->pbc->y = fy;
    FUN_00108dac(o);
  }
}

// Ruled out (head only): all 15 orders of {fx=,fy=,flag store,pc0->x=,pc0->y=} (best 5 words, this one: fx, flag, x-store, fy, y-store); locals read inline (reloads the globals, 51 words); p=o->pc0 local for the first store; inline SetX/SetY members; Ghidra raw pointer form; switch/ternary variants.
