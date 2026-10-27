/* HSTMATCH module=hstp_trans_main.prx start=0x001e2114 end=0x001e21a8 symbol=FUN_001e2114 lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/rect_set_center_001d4310.cpp: the function name retargeted, the code is identical); exact match verified; names and types await human review. */
/* Moves the short rectangle at +4 (x1,y1,x2,y2) so that it is centred on (cx, cy): each axis shifts the near edge to
   cx - width/2 and drags the far edge by the same delta (cf. EBOOT.BIN FUN_001d764c). Matching idiom: Width()/Height() are
   getters on the Rect sub-object while SetX/SetY read x1/y1 through the Obj; with everything on one type MWCC CSEs
   the first x1/y1 load into a register (retail reloads it). Names provisional. */
struct Rect {
  short x1;
  short y1;
  short x2;
  short y2;
  short Width() const { return x2 - x1; }
  short Height() const { return y2 - y1; }
};
struct Obj {
  char pad[4];
  Rect r;
  void SetX(short x) { short dx = x - r.x1; r.x1 = x; r.x2 += dx; }
  void SetY(short y) { short dy = y - r.y1; r.y1 = y; r.y2 += dy; }
};

extern "C" void FUN_001e2114(Obj *o, short cx, short cy)
{
  o->SetX(cx - o->r.Width() / 2);
  o->SetY(cy - o->r.Height() / 2);
}
