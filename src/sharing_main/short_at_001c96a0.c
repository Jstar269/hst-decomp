/* HSTMATCH module=hstp_trans_main.prx start=0x001c96a0 end=0x001c972c symbol=FUN_001c96a0 lang=c99 rodata=0x002d679c */
/* Clone of src/eboot/short_at_001bb8b8.c (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_0019fc84(int);

int FUN_001c96a0(int param_1, int param_2)
{
  int v = FUN_0019fc84(param_2);
  if (v != 0) {
    switch (param_1) {
    case 0: return *(short *)(v + 0);
    case 1: return *(short *)(v + 2);
    case 2: return *(short *)(v + 4);
    case 3: return *(short *)(v + 6);
    case 4: return *(short *)(v + 8);
    case 5: return *(short *)(v + 10);
    }
  }
  return 0;
}
