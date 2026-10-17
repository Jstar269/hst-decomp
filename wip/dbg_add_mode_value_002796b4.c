/* HSTMATCH module=EBOOT.BIN start=0x002796b4 end=0x0027977c symbol=FUN_002796b4 lang=c99 */
/* Near miss (needs an hstmatch way to place a same-file static helper). Adds param_2 to the mode-indexed entry of the
   +0x138 array (modes 1-4; sibling getter src/eboot/mode_getter_f138_002795dc.c): inline Get (debug print and 0 on an
   invalid mode) + inline Set (store and debug print). Written with a same-file STATIC varargs stub `Dbg` defined before
   the function: only then does MWCC keep a2/a3 live across the calls (retail keeps this in a3 and param_2 in a2 across
   `jal 0x26f7f4`; with an extern declaration it reloads). Compared against retail with the stub's 44 bytes skipped, the
   body is identical except the two `jal` targets (ours call the local Dbg at 0x2796b4, retail 0x26f7f4); hstmatch
   reports MISPLACED because the stub becomes the first function of the object (hstmatch only finds the first .text
   section). Switch labels in source order 1..4 give retail's reversed 4,3,2,1 beq chain; the early-return inline
   getter is what puts the value in v1 (the same code with locals puts it in a0). */
typedef struct {
  char pad0[0x104];
  int mode;
  char pad108[0x134 - 0x108];
  int vals[5];
} Obj;
extern char DAT_002fe648[];
extern char DAT_002fe660[];
static void Dbg(...) {}

static inline int Get(Obj *o)
{
  int m = o->mode;
  switch (m) {
  case 1:
  case 2:
  case 3:
  case 4:
    return o->vals[m];
  default:
    Dbg(DAT_002fe648, m);
    return 0;
  }
}

static inline void Set(Obj *o, int val)
{
  int m = o->mode;
  switch (m) {
  case 1:
  case 2:
  case 3:
  case 4:
    o->vals[m] = val;
    Dbg(DAT_002fe660, m, val);
    break;
  }
}

void FUN_002796b4(Obj *param_1, int param_2)
{
  Set(param_1, param_2 + Get(param_1));
}
