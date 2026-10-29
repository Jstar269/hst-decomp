/* HSTMATCH module=EBOOT.BIN start=0x0012b72c end=0x0012b760 symbol=FUN_0012b72c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[868]; unsigned char f364, pad2[1]; unsigned char f366, f367; };

/* Map a mode to a state byte. The explicit `default: break;` is load-bearing: without it mwcc builds an
   ASCENDING ladder (tests 0,4,5 with case 0 out of line); with it, the same cases become the DESCENDING
   ladder 5,4,0 with branch-likely arms (load in each delay) and case 5 out of line. */
int FUN_0012b72c(struct S *s, int a1, int mode)
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
