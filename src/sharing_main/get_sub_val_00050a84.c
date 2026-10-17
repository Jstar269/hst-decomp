/* HSTMATCH module=hstp_trans_main.prx start=0x00050a84 end=0x00050ae4 symbol=FUN_00050a84 lang=c99 */
/* Clone of src/eboot/get_sub_val_000501a8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void *FUN_00050aec(void);
extern void *FUN_00023a28(void *);

struct Sub {
    char pad[6];
    unsigned short val;
};

struct Manager {
    char pad[24];
    void *item;
    char pad2[112];
    unsigned char type;
};

unsigned short FUN_00050a84(void)
{
    unsigned short ret = 0;
    struct Manager *mgr = (struct Manager *)FUN_00050aec();
    if (mgr != 0) {
        void *item = (mgr->type == 3) ? mgr->item : 0;
        if (item != 0) {
            struct Sub *sub = (struct Sub *)FUN_00023a28(item);
            if (sub != 0) {
                ret = sub->val;
            }
        }
    }
    return ret;
}
