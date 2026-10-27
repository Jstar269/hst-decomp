/* HSTMATCH module=hstp_trans_main.prx start=0x001fb5ec end=0x001fb7d0 symbol=FUN_001fb5ec lang=c++ data=0x00396380 */
/* Clone of src/eboot/init_items_from_config_001ed27c.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (9 strings, 0x00396380-0x003963d2) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: C++ with an inline-constructed `new Res` (matching shape for `beqz v0; move s0,v0`), typed query results as floats, the two-entry item array indexed by the loop counter, first-call argument restored; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_00396360[];
extern char DAT_0039637c[];
extern char DAT_003b0388[];
extern void FUN_00065884(void *);
extern void FUN_0008d97c(void *);
extern void FUN_00066260(void *, char *, int, int, char *);
extern float FUN_00066bb0(void *, char *, int);
extern void FUN_001fb7d0(void *);
}

struct Res {
  char pad[0x30];
  Res() {
    FUN_00065884(this);
    *(char **)this = DAT_003b0388;
    FUN_0008d97c(pad + 16);
    FUN_0008d97c(pad + 32);
  }
};

struct Item {
  float a, b, c, d, e, f, g, h, i;
};

struct Obj {
  char pad[0x90];
  Res *res;
  char pad2[8];
  Item items[2];
};

extern "C" void FUN_001fb5ec(Obj *self)
{
  FUN_001fb7d0(self);
  Res *p = new Res;
  self->res = p;
  FUN_00066260(p, DAT_00396360, 1, 1, DAT_0039637c);
  for (unsigned int i = 0; i < 2; i++) {
    Item *it = &self->items[i];
    int n = i + 1;
    it->a = FUN_00066bb0(self->res, "RotSpeed", n) * 0.017453292f * 0.033333335f;
    it->b = FUN_00066bb0(self->res, "Tilt", n) * 0.017453292f;
    it->c = FUN_00066bb0(self->res, "TiltWin", n) * 0.017453292f;
    it->d = FUN_00066bb0(self->res, "Distance", n);
    it->e = FUN_00066bb0(self->res, "FovX", n);
    it->f = FUN_00066bb0(self->res, "OffsetY", n);
    it->g = FUN_00066bb0(self->res, "Near", n);
    it->h = FUN_00066bb0(self->res, "Far", n);
    it->i = FUN_00066bb0(self->res, "DefaultAngleY", n) * 0.017453292f;
  }
}
