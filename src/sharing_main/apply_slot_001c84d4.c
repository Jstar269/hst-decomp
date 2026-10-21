/* HSTMATCH module=hstp_trans_main.prx start=0x001c84d4 end=0x001c85f0 symbol=FUN_001c84d4 lang=c99 */
/* Clone of src/eboot/apply_slot_001ba78c.c (hstclone.py tag c22rt2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_001773a0(int id);
extern char *FUN_0017759c(int id, int prev);
extern int FUN_00177360(int id);
extern unsigned char FUN_001c8cc8(void *model);
extern int FUN_00212dd8(int id);
extern void FUN_0021465c(void *slot, unsigned char mode, int *rect, int a, int b, int c, int d);

void FUN_001c84d4(char *self, int *handle)
{
    char *p = *(char **)handle + 0x30;
    if (*(unsigned char *)p == 0)
        return;
    int id = *(short *)(*(int *)(p + 4));
    char *cfg = FUN_0017759c(id, FUN_001773a0(id));
    int rect[6] = {0};
    rect[0] = id;
    int *src = *(int **)(*(char **)handle + 0x34);
    rect[1] = *(short *)((char *)src + 2);
    rect[2] = *(short *)((char *)src + 4);
    rect[3] = *(short *)((char *)src + 6);
    rect[4] = *(short *)((char *)src + 8);
    rect[5] = FUN_00177360(id);
    unsigned char mode = FUN_001c8cc8(*(void **)(*(int *)(*(int *)(self + 4) + 4) + 4));
    void **slot = (void **)(*(char **)(self + 4) + 4);
    int v = FUN_00212dd8(rect[0]);
    FUN_0021465c(*slot, mode, rect, *(unsigned char *)(cfg + 8) != 0,
                 *(unsigned char *)(cfg + 9) != 0, *(unsigned char *)(cfg + 10) != 0, v);
    self[0x11] = 1;
    self[0x15] = 1;
}
