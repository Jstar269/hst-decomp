/* HSTMATCH module=hstp_trans_main.prx start=0x000b44f8 end=0x000b45fc symbol=FUN_000b44f8 lang=c++ rodata=0x002cff8c */
/* Clone of src/eboot/pick_index_byte_000b150c.cpp (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Reads the object returned by FUN_000b6e80 and returns one of the signed bytes at +0x21c..+0x22b,
   selected by the third parameter (the switch with the jump table at 0x2cff8c) and the second parameter
   (the nested switch inside the cases 0, 1, 8 and 9). The cases 8, 9 and 10 fall through into each
   other, the case 7 and every other value return 0.
   Matching idioms: the nested selections are SWITCHES (an if/else chain makes the compiler branch
   around the return instead of branching to the epilogue with the byte load in the delay slot), MWCC
   lays the cases out in the source order but tests them in the REVERSE order (so the nested switches
   are written ascending), the byte is a SIGNED char and the jump table has to be placed at 0x2cff8c
   with rodata=. */
extern "C" int FUN_000b6e80(void *self);

extern "C" int FUN_000b44f8(void *self, int param_2, int param_3)
{
  signed char *obj = (signed char *)FUN_000b6e80(self);
  switch (param_3) {
  case 0:
    switch (param_2) {
    case 0: return obj[0x21c];
    case 1: return obj[0x21d];
    case 2: return obj[0x21e];
    }
    break;
  case 1:
    switch (param_2) {
    case 0: return obj[0x229];
    case 1: return obj[0x22a];
    case 2: return obj[0x22b];
    }
    break;
  case 2: return obj[0x228];
  case 3: return obj[0x224];
  case 4: return obj[0x226];
  case 5: return obj[0x227];
  case 6: return obj[0x225];
  case 8:
    switch (param_2) {
    case 0: return obj[0x21f];
    case 1: return obj[0x220];
    }
  case 9:
    switch (param_2) {
    case 0: return obj[0x221];
    case 1: return obj[0x222];
    }
  case 10: return obj[0x223];
  }
  return 0;
}
