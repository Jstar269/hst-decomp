/* HSTMATCH module=EBOOT.BIN start=0x001bbc58 end=0x001bbcd4 symbol=FUN_001bbc58 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: unsigned short loop with pb declared before pa and 3-byte tail comparison; exact match verified; names and types await human review. */

int FUN_001bbc58(unsigned short *a, unsigned short *b)
{
  int r = 1;
  int i = 0;
  unsigned short *pb = b;
  unsigned short *pa = a;
  do {
    if (*pa != *pb) {
      r = 0;
      break;
    }
    i++;
    pb++;
    pa++;
  } while (i < 4);

  unsigned char *ba = (unsigned char *)a;
  unsigned char *bb = (unsigned char *)b;

  if (ba[8] != bb[8]) {
    r = 0;
  }
  if (ba[9] != bb[9]) {
    r = 0;
  }
  if (ba[10] != bb[10]) {
    r = 0;
  }
  return r;
}
