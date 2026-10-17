/* HSTMATCH module=hstp_trans_main.prx start=0x001939ec end=0x00193a54 symbol=FUN_001939ec */
/* Clone of src/eboot/FUN_001872a0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
typedef struct { unsigned int value; unsigned int pad[4]; } Rec;
typedef struct { char pad0[0x2884]; Rec *recs; char pad1[0x2a24 - 0x2888]; int count; } RecOwner;
extern void FUN_00105470(unsigned int value, int mode);

void FUN_001939ec(RecOwner *c)
{
    Rec *r;
    int i;
    r = c->recs;
    for (i = 0; i < c->count; i++) {
        if (r->value != 0) FUN_00105470(r->value, 1);
        r++;
    }
}
