/* HSTMATCH module=EBOOT.BIN start=0x002abe88 end=0x002acb2c symbol=FUN_002abe88 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the `saving` branch is an inline Save() helper (its unfilled `b; nop` tail), the duplicated close-out sequence is the inline CloseEntry(), the `entry_open` arm is wrapped as `if (DAT_00341771 == 0) {..} return;` (the trailing return puts MWCC's branch cleanup into the mode that keeps retail's dead delay-slot originals), the saved pad bit is read through an `int` getter into a `char` local (retail's seb), and the two Vec4 records are const& temporaries; StrPair is the same 24-byte string pair class as 0x2abb70; names and types await human review. */
#include "hst/vshistory.h"

struct Widget {
    virtual void m0();
    virtual void m1(bool);
    virtual void m2();
};

struct TextBox {
    char pad0[0xf8];
    char *ff8;
    char padfc[0x138 - 0xfc];
    int f138;
};

struct CommonPanel : Widget {
};

struct Menu : Widget {
    char pad4[0xdc - 4];
    int fdc;
};

struct Page1 : Widget {
    char pad4[0x170 - 4];
    TextBox *f170;
    TextBox *f174;
    Menu *f178;
    unsigned char f17c;
    char pad17d[0x77d - 0x17d];
    char f77d[0x80];
    char f7fd[0x87];
    int f884;
};

struct Page2 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    char pad4[0x358 - 4];
    Widget *f358;
    int pad35c;
    unsigned char f360;
    char pad361[0x1668 - 0x361];
    int f1668;
    int f166c;
};

struct Page3 : Widget {
    char pad4[0x30c4 - 4];
    bool side_flag;
    bool unk30c5;
    char pad30c6[0x30f0 - 0x30c6];
    CountRow rows[2]; /* 0x30f0 */
    bool NotFlag() { return !side_flag; }
};

struct EntryInfo {
    char pad0[0x1c];
    int f1c;
    void *f20;
    char pad24[0x2c - 0x24];
    int f2c;
    int f30;
};

struct HistoryEntry {
    char pad0[0x70];
    EntryInfo *p70;
};

struct Btn {
    signed char a : 2;
    signed char b : 2;
    signed char c : 2;
    signed char d : 2;
    int C() const { return c; }
};

struct Pad {
    char pad0[0x88];
    Btn k88;
    Btn k89;
    Btn k8a;
    Btn k8b;
};

struct Glob {
    char pad0[0xc];
    int fc;
    char pad10[0x52 - 0x10];
    unsigned char f52;
};

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};

extern "C" {
extern Pad *DAT_002cfc8c;
extern int DAT_00300af4[];
extern char DAT_00302c50[];
extern Glob *DAT_00331b84;
extern char DAT_0034179c[];
extern char *DAT_003415a8;
extern void *DAT_003415ac;
extern unsigned char DAT_00341771;
extern char DAT_0034a678[];
extern void *DAT_0034b354;
StrPair FUN_00045730(const unsigned short *);
int FUN_0004577c(StrPair *);
void FUN_00011090(unsigned short *, int, int);
void FUN_000143b0(char *, const char *, const char *);
void FUN_00014a40(const char *);
void FUN_00063830(float, float, Glob *, const Vec4 &, const Vec4 &, int, int, int);
void FUN_00103628(void *, int);
void FUN_0010b8cc(Widget *, int, int);
void FUN_0010d4a8(TextBox *);
void FUN_00110a78(void *, const char *, int);
void FUN_00114168(void *, int, const char *, int, int);
int FUN_001155c0(void *);
int FUN_001156d4(void *);
void FUN_00199244(HistoryEntry *);
void FUN_001b1c44(char *, int);
void FUN_001b3e2c(char *);
const char *FUN_001fea10(int, int, int);
void FUN_0023466c(char *);
void FUN_002a51ec(const char *, char *, char *);
void FUN_002a57ec(CommonPanel *, int, int);
void FUN_002a5e3c(Page1 *, int);
void FUN_002a7218(Page2 *, int);
void FUN_002a9114(Page3 *, int, int);
void FUN_002a9370(Page3 *, bool, int);
void FUN_002ab8fc(HistoryScreen *, int);
void FUN_002abb70(HistoryScreen *, int);
const char *FUN_002af0d4(char *);
void FUN_002af224(char *, const char *);
int FUN_002af274(char *);
void FUN_002af29c(char *, int);
}

static inline void CloseEntry(HistoryScreen *self)
{
    self->entry_open = 0;
    Page1 *page = self->page1;
    page->f178->m1(0);
    page->f17c = 1;
    int choice = page->f178->fdc;
    FUN_0010b8cc(page->f178, choice, 0);
    if (DAT_0034b354 != 0)
        FUN_00110a78(DAT_0034b354, FUN_001fea10(18, 49, DAT_00300af4[choice]), 0);
}

static inline void Save(HistoryScreen *self)
{
    if (FUN_001155c0(DAT_003415ac) == 0)
        return;
    FUN_00103628(DAT_003415ac, 1);
    if (FUN_001156d4(DAT_003415ac) == 0) {
        Page2 *page = self->page2;
        FUN_002af29c(DAT_003415a8 + HISTORY_LIST_OFFSET, page->f1668 + page->f166c);
        page->m1();
    }
    self->saving = 0;
    Page2 *page = self->page2;
    bool ok = 0 < FUN_002af274(DAT_003415a8 + HISTORY_LIST_OFFSET);
    page->f358->m1(!ok);
    page->f360 = 1;
}

extern "C" void FUN_002abe88(HistoryScreen *self)
{
    int cur = self->tab;
    if (self->saving != 0) {
        Save(self);
        return;
    }
    if (self->entry_open != 0) {
        if (DAT_00341771 == 0) {
            if (self->entry->p70->f2c != 2) {
                CloseEntry(self);
            } else {
                char buf[256];
                self->text = FUN_00045730(self->name);
                FUN_000143b0(buf, DAT_00302c50, self->text.s.c_str());
                FUN_00014a40(self->text.s.c_str());
                self->text = StrPair(buf);
                const char *name = self->text.s.c_str();
                Page1 *page = self->page1;
                FUN_002af224(DAT_003415a8 + HISTORY_LIST_OFFSET, name);
                FUN_002a51ec(name, page->f77d, page->f7fd);
                TextBox *box = page->f170;
                box->ff8 = page->f77d;
                box->f138 = 1;
                FUN_0010d4a8(box);
                box = page->f174;
                box->ff8 = page->f7fd;
                box->f138 = 1;
                FUN_0010d4a8(box);
                CloseEntry(self);
            }
            Glob *g = DAT_00331b84;
            g->fc = 0;
            g->f52 = 0;
            FUN_00103628(DAT_0034b354, 0);
        }
        return;
    }
    if (DAT_002cfc8c->k88.a != 0) {
        char cancel = DAT_002cfc8c->k8b.C();
        if (cancel == 0 && !(self->mode == HMODE_PAGE2 && self->sel == 1) && !(self->mode == HMODE_PAGE3_A && self->page3->unk30c5 != 0)
            && !(self->mode == HMODE_PAGE3_B && self->page3->unk30c5 != 0)) {
            if (self->top_focus != 0) {
                FUN_001b3e2c(DAT_0034179c);
                FUN_001b1c44(DAT_0034179c, 4);
                FUN_0023466c(DAT_0034a678);
            } else {
                FUN_002ab8fc(self, 1);
                FUN_001b1c44(DAT_0034179c, 4);
            }
        } else if (DAT_002cfc8c->k8a.a == 0 && self->mode != HMODE_INIT) {
            self->tab = (cur + 3) % 4;
        } else if (DAT_002cfc8c->k8a.b == 0 && self->mode != HMODE_INIT) {
            self->tab = (cur + 1) % 4;
        } else if (self->top_focus != 0) {
            if (DAT_002cfc8c->k89.d == 0 && self->mode != HMODE_INIT) {
                self->tab = (cur + 3) % 4;
            } else if (DAT_002cfc8c->k89.b == 0 && self->mode != HMODE_INIT) {
                self->tab = (cur + 1) % 4;
            } else if (DAT_002cfc8c->k8b.b == 0) {
                if ((self->mode != HMODE_PAGE2 || FUN_002af274(DAT_003415a8 + HISTORY_LIST_OFFSET) > 0)
                    && (self->mode != HMODE_PAGE3_A || self->page3->rows[self->page3->NotFlag()].count > 0)
                           && (self->mode != HMODE_PAGE3_B || self->page3->rows[self->page3->NotFlag()].count > 0)) {
                    FUN_002ab8fc(self, 0);
                    FUN_001b1c44(DAT_0034179c, 3);
                }
            }
        } else {
            switch (self->mode) {
            case HMODE_PAGE1:
                if (DAT_002cfc8c->k8b.a == 0) {
                    self->SetSel((self->sel + 1) % 2);
                    FUN_002a5e3c(self->page1, self->sel);
                    FUN_001b1c44(DAT_0034179c, 6);
                } else if (DAT_002cfc8c->k8b.b == 0 && self->entry_open == 0 && self->page1->f884 == 13) {
                    self->text = StrPair(FUN_002af0d4(DAT_003415a8 + HISTORY_LIST_OFFSET));
                    FUN_00011090(self->name, FUN_0004577c(&self->text), 150);
                    self->label = StrPair(FUN_001fea10(17, 13, 3));
                    self->entry->p70->f1c = FUN_0004577c(&self->label);
                    self->entry->p70->f20 = self->name;
                    FUN_00199244(self->entry);
                    self->entry->p70->f30 = 24;
                    Page1 *page = self->page1;
                    page->f178->m1(1);
                    page->f17c = 0;
                    self->entry_open = 1;
                    FUN_001b1c44(DAT_0034179c, 3);
                    FUN_00063830(65535.0f, -1.0f, DAT_00331b84, Vec4(0.0f, 0.0f, 0.0f, 0.0f), Vec4(0.0f, 0.0f, 0.0f, 0.75f), 1, 0, 0);
                    FUN_00103628(DAT_0034b354, 1);
                }
                break;
            case HMODE_PAGE2:
                if (FUN_002af274(DAT_003415a8 + HISTORY_LIST_OFFSET) > 0) {
                    if (DAT_002cfc8c->k8b.b == 0) {
                        if (self->sel == 0) {
                            self->SetSel(1);
                            FUN_002a7218(self->page2, self->sel);
                            FUN_002a57ec(self->common, self->mode - 1, self->sel);
                            FUN_001b1c44(DAT_0034179c, 3);
                        }
                    } else if (DAT_002cfc8c->k8b.c == 0) {
                        if (self->sel == 1) {
                            self->SetSel(0);
                            FUN_002a7218(self->page2, self->sel);
                            FUN_002a57ec(self->common, self->mode - 1, self->sel);
                            FUN_001b1c44(DAT_0034179c, 4);
                        }
                    } else if (DAT_002cfc8c->k8b.d == 0 && self->sel == 0) {
                        FUN_00114168(DAT_003415ac, 1, FUN_001fea10(17, 19, 0), 0, 0);
                        self->saving = 1;
                        Page2 *page = self->page2;
                        page->f358->m1(1);
                        page->f360 = 0;
                        FUN_001b1c44(DAT_0034179c, 3);
                    }
                }
                break;
            case HMODE_PAGE3_A:
            case HMODE_PAGE3_B:
                if (self->page3->rows[self->page3->NotFlag()].count > 0) {
                    if (DAT_002cfc8c->k8b.a == 0) {
                        self->SetSel((self->sel + 1) % 3);
                        FUN_002a9114(self->page3, self->sel, 0);
                        FUN_002a9370(self->page3, self->page3->unk30c5, 1);
                        FUN_001b1c44(DAT_0034179c, 6);
                    } else if (cancel == 0) {
                        FUN_002a9370(self->page3, 0, 1);
                        FUN_002a57ec(self->common, self->mode - 1, self->page3->unk30c5);
                        FUN_002ab8fc(self, 1);
                        FUN_001b1c44(DAT_0034179c, 4);
                    } else if (DAT_002cfc8c->k8b.d == 0) {
                        FUN_002a9370(self->page3, !self->page3->unk30c5, 1);
                        FUN_002a57ec(self->common, self->mode - 1, self->page3->unk30c5);
                        FUN_001b1c44(DAT_0034179c, 1);
                    }
                }
                break;
            }
        }
    }
    if (cur != self->tab) {
        FUN_002abb70(self, self->tab + 1);
        FUN_002ab8fc(self, 1);
        FUN_001b1c44(DAT_0034179c, 6);
    }
    self->common->m2();
    switch (self->mode) {
    case HMODE_PAGE1:
        self->page1->m2();
        break;
    case HMODE_PAGE2:
        self->page2->m2();
        break;
    case HMODE_PAGE3_A:
        self->page3->m2();
        break;
    case HMODE_PAGE3_B:
        self->page3->m2();
        break;
    }
}
