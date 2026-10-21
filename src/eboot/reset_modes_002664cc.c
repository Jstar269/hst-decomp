/* HSTMATCH module=EBOOT.BIN start=0x002664cc end=0x002665dc symbol=FUN_002664cc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00057b58(void *p, int a1, int a2, float f);
extern void FUN_00058ddc(void *p, int a1, int a2);
extern void FUN_00058f38(void *p, int a1, float f);
extern void FUN_0005f110(void *p, float f);
extern void FUN_00059084(void *p, int a1);

static inline void ModeA_002664cc(void *p, int x)
{
    FUN_00057b58(p, 0, x, 0.0f);
}

static inline void ModeB_002664cc(void *p, int y)
{
    FUN_00058ddc(p, y, -1);
    *(char *)((char *)p + 0xc0) = (char)y;
}

static inline void ModeC_002664cc(void *p)
{
    FUN_00058f38(p, -1, 0.0f);
    FUN_0005f110(p, 0.0f);
}

static inline void ModeD_002664cc(void *p)
{
    FUN_00059084(p, -1);
    *(float *)((char *)p + 0xd0) = *(float *)((char *)p + 0xc4);
}

void FUN_002664cc(char *self, int x, int y)
{
    ModeA_002664cc(*(void **)(self + 0x70), x);
    ModeB_002664cc(*(void **)(self + 0x70), y);
    ModeC_002664cc(*(void **)(self + 0x70));
    ModeD_002664cc(*(void **)(self + 0x70));
    if (*(void **)(self + 0x74) == 0)
        return;
    ModeA_002664cc(*(void **)(self + 0x74), x);
    ModeB_002664cc(*(void **)(self + 0x74), y);
    ModeC_002664cc(*(void **)(self + 0x74));
    ModeD_002664cc(*(void **)(self + 0x74));
}
