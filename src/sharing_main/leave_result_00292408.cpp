/* HSTMATCH module=hstp_trans_main.prx start=0x00292408 end=0x002924a0 symbol=FUN_00292408 lang=c++ */
/* Hand-written reconstruction from the disassembly (same source as the EBOOT twin src/eboot/leave_result_00281090.cpp, addresses substituted); exact match verified; names and types await human review. */
struct GObj { virtual ~GObj(); };
extern "C" void FUN_000bdad0(GObj *p);
extern "C" void FUN_000bd848(GObj *p);
extern "C" void FUN_00108f54(void *a, int b);
struct Tag {};
extern "C" void FUN_00121330(void *a, int b, Tag c);

/* Screen object; only the byte at 0x2c00 is touched here. */
struct ScreenObj {
  char pad00[0x2c00];
  char unk2c00;          /* 0x2c00 */
};

/* Global holder (DAT_003ea8ec): a sub-object at 0x8c whose first-word companion sits at 0x90. */
struct Holder {
  char pad00[0x8c];
  char sub8c[4];         /* 0x8c, passed by address */
  int unk90;             /* 0x90 */
};

extern GObj *DAT_003e1e04;
extern Holder *DAT_003ea8ec;

/* Clears the flag, destroys the global object if present and releases the holder's sub-object. */
extern "C" void FUN_00292408(ScreenObj *self)
{
  self->unk2c00 = 0;
  if (DAT_003e1e04 != 0) {
    FUN_000bdad0(DAT_003e1e04);
    FUN_000bd848(DAT_003e1e04);
    if (DAT_003e1e04 != 0) {
      delete DAT_003e1e04;
      DAT_003e1e04 = 0;
    }
  }
  FUN_00108f54(DAT_003ea8ec, 1);
  FUN_00121330(DAT_003ea8ec->sub8c, DAT_003ea8ec->unk90, Tag());
}
