/* HSTMATCH module=hstp_trans_main.prx start=0x000a9f70 end=0x000aa02c symbol=FUN_000a9f70 lang=c99 */
/* Clone of src/eboot/FUN_000a75a8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: copied the four float fields through a typed array, aligned the vector result buffer, and typed the matrix-member argument to preserve the call setup; exact match verified; names and types await human review. */
typedef unsigned char bool;
typedef unsigned char undefined1;
typedef unsigned int uint;
typedef struct { char pad[0x5a0]; float matrix[4]; } MatrixOwner;
extern int FUN_000aa02c();
extern void FUN_00022478(float *, void *, float *);
bool FUN_000a9f70(int self, int other) {
  bool result;
  undefined1 auStack_10[16];
  undefined1 auStack_20[16];
  float fields[4];
  float local_40[4] __attribute__((aligned(16)));
  if ((*(uint *)(self + 0x144) ^ 1) == *(uint *)(other + 0x230)) {
    fields[0] = *(float *)(self + 0x580);
    fields[1] = *(float *)(self + 0x584);
    fields[2] = *(float *)(self + 0x588);
    fields[3] = *(float *)(self + 0x58c);
    if (FUN_000aa02c(self, auStack_20, other + 0x26c, fields, 1, 0, 0) != 0) {
      FUN_00022478(local_40, auStack_10, ((MatrixOwner *)self)->matrix);
      bool mode = *(int *)(self + 0x150) == 0;
      bool inside = *(float *)(self + 0x580) <= local_40[0];
      result = mode == inside;
    } else {
      result = 1;
    }
  } else {
    result = 1;
  }
  return result;
}


