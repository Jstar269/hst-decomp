/* HSTMATCH module=EBOOT.BIN start=0x00199e0c end=0x00199f78 symbol=FUN_00199e0c lang=c++ data=0x002e1a54 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002e1a54-0x002e1a80) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Layout container: children are looked up by name (vtable slot 1 takes one int). */
struct Layout { virtual void d0(); virtual void v1(int); };
/* Pane object driven through its vtable (slots 1 and 10); two shorts at 0x11c. */
struct Pane { virtual void d0(); virtual void v1(int); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void v10();
  char pad[0x118]; short unk11c; short unk11e; };
struct InstallScreen { char pad[0x54]; Pane *pane; Layout *layout; int unk5c; };

extern int DAT_002cfc8c;
extern int DAT_003417a4;
extern "C" void FUN_0001dfe8(int, int);
extern "C" void FUN_0001e23c(int, int, int);
extern "C" void FUN_000ffb3c(void *, int);
extern "C" void *FUN_001026b8(Layout *, char *);
extern "C" void FUN_0010b8cc(Pane *, int, int);
extern "C" void FUN_00199f78(InstallScreen *);

/* Set up the install screen: select the background layer for the current mode (flag 0 = the chosen one), then place the pane. */
extern "C" void FUN_00199e0c(InstallScreen *screen)
{
  screen->unk5c = 0;
  FUN_0001dfe8(DAT_002cfc8c, 0x2000);
  FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
  screen->layout->v1(0);
  FUN_000ffb3c(FUN_001026b8(screen->layout, "installbg0"), 0);
  FUN_000ffb3c(FUN_001026b8(screen->layout, "installbg_hst0"), 1);
  FUN_000ffb3c(FUN_001026b8(screen->layout, "installbg_asia0"), 1);
  if (DAT_003417a4 - 2U < 2) {
    FUN_000ffb3c(FUN_001026b8(screen->layout, "installbg0"), 1);
    FUN_000ffb3c(FUN_001026b8(screen->layout, "installbg_hst0"), 0);
    FUN_000ffb3c(FUN_001026b8(screen->layout, "installbg_asia0"), 1);
  }
  screen->pane->v1(0);
  screen->pane->v10();
  Pane *pane = screen->pane;
  pane->unk11c = -12;
  pane->unk11e = 0;
  FUN_0010b8cc(screen->pane, 0, 2);
  FUN_00199f78(screen);
}
