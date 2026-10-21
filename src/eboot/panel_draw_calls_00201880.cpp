/* HSTMATCH module=EBOOT.BIN start=0x00201880 end=0x00201910 symbol=FUN_00201880 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the four calls take a typed Panel pointer (&self->panels[i]) as first argument with member reads x/y of the same panel, which fixes the delay-slot choice of the first call; exact match verified; names and types await human review. */
struct Panel { char pad0[8]; short x, y; char pad[0x8c-12]; };
struct Obj { char pad[0x8bc]; Panel panels[4]; };
extern "C" void FUN_002177d4(Panel *, int, int, int, int, int);
extern "C" void FUN_00201880(Obj *self)
{
  FUN_002177d4(&self->panels[0], self->panels[0].x + 240, self->panels[0].y, self->panels[0].x, self->panels[0].y, 6);
  FUN_002177d4(&self->panels[1], self->panels[1].x + 240, self->panels[1].y, self->panels[1].x, self->panels[1].y, 6);
  FUN_002177d4(&self->panels[2], self->panels[2].x + 240, self->panels[2].y, self->panels[2].x, self->panels[2].y, 6);
  FUN_002177d4(&self->panels[3], self->panels[3].x + 240, self->panels[3].y, self->panels[3].x, self->panels[3].y, 6);
}
