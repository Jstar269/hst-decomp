/* HSTMATCH module=hstp_trans_main.prx start=0x00000f24 end=0x00000f74 symbol=FUN_00000f24 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Runs the global-destructor chain that FUN_00000f74 builds (each record: next, destructor, object). */
typedef struct DestructorChain {
    struct DestructorChain *next;
    void (*destructor)(void *, int);
    void *object;
} DestructorChain;

extern DestructorChain *DAT_003b330c;

void FUN_00000f24(void)
{
    DestructorChain *gdc;

    while ((gdc = DAT_003b330c) != 0) {
        DAT_003b330c = gdc->next;
        gdc->destructor(gdc->object, -1);
    }
}
