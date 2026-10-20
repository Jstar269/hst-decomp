/* HSTMATCH module=hstp_trans_main.prx start=0x001d0158 end=0x001d01ac symbol=FUN_001d0158 lang=c99 */
/* Clone of src/eboot/board_cell_001c1f44.c (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern unsigned char DAT_003eb004[];

unsigned char *FUN_001d0158(int row, int col)
{
    if (row >= 0 && row < 2 && col >= 0 && col < 2)
        return DAT_003eb004 + 1046 + row * 0x4000 + col * 0x2000;
    return 0;
}
