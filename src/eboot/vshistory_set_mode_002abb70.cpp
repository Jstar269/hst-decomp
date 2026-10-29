/* HSTMATCH module=EBOOT.BIN start=0x002abb70 end=0x002abe70 symbol=FUN_002abb70 lang=c++ data=0x00302c1c */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: a switch over the mode (cases 3 and 4 share one body, MWCC tests 4,3,2,1,0 in reverse label order) whose case 0 assigns a temporary StrPair (String + 12-byte container; inline ctor/dtor/operator= calling the out-of-line helpers, same class as 0x22d848) to the member; the two menu strings are anonymous .data placed with data=0x00302c1c and the empty-string argument is the pooled DAT_00300a90; `bool NotFlag() { return !f30c4; }` gives the sltu/xori/andi index; names and types await human review. */
#include "hst/vshistory.h"

struct CommonPanel {
    virtual void m0();
    virtual void m1();
};
struct Page1 {
    virtual void m0();
    virtual void m1();
};
struct Page2 {
    virtual void m0();
    virtual void m1();
};
struct TargetInfo {
    char pad[0xd8];
    int fd8; /* 0xd8 */
    int fdc; /* 0xdc */
};
struct Page3 {
    virtual void m0();
    virtual void m1();
    char pad4[0x1038 - 4];
    TargetInfo *target; /* 0x1038 */
    char pad103c[0x30c0 - 0x103c];
    int unk30c0;
    bool side_flag;     /* 0x30c4 */
    char pad30c5[3];
    int unk30c8;
    int unk30cc;
    int unk30d0;
    char pad30d4[0x30f0 - 0x30d4];
    CountRow rows[2];   /* 0x30f0 */
    bool NotFlag() { return !side_flag; }
};

extern "C" {
extern char DAT_00300a90;
extern char DAT_0030ebf4[];
extern char DAT_0030ab9c[];
extern char DAT_0034179c[];
void FUN_002abe70(HistoryScreen *, int);
void FUN_002a7218(Page2 *, int);
void FUN_002a5e3c(Page1 *, int);
void FUN_0001cad0(char *, int, const char *);
void *FUN_00000bcc(unsigned);
CommonPanel *FUN_002a5370(void *);
Page1 *FUN_002a5a04(void *);
Page2 *FUN_002a6b68(void *);
Page3 *FUN_002a8694(void *);
void FUN_0001cb88(char *);
int FUN_00010184(int, int);
void FUN_0001bfb4(char *, int, int);
void FUN_0001ca58(char *, const char *);
void FUN_001b3378(char *, int);
int FUN_0001cbfc();
int FUN_0001cc54();
void FUN_000104e0(int);
void FUN_001b3ce8(char *, int);
void FUN_002ab8fc(HistoryScreen *, int);
void FUN_002a9114(Page3 *, int, int);
void FUN_002a9370(Page3 *, int, int);
}

#define SCRATCH_SIZE 0x100000
#define SCRATCH_ALIGN 0x40

/* Switch the screen to `mode`: mode 0 builds the four parts and loads the screen's sound banks;
   modes 1-4 reset the page that will be shown. */
extern "C" void FUN_002abb70(HistoryScreen *self, int mode)
{
    if (mode != self->mode) {
        self->mode = mode;
        FUN_002abe70(self, 0);
        switch (mode) {
        case HMODE_INIT: {
            self->tab = 0;
            self->saving = 0;
            self->entry_open = 0;
            self->text = StrPair(&DAT_00300a90);
            FUN_0001cad0(DAT_0030ebf4, 1, "menu/adhoc_vshistory.xb");
            CommonPanel *common = (CommonPanel *)FUN_00000bcc(236);
            if (common)
                common = FUN_002a5370(common);
            self->common = common;
            Page1 *page1 = (Page1 *)FUN_00000bcc(5892);
            if (page1)
                page1 = FUN_002a5a04(page1);
            self->page1 = page1;
            Page2 *page2 = (Page2 *)FUN_00000bcc(5780);
            if (page2)
                page2 = FUN_002a6b68(page2);
            self->page2 = page2;
            Page3 *page3 = (Page3 *)FUN_00000bcc(12600);
            if (page3)
                page3 = FUN_002a8694(page3);
            self->page3 = page3;
            FUN_0001cb88(DAT_0030ebf4);
            int scratch = FUN_00010184(SCRATCH_ALIGN, SCRATCH_SIZE);
            FUN_0001bfb4(DAT_0030ab9c, scratch, SCRATCH_SIZE);
            FUN_0001ca58(DAT_0030ebf4, "menu/adhoc_vshistory_bgm.xb");
            FUN_001b3378(DAT_0034179c, 4);
            FUN_0001cb88(DAT_0030ebf4);
            int cur_buf = FUN_0001cbfc();
            int cur_size = FUN_0001cc54();
            FUN_0001bfb4(DAT_0030ab9c, cur_buf, cur_size);
            FUN_000104e0(scratch);
            FUN_001b3ce8(DAT_0034179c, 4);
            self->common->m1();
            self->page1->m1();
            self->page2->m1();
            self->page3->m1();
            FUN_002ab8fc(self, 1);
            break;
        }
        case HMODE_PAGE1:
            FUN_002a5e3c(self->page1, 0);
            break;
        case HMODE_PAGE2:
            FUN_002a7218(self->page2, 0);
            break;
        case HMODE_PAGE3_A:
        case HMODE_PAGE3_B: {
            Page3 *page = self->page3;
            page->side_flag = (mode == HMODE_PAGE3_A);
            page->unk30c8 = 0;
            page->unk30cc = 0;
            int count = page->rows[page->NotFlag()].count;
            page->unk30d0 = count;
            TargetInfo *target = page->target;
            target->fd8 = count;
            target->fdc = 5;
            FUN_002a9114(page, page->unk30c0, 0);
            FUN_002a9114(self->page3, 0, 0);
            FUN_002a9370(self->page3, 0, 1);
            break;
        }
        }
    }
}
