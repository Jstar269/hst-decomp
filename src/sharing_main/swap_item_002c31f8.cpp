/* HSTMATCH module=hstp_trans_main.prx start=0x002c31f8 end=0x002c3498 symbol=FUN_002c31f8 lang=c++ */
/* Clone of src/eboot/swap_item_002b3738.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-written swap of 100-byte struct; unrolled copy loops generated via operator=; exact match verified; names and types await human review. */

struct Item {
    int f0;
    char name[32];
    char desc[32];
    char c68;
    char c69;
    char c70;
    unsigned char u71;
    unsigned char u72;
    char c73;
    char c74;
    char c75;
    int f76;
    int f80;
    char extra[16];
};

extern "C" void FUN_002c31f8(Item *a, Item *b)
{
    Item tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
