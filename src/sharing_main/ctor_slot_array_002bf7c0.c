/* HSTMATCH module=hstp_trans_main.prx start=0x002bf7c0 end=0x002bf8fc symbol=FUN_002bf7c0 lang=c99 */
/* Clone of src/eboot/ctor_slot_array_002afd70.c (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_0001ec44(void *p);
extern void FUN_0010873c(void *p);
extern void FUN_000007f4(void *p, void *ctor, void *dtor, int size, int n);
extern void LAB_002bf954(void);
extern void FUN_002bf8fc(void);
extern void FUN_0022664c(void *p);
extern void FUN_0001ef34(void *a, void *self);
extern void FUN_002c34f4(void *p, int n);
extern void FUN_002c28fc(void *self);
extern void *FUN_00000bcc(int n);
extern void *FUN_0022e66c(void *p);
extern char DAT_003b3264[];
extern char DAT_003b3280[];

char *FUN_002bf7c0(char *self, void *param_2)
{
    FUN_0001ec44(self);
    FUN_0010873c(self + 0x3c);
    *(void **)self = DAT_003b3264;
    *(void **)(self + 0x3c) = DAT_003b3280;
    FUN_000007f4(self + 0x98, (void *)LAB_002bf954, (void *)FUN_002bf8fc, 12, 10);
    FUN_0022664c(self + 0x41c);
    *(char *)(self + 0x168) = 0;
    *(char *)(self + 0x90) = 0;
    *(char *)(self + 0x169) = 0;
    *(char *)(self + 0x38a) = 0;
    *(int *)(self + 0x400) = 0;
    *(int *)(self + 0x40c) = 0;
    *(int *)(self + 0x410) = 0;
    *(char *)(self + 0x414) = 0;
    *(int *)(self + 0x418) = 0;
    *(int *)(self + 0x38c) = 0;
    *(char *)(self + 0x408) = 0;
    *(int *)(self + 0x3f8) = -1;
    FUN_0001ef34(param_2, self);
    int i = 0;
    int off12 = 0;
    int off4 = 0;
    do {
        if (*(unsigned int *)(self + off12 + 0xa0) < 20)
            FUN_002c34f4(self + off12 + 0x98, 20);
        *(int *)(self + off4 + 0x3a8) = 0;
        *(int *)(self + off4 + 0x3d0) = 0;
        i++;
        off12 += 12;
        off4 += 4;
    } while (i < 10);
    FUN_002c28fc(self);
    void *p = FUN_00000bcc(0x74);
    if (p != 0)
        *(void **)(self + 0x4a8) = FUN_0022e66c(p);
    else
        *(void **)(self + 0x4a8) = p;
    return self;
}
