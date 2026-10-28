/* HSTMATCH module=hstp_trans_main.prx start=0x00123adc end=0x00123b54 symbol=FUN_00123adc lang=c99 */
/* Clone of src/eboot/clear_nested_fields_00118908.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

void FUN_00123adc(int param_1)
{
  int outer = 0;
  int middle = 0;
  int inner = 0;
  char *parent = (char *)param_1;
  do {
    *(int *)(param_1 + 0xf4) = 0;
    middle = 0;
    {
      char *row = parent;
      do {
        inner = 0;
        {
          char *item = row;
          do {
            *(int *)(item + 0x104) = 0;
            *(int *)(item + 0x108) = 0;
            *(int *)(item + 0x10c) = 0;
            *(int *)(item + 0x110) = 0;
            inner += 5;
            *(int *)(item + 0x114) = 0;
            item += 0x14;
          } while (inner < 6);
        }
        *(int *)(row + inner * 4 + 0x104) = 0;
        middle++;
        row += 0x2c;
      } while (middle < 2);
    }
    outer++;
    param_1 += 4;
    parent += 0x58;
  } while (outer < 4);
}
