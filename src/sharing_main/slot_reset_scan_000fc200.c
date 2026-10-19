/* HSTMATCH module=hstp_trans_main.prx start=0x000fc200 end=0x000fc270 symbol=FUN_000fc200 lang=c99 */
/* Clone of src/eboot/slot_reset_scan_000f6b0c.c (hstclone.py tag ds1018ar4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Slot {
    char pad0[0x30];
    unsigned char f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    char pad1[0x0c];
    int f50;
    int f54;
    int f58;
    float f5c;
    int f60;
    int f64;
    int f68;
} Slot;

void FUN_000fc200(Slot *base, int key)
{
    unsigned int i = 0;
    Slot *p = base;

    for (; i < 32; p = (Slot *)((char *)p + 0x40), i++) {
        if (key != 0 && key != p->f3c)
            continue;
        p->f30 = 0;
        p->f34 = -1;
        p->f38 = 0;
        p->f3c = 0;
        p->f40 = -1;
        p->f50 = 0;
        p->f54 = 0;
        p->f58 = 0;
        p->f5c = 1.0f;
        p->f60 = 0;
        p->f64 = 0;
        p->f68 = 0;
    }
    *(unsigned char *)((char *)base + 0x870) = 1;
}
