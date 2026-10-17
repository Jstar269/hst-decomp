/* HSTMATCH module=hstp_trans_main.prx start=0x002b40c8 end=0x002b413c symbol=FUN_002b40c8 lang=c++ */
/* Clone of src/eboot/delete_items_and_callback_002a4938.cpp (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: initialization scheduling and delete loop; exact match verified; names and types await human review. */

struct VC_0 { virtual ~VC_0(); };

extern "C" {
extern VC_0 *DAT_003f468c[4];
extern char DAT_003a9838;
extern void FUN_002b413c(void *);
}

extern "C" void FUN_002b40c8(void)
{
    int i;
    VC_0 **p;
    i = 0;
    p = DAT_003f468c;
    do {
        VC_0 *item = *p;
        if (item != 0) {
            delete item;
            *p = 0;
        }
        p++;
    } while (++i < 4);
    FUN_002b413c(&DAT_003a9838);
}
