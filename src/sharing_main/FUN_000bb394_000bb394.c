/* HSTMATCH module=hstp_trans_main.prx start=0x000bb394 end=0x000bb408 symbol=FUN_000bb394 lang=c99 */
/* Clone of src/eboot/FUN_000b80a4_000b80a4.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
typedef unsigned char undefined1;

extern void FUN_000bb408(void);

undefined4 FUN_000bb394(int param_1, int param_2)
{
  switch (param_2) {
  case 8:
  case 0xe:
    if (param_2 == 8)
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x68);
    else
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x6c);
    FUN_000bb408();
    break;
  case 0x14:
    *(undefined1 *)(param_1 + 0x3d) = 1;
    break;
  default:
    break;
  }
  return 0;
}
