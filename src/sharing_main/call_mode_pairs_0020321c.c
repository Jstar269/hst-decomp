/* HSTMATCH module=hstp_trans_main.prx start=0x0020321c end=0x0020330c symbol=FUN_0020321c lang=c99 rodata=0x002d9524 */
/* Clone of src/eboot/call_mode_pairs_001f4c54.c (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0xa8]; char *obj; } Global;
typedef struct { unsigned char pad[0x524]; unsigned int mode; } Self;

extern Global *DAT_003e19f0;
extern void FUN_001c2a28(void *, int, int, int, int);

void FUN_0020321c(Self *self)
{
    char *o = DAT_003e19f0->obj;

    switch (self->mode) {
    case 0:
    case 1:
        FUN_001c2a28(o + 0x3c, 180, 30, 0, 0);
        FUN_001c2a28(o + 0x3c, 185, 90, 0, 0);
        break;
    case 2:
        FUN_001c2a28(o + 0x3c, 180, 30, 0, 0);
        FUN_001c2a28(o + 0x3c, 186, 90, 0, 0);
        break;
    case 3:
    case 4:
    case 5:
        FUN_001c2a28(o + 0x3c, 179, 30, 0, 0);
        FUN_001c2a28(o + 0x3c, 184, 90, 0, 0);
        break;
    }
}
