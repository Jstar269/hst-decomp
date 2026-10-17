/* HSTMATCH module=EBOOT.BIN start=0x002797e8 end=0x00279854 symbol=FUN_002797e8 lang=c99 */
/* Hand-written reconstruction from the disassembly; NEAR MISS (5 words); names and types await human review. */
extern char DAT_002fe690[];
extern void FUN_0026f7f4();

typedef struct Obj {
  char pad0[0x104];
  int mode;
  char pad1[0x10];
  int f118[4];
  int f128[4];
  int f138[4];
  int f148[4];
} Obj;

void FUN_002797e8(Obj *o, int value)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    o->f148[mode - 1] = value;
    FUN_0026f7f4(DAT_002fe690, mode, value);
    break;
  }
}
// Mode setter (cf. the exact getters mode_getter_*.c): stores into a 4-entry table by mode 1..4 and prints (fmt, mode, value) through the empty variadic stub 0x26f7f4.
// Differs in 5 words: ours addresses the slot in v0 and schedules `sw` before the `addiu a0` (the jal slot holds the addiu); retail uses v1 and has the `sw` in the jal delay slot.
// Cause (verified): the retail stub is a `static` empty variadic function defined EARLIER IN THE SAME TU (first function of the 0x26f7f4.. translation unit). With
//   extern "C" { static void FUN_0026f7f4(...) {} }  in front of the setter (lang=c++, the stub as first function) the setter body is byte-exact to retail and only the
//   jal target differs (it points at the local stub). Same effect as 0x205b54 (a3 kept across a call to a static stub). hstmatch cannot place that stub: it would have to
//   link at 0x26f7f4, 0x9b20 bytes before this function, i.e. the whole 40 KB run 0x26f7f4..0x279854 would have to be one source.
// Ruled out (~25 compiles): C++ vs C, store as an argument expression / comma operand, string pointer in a local, store through a pointer local, typed tab[mode] view,
//   reading the slot back as the third argument, reversed case labels, store after the call (needs s-regs, 35 words).
