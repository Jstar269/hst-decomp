/* HSTMATCH module=EBOOT.BIN start=0x00118908 end=0x00118980 symbol=FUN_00118908 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

/* Zeroes the four-int array at +0xf4 and the table of 4 banks x 2 rows x 11 ints at +0x104. */
void FUN_00118908(int self)
{
  int outer = 0;
  int middle = 0;
  int inner = 0;
  char *parent = (char *)self;
  do {
    *(int *)(self + 0xf4) = 0;
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
    self += 4;
    parent += 0x58;
  } while (outer < 4);
}
