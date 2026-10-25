/* HSTMATCH module=hstp_trans_main.prx start=0x000e3144 end=0x000e31a0 symbol=FUN_000e3144 lang=c99 */
/* Clone of src/eboot/round_half_000def58.c (hstclone.py tag lnmc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: shared bool result with an inner >= half branch; exact match verified; names and types await human review. */
extern unsigned char DAT_003e1e88;
typedef unsigned char bool;
bool FUN_000e3144(int self) {
  bool result;
  if (DAT_003e1e88 != 0) {
    result = *(int *)(self + 0xc8) > 0;
  } else {
  int half = (*(int *)(self + 0xb4) + 1) / 2;
  if (*(int *)(self + 0xb8) < half) {
      if (*(int *)(self + 0xbc) >= half) result = 1;
      else result = 0;
    } else {
      result = 1;
    }
  }
  return result;
}
