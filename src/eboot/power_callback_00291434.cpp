/* HSTMATCH module=EBOOT.BIN start=0x00291434 end=0x002914c0 symbol=FUN_00291434 lang=c++ helpers=FUN_0028fb44@0x0028fb44-0x0028fb70 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/power_callback_00291434.cpp, completed with its same-file static helper FUN_0028fb44 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
/* Power-callback notification bits. */
enum {
  POWER_CB_SUSPENDING = 0x10000,
  POWER_CB_RESUME_COMPLETE = 0x40000,
  POWER_CB_STANDBY = 0x80000
};

extern "C" {
extern unsigned char DAT_0034a80c; /* 1 while the system is suspended or in standby */
extern char DAT_002ff8e8[];
extern char DAT_002ff928[];
extern char DAT_002ff968[];
static void FUN_0028fb44(...)
{
}

/* Power callback: tracks suspend/resume in DAT_0034a80c and logs each transition. */
int FUN_00291434(int unused, unsigned flags)
{
  if ((flags & POWER_CB_STANDBY) != 0 || (flags & POWER_CB_SUSPENDING) != 0) {
    DAT_0034a80c = 1;
    if ((flags & POWER_CB_STANDBY) != 0) {
      FUN_0028fb44(DAT_002ff8e8);
    }
    else {
      FUN_0028fb44(DAT_002ff928);
    }
  }
  else {
    if ((flags & POWER_CB_RESUME_COMPLETE) != 0) {
      DAT_0034a80c = 0;
      FUN_0028fb44(DAT_002ff968);
    }
  }
  return 0;
}
}
