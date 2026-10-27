/* HSTMATCH module=EBOOT.BIN start=0x00000f24 end=0x00000f74 symbol=FUN_00000f24 lang=c99 */
/* Hand-written reconstruction (port of src/sharing_main/destroy_global_chain_00000f24.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Runs the global-destructor chain that FUN_00000f74 builds (each record: next, destructor, object). */
typedef struct DestructorChain {
    struct DestructorChain *next;
    void (*destructor)(void *, int);
    void *object;
} DestructorChain;

extern DestructorChain *DAT_0030a03c;

void FUN_00000f24(void)
{
    DestructorChain *gdc;

    while ((gdc = DAT_0030a03c) != 0) {
        DAT_0030a03c = gdc->next;
        gdc->destructor(gdc->object, -1);
    }
}
