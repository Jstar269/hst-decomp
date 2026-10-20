/* HSTMATCH module=EBOOT.BIN start=0x0016b6c8 end=0x0016b720 symbol=FUN_0016b6c8 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0x103e]; unsigned short slot; } Table;
extern Table *FUN_0016bb88(int);
void FUN_0016b6c8(int id)
{
    Table *t = FUN_0016bb88(id);
    unsigned short v = (unsigned short)id;
    if (v == 0x7fff || v == 0x7ffe || (v >= 0 && v < 15)) t->slot = (unsigned short)id;

}
