/* HSTMATCH module=hstp_trans_main.prx start=0x00212d94 end=0x00212dd8 symbol=FUN_00212d94 lang=c99 */
/* Clone of src/eboot/is_slot_kind_0020452c.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tests whether the "kind" argument is one of 2..5 (the same set the neighbouring
   format_slot_kind_002044b4.c formats as 99). Ghidra's pseudocode claims the default case returns 0,
   but retail's default path falls through the branch-likely delay slot that holds "li v0,1", so retail
   returns 1 for every input; the reconstruction below is the one that reproduces retail's bytes.
   Matching idioms: the switch has to be written with a RESULT VARIABLE ("int r = 0; ... r = 1; break;")
   and a single "return r" at the end - the direct "return 1"/"return 0" form puts the constants in v0
   and moves the case-5 test into a branch-likely, which does not match retail (retail keeps the
   constants in v1, tests 5,4,3,2 in that order and puts the "return 0" into the delay slot of the
   case-5 test). */
int FUN_00212d94(int kind)
{
  int r = 0;
  switch (kind) {
  case 2:
  case 3:
  case 4:
  case 5:
    r = 1;
    break;
  }
  return r;
}
