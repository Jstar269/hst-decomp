/* HSTMATCH module=EBOOT.BIN start=0x002a4938 end=0x002a49ac symbol=FUN_002a4938 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: initialization scheduling and delete loop; exact match verified; names and types await human review. */

struct VC_0 { virtual ~VC_0(); };

extern "C" {
extern VC_0 *DAT_0034b340[4];
extern char DAT_0030079c;
extern void FUN_002a49ac(void *);
}

extern "C" void FUN_002a4938(void)
{
    int i;
    VC_0 **p;
    i = 0;
    p = DAT_0034b340;
    do {
        VC_0 *item = *p;
        if (item != 0) {
            delete item;
            *p = 0;
        }
        p++;
    } while (++i < 4);
    FUN_002a49ac(&DAT_0030079c);
}
