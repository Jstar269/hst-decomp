/* HSTMATCH module=EBOOT.BIN start=0x000cec58 end=0x000cecb4 symbol=FUN_000cec58 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0x3c]; unsigned char flag; } Self;
int FUN_000cec58(Self *s, int kind)
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
