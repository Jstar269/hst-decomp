/* HSTMATCH module=hstp_trans_main.prx start=0x000957bc end=0x000957dc symbol=FUN_000957bc */
/* Clone of src/eboot/FUN_00093898.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[0x84]; float scale; } Scaled;
typedef struct { char pad[0x58]; Scaled *s; } ScaledRef;

float FUN_000957bc(ScaledRef *r)
{
    return r->s ? r->s->scale : 1.0f;
}
