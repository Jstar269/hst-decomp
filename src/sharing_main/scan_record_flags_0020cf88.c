/* HSTMATCH module=hstp_trans_main.prx start=0x0020cf88 end=0x0020d018 symbol=FUN_0020cf88 lang=c99 */
/* Clone of src/eboot/scan_record_flags_001fe7b8.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char uchar;
typedef unsigned int uint;
void FUN_0020cf88(int *param_1)
{
  uchar found = 0;
  int i = 0;
  int *cursor = param_1;
  do {
    if ((*cursor != 0x7fffffff) && ((uchar)cursor[1] != 0)) found = 1;
    ++i;
    *(uchar *)(cursor + 1) = 0;
    cursor += 8;
  } while (i < 10);
  if (found) {
    i = 9;
    cursor = param_1 + 0x48;
    do {
      if (*cursor != 0x7fffffff) {
        int offset = i << 5;
        *(uchar *)(offset + (int)param_1 + 4) = 1;
        return;
      }
      --i;
      cursor -= 8;
    } while (i >= 0);
  }
}
