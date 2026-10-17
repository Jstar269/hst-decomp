/* HSTMATCH module=EBOOT.BIN start=0x002059ec end=0x00205bc0 symbol=FUN_002059ec lang=c++ */
/* Hand-written reconstruction from the disassembly; three-function run 0x2059ec..0x205bc0: the empty variadic stub 0x2059ec is a `static` helper defined earlier in the same file (MWCC then keeps `this` in a3 across the call), 0x205a18 and 0x205b4c are the installed wrap_angles_00205a18.cpp / FUN_00205b4c.c bodies; matching idiom: the call passes o->f50 (not v) as its dropped third argument; exact match verified; names and types await human review. */
extern "C" {
static void FUN_002059ec(...)
{
}
}

struct Obj_00205a18 {
    char pad[0x30];
    float rx, ry, rz;
};
inline void WrapAngle_00205a18(float &a)
{
    if (a < -3.1415927f)
        a += 6.2831855f;
    else if (a > 3.1415927f)
        a -= 6.2831855f;
}
extern "C" void FUN_00205a18(Obj_00205a18 *o)
{
    WrapAngle_00205a18(o->rx);
    WrapAngle_00205a18(o->ry);
    WrapAngle_00205a18(o->rz);
}

struct Obj_00205b4c {
    char pad[0x48];
    int f48;
};
extern "C" void FUN_00205b4c(Obj_00205b4c *o, int v)
{
    o->f48 = v;
}

extern char DAT_002ef6bc[];

struct Obj {
  char pad0[0x4c];
  int f4c;
  int f50;
};

extern "C" void FUN_00205b54(Obj *o, int v)
{
  if (v != o->f4c) {
    if (v >= 2) {
      o->f50 = v;
    } else {
      o->f50 = v;
      if (o->f50 != 0) {
        FUN_002059ec(DAT_002ef6bc, o->f4c, o->f50);
        o->f4c = o->f50;
        o->f50 = 0;
      }
    }
  } else {
    if (o->f50 != 0) {
      o->f50 = 0;
    }
  }
}
