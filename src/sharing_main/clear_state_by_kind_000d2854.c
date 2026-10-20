/* HSTMATCH module=hstp_trans_main.prx start=0x000d2854 end=0x000d28b0 symbol=FUN_000d2854 lang=c99 */
/* Clone of src/eboot/clear_state_by_kind_000cec58.c (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0x3c]; unsigned char flag; } Self;
int FUN_000d2854(Self *s, int kind)
{
    switch (kind) {
    case 0:
    case 1:
        break;
    case 14:
        s->flag = 0;
        break;
    case 8:
        s->flag = 0;
        break;
    case 9:
        s->flag = 0;
        break;
    case 10:
        break;
    case 11:
        break;
    }
    return 0;

}
