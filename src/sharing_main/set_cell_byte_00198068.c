/* HSTMATCH module=hstp_trans_main.prx start=0x00198068 end=0x001980a8 symbol=FUN_00198068 lang=c99 */
/* Clone of src/eboot/set_cell_byte_0018b8b8.c (hstclone.py tag ds1018ar2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_00198068(char *p, int row, int col, char v)
{
    char *r;

    if (row < 0) return;
    if (row >= 15) return;
    if (col < 0) return;
    if (col >= 4) return;
    r = p + row * 4;
    r[col] = v;
}
