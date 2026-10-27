/* HSTMATCH module=hstp_trans_main.prx start=0x0018593c end=0x00185a08 symbol=FUN_0018593c lang=c++ rodata=0x002d2470 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* chr_manager.cpp (file name and the m_pGearIdxList member name from the assert strings): returns the first word of the
   idx-th entry of the list selected by kind. Six labels 0..5 (case 0 shares the default body) give the retail jump table
   at 0x002d2470; without the explicit case 0 MWCC emits a compare chain. Debug build: the m_pGearIdxList assertion is kept. */
extern "C" void FUN_00177f38(...);
extern const char DAT_00387a88[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_00387c04[];   /* "m_pGearIdxList" */
extern const char DAT_00387ac4[];   /* "chr_manager.cpp" */
#define HST_ASSERT(cond, text, file, line) do { if (!(cond)) { FUN_00177f38(DAT_00387a88, text, file, line); for (;;) {} } } while (0)

struct Item {
    int id;
};

struct List {
    Item **data;
    int size;
    int cap;
    int pad[3];
};

struct ChrManager {
    char pad0[0x1d4];
    List *m_pGearIdxList;   /* 0x1d4 */
    List list1d8;           /* 0x1d8 */
    List list1f0;           /* 0x1f0 */
    List list208;           /* 0x208 */
};

extern "C" int FUN_0018593c(ChrManager *self, int kind, int idx)
{
    int r;
    switch (kind) {
    case 1:
        r = self->list1d8.data[idx]->id;
        break;
    case 2:
        r = self->list1f0.data[idx]->id;
        break;
    case 3:
    case 4:
        r = self->list208.data[idx]->id;
        break;
    case 5:
        HST_ASSERT(self->m_pGearIdxList, DAT_00387c04, DAT_00387ac4, 7737);
        r = self->m_pGearIdxList->data[idx]->id;
        break;
    case 0:
    default:
        r = 0;
        break;
    }
    return r;
}
