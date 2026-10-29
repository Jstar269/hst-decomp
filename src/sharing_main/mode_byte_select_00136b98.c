/* HSTMATCH module=hstp_trans_main.prx start=0x00136b98 end=0x00136bcc symbol=FUN_00136b98 lang=c99 */
/* Clone of src/eboot/mode_byte_select_0012b72c.c (hstclone.py tag c180307): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[868]; unsigned char f364, pad2[1]; unsigned char f366, f367; };

/* Map a mode to a state byte. The explicit `default: break;` is load-bearing: without it mwcc builds an
   ASCENDING ladder (tests 0,4,5 with case 0 out of line); with it, the same cases become the DESCENDING
   ladder 5,4,0 with branch-likely arms (load in each delay) and case 5 out of line. */
int FUN_00136b98(struct S *s, int a1, int mode)
{
    int r = 0;
    switch (mode) {
    case 0:
        r = s->f364;
        break;
    case 4:
        r = s->f366;
        break;
    case 5:
        r = s->f367;
        break;
    default:
        break;
    }
    return r;
}
