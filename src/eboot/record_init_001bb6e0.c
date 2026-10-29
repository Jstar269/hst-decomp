/* HSTMATCH module=EBOOT.BIN start=0x001bb6e0 end=0x001bb8b8 symbol=FUN_001bb6e0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/record_info.h"

extern void FUN_00011090(void *, const void *, int);
extern void FUN_000149a8(void *, const void *);
extern RecordInfo *FUN_00193474(int);

enum { RECORD_SIZE = 0x9c, UNK64_LIMIT = 0x16 };

/* Builds a record: copies the template (s40), fills the halfword values and extras from the info record for id
   (param_3), then the byte settings and the repeated groups. Stack arguments are named after their stack offset. */
void FUN_001bb6e0(RecordInfo *rec, int param_2, int id, int val1, int val2,
                  int val3, int val4, int val5,
                  unsigned char s0, unsigned char s4, unsigned char s8, int sC,
                  int s10, int s14, int s18, int s1C, int s20, int s24,
                  unsigned char s28, int s2C, unsigned char s30, int s34, int s38,
                  unsigned char s3C, int s40)
{
    RecordInfo *info;
    int i;
    unsigned char *p;

    FUN_00011090(rec, (const void *)s40, RECORD_SIZE);
    info = FUN_00193474(id);
    if (info != 0) {
        rec->extra[0] = info->extra[0];
        rec->extra[1] = info->extra[1];
        rec->extra[2] = info->extra[2];
        rec->extra[3] = info->extra[3];
        rec->extra[4] = info->extra[4];
        rec->extra[5] = info->extra[5];
        rec->extra[6] = info->extra[6];
        rec->extra[7] = info->extra[7];
    }
    rec->vals[0] = (short)id;
    rec->vals[1] = (short)val1;
    rec->vals[2] = (short)val2;
    rec->vals[3] = (short)val3;
    rec->vals[4] = (short)val4;
    rec->vals[5] = (short)val5;
    FUN_000149a8(rec->unkcc, (const void *)param_2);
    rec->unk9c = s0;
    rec->unk9d = s4;
    rec->unk9e = s8;
    rec->unk9f = s28;
    rec->unka0 = sC;
    rec->unk64 = s10;
    if (rec->unk64 < 0 || rec->unk64 >= UNK64_LIMIT)
        rec->unk64 = 0;
    rec->unk65 = s14;
    rec->unk52 = (short)s18;
    FUN_000149a8(rec->unk54, (const void *)s1C);
    rec->unk66 = s20;
    rec->unk67 = s2C;
    i = 0;
    p = (unsigned char *)rec; /* advances by one 3-byte group per pass; the groups sit at 0x7c */
    do {
        p[0x7d] = rec->unk64;
        rec->unk78 = rec->unk52;
        FUN_000149a8(rec->unk68, rec->unk54);
        i = i + 1;
        rec->unk7c[0] = rec->unk66;
        p[0x7e] = rec->unk67;
        p = p + 3;
    } while (i < INFO_REPEATS);
    rec->unkc9 = s24;
    rec->unkcb = s34;
    rec->unkec = s38;
    rec->unk101 = s3C;
    rec->unkc8 = s30;
}
