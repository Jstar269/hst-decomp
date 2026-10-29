/* HSTMATCH module=EBOOT.BIN start=0x002052b8 end=0x00205374 symbol=FUN_002052b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed object views; the if/else on use_arg is a done flag (matching idiom: done = 0; if (use_arg != 0) { F(..arg); done = 1; } if (done == 0) F(..0);), #pragma opt_strength_reduction off for the recomputed index*4, and handle declared before slot for the s-registers; exact match verified; readability pass; names and types await human review. */
typedef struct { char pad[0x58]; int handle; } Sub;
#pragma opt_strength_reduction off
typedef struct { Sub *sub; int unk4; int unk8; int *slots; } Obj;
enum { SLOT_COUNT = 6 };
extern void FUN_0005743c(int a, int b, int c, int d);

/* For each of the six slots calls the helper with the sub-object's handle, the slot value and arg (or 0). */
void FUN_002052b8(Obj *obj, int use_arg, int arg)
{
  int handle;
  int slot;
  int done;

  handle = obj->sub->handle;
  if (handle != 0) {
    slot = 0;
    do {
      done = 0;
      if (use_arg != 0) {
        FUN_0005743c(handle, slot, obj->slots[slot], arg);
        done = 1;
      }
      if (done == 0) {
        FUN_0005743c(handle, slot, obj->slots[slot], 0);
      }
      slot = slot + 1;
    } while (slot < SLOT_COUNT);
  }
}
