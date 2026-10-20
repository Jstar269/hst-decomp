/* HSTMATCH module=hstp_trans_main.prx start=0x0017788c end=0x001778e4 symbol=FUN_0017788c lang=c99 */
/* Clone of src/eboot/code_slot_0016b6c8.c (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0x103e]; unsigned short slot; } Table;
extern Table *FUN_00177d4c(int);
void FUN_0017788c(int id)
{
    Table *t = FUN_00177d4c(id);
    unsigned short v = (unsigned short)id;
    if (v == 0x7fff || v == 0x7ffe || (v >= 0 && v < 15)) t->slot = (unsigned short)id;

}
