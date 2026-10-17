/* HSTMATCH module=EBOOT.BIN start=0x00125230 end=0x001252d0 symbol=FUN_00125230 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Returns 1 when none of six state flags (two helper calls and four byte flags) is set. Matching idiom: `int r = ..; if (!r) r = ..; return r ^ 1;`; `return !(a || b ...)` adds a trailing andi 0xff. */
struct GameA {
  char pad0[0x5e];
  unsigned char f5e;
  char pad1[3];
  unsigned char f62;
  char pad2[0x22];
  unsigned char f85;
};
struct GameB {
  char pad[0xf1];
  unsigned char ff1;
};
extern GameA *DAT_00338b44;
extern GameB *DAT_00340284;
extern "C" int FUN_000dbc04(GameA *);
extern "C" int FUN_000defb4(GameA *);

extern "C" int FUN_00125230(void)
{
  int r = FUN_000dbc04(DAT_00338b44) != 0;
  if (!r) r = DAT_00338b44->f5e != 0;
  if (!r) r = FUN_000defb4(DAT_00338b44) != 0;
  if (!r) r = DAT_00338b44->f85 != 0;
  if (!r) r = DAT_00338b44->f62 != 0;
  if (!r) r = DAT_00340284->ff1 != 0;
  return r ^ 1;
}
