/* HSTMATCH module=EBOOT.BIN start=0x001468a0 end=0x001468e4 symbol=FUN_001468a0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00148300(void *a, Arg1 b);
extern "C" void FUN_001480d0(void *a, int b, void *c);
extern "C" void FUN_001468a0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00148300(a, x); FUN_001480d0(a, 1, b); }
