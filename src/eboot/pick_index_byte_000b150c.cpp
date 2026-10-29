/* HSTMATCH module=EBOOT.BIN start=0x000b150c end=0x000b1610 symbol=FUN_000b150c lang=c++ rodata=0x002bffa0 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Reads the object returned by FUN_000b3c68 and returns one of the signed bytes at +0x21c..+0x22b,
   selected by the third parameter `kind` (the switch with the jump table at 0x2bffa0) and the second parameter `sub`
   (the nested switch inside the cases 0, 1, 8 and 9). The cases 8, 9 and 10 fall through into each
   other, the case 7 and every other value return 0.
   Matching idioms: the nested selections are SWITCHES (an if/else chain makes the compiler branch
   around the return instead of branching to the epilogue with the byte load in the delay slot), MWCC
   lays the cases out in the source order but tests them in the REVERSE order (so the nested switches
   are written ascending), the byte is a SIGNED char and the jump table has to be placed at 0x2bffa0
   with rodata=. */
/* Object returned by the lookup: a run of signed bytes starting at +0x21c. */
struct ByteTable {
  char pad[0x21c];
  signed char v[16];
};

extern "C" ByteTable *FUN_000b3c68(void *self);

extern "C" int FUN_000b150c(void *self, int sub, int kind)
{
  ByteTable *obj = FUN_000b3c68(self);
  switch (kind) {
  case 0:
    switch (sub) {
    case 0: return obj->v[0];
    case 1: return obj->v[1];
    case 2: return obj->v[2];
    }
    break;
  case 1:
    switch (sub) {
    case 0: return obj->v[0xd];
    case 1: return obj->v[0xe];
    case 2: return obj->v[0xf];
    }
    break;
  case 2: return obj->v[0xc];
  case 3: return obj->v[8];
  case 4: return obj->v[0xa];
  case 5: return obj->v[0xb];
  case 6: return obj->v[9];
  case 8:
    switch (sub) {
    case 0: return obj->v[3];
    case 1: return obj->v[4];
    }
  case 9:
    switch (sub) {
    case 0: return obj->v[5];
    case 1: return obj->v[6];
    }
  case 10: return obj->v[7];
  }
  return 0;
}
