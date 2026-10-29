/* Ad-hoc VS-history screen object (C++ only) and the value types shared by its 0x2ab000 sources. */
#ifndef HST_VSHISTORY_H
#define HST_VSHISTORY_H

/* Library string: capacity word (bit 0 set = heap buffer), length, heap pointer; 12 bytes. */
struct Str {
    unsigned cap;
    unsigned size;
    char *data;
    const char *c_str() const { return (cap & 1) ? data : (const char *)this + 1; }
};

/* Three-word helper container that belongs to a string pair. */
struct Rep {
    int a, b, c;
};

extern "C" {
Str *FUN_000031f0(Str *, const char *);
void FUN_00003e04(Str *, const Str *);
void FUN_00004138(Str *, int);
void FUN_00190880(Rep *, const Rep *);
void FUN_000462a0(Rep *, int);
}

/* A string plus its container (24 bytes), built from a literal and copied by the out-of-line helpers. */
struct StrPair {
    Str s;
    Rep r;
    StrPair(const char *lit)
    {
        FUN_000031f0(&s, lit);
        int *p = &r.a;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
    }
    ~StrPair()
    {
        FUN_000462a0(&r, -1);
        FUN_00004138(&s, 0);
    }
    StrPair &operator=(const StrPair &o)
    {
        FUN_00003e04(&s, &o.s);
        FUN_00190880(&r, &o.r);
        return *this;
    }
};

/* One row of a page's two-row table: how many items the row holds. */
struct CountRow {
    int count;
    int unk4[2];
};

/* Offset of the history list inside the global data block reached through DAT_003415a8. */
#define HISTORY_LIST_OFFSET 0x87128

enum HistoryMode {
    HMODE_INIT = 0,   /* nothing built yet */
    HMODE_PAGE1 = 1,
    HMODE_PAGE2 = 2,
    HMODE_PAGE3_A = 3, /* page 3 with its flag set */
    HMODE_PAGE3_B = 4  /* page 3 with its flag clear */
};

/* The four parts are completed by the sources that call their virtual methods. */
struct CommonPanel; /* always updated */
struct Page1;       /* shown in mode 1 */
struct Page2;       /* shown in mode 2 */
struct Page3;       /* shown in modes 3 and 4 */
struct HistoryEntry;

struct HistoryScreen {
    const void *vtbl;    /* 0x00 */
    char pad04[0x38];
    CommonPanel *common; /* 0x3c */
    Page1 *page1;        /* 0x40 */
    Page2 *page2;        /* 0x44 */
    Page3 *page3;        /* 0x48 */
    int mode;            /* 0x4c */
    int tab;             /* 0x50 selected tab, mode = tab + 1 */
    int sel;             /* 0x54 selection inside the page */
    unsigned char saving;     /* 0x58 */
    unsigned char entry_open; /* 0x59 */
    unsigned char top_focus;  /* 0x5a */
    StrPair text;        /* 0x5c */
    StrPair label;       /* 0x74 */
    HistoryEntry *entry; /* 0x8c */
    unsigned short name[150]; /* 0x90 */
    void SetSel(int v)
    {
        if (v != sel)
            sel = v;
    }
};

#endif
