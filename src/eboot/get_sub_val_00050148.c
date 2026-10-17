/* HSTMATCH module=EBOOT.BIN start=0x00050148 end=0x000501a8 symbol=FUN_00050148 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void *FUN_00050210(void);
extern void *FUN_00023a00(void *);

struct Sub {
    char pad[12];
    unsigned short val;
};

struct Manager {
    char pad[24];
    void *item;
    char pad2[112];
    unsigned char type;
};

unsigned short FUN_00050148(void)
{
    unsigned short ret = 0;
    struct Manager *mgr = (struct Manager *)FUN_00050210();
    if (mgr != 0) {
        void *item = (mgr->type == 3) ? mgr->item : 0;
        if (item != 0) {
            struct Sub *sub = (struct Sub *)FUN_00023a00(item);
            if (sub != 0) {
                ret = sub->val;
            }
        }
    }
    return ret;
}
