/* HSTMATCH module=hstp_trans_main.prx start=0x001896a8 end=0x001896c4 symbol=FUN_001896a8 */
/* Clone of src/eboot/FUN_0017cfb4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
typedef struct { int pad; int value; } Slot;
typedef struct { int pad; int index; Slot **slots; } SlotList;

void FUN_001896a8(SlotList *l, int v)
{
    l->slots[l->index]->value = v;
}
