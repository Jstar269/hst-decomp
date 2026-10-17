/* HSTMATCH module=hstp_trans_main.prx start=0x00158124 end=0x00158268 symbol=FUN_00158124 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0c) corrected by hand: C++ struct with SubList::end() and SubList::insert(), and null-checked allocation before reading stream header; exact match verified; names and types await human review. */
struct Stream {
    virtual void *v0(char **);
};

extern "C" {
extern char *FUN_00000a90(unsigned);
extern void *FUN_00000bcc(unsigned);
extern void FUN_00014b74(char *, const char *, int);
extern int FUN_0015b03c(char **);
extern void FUN_0015b228(void *, void *, int *, void **);
extern void *FUN_0015b314(void *);
}

struct SubList {
    int f0;
    int f4;
    int *end() { return &f4; }
    void insert(void **val) {
        int auStack_c;
        int *local_10 = end();
        FUN_0015b228(&auStack_c, this, (int *)&local_10, val);
    }
};

struct Node {
    SubList list;
    int f8;
    char *fc;
};

extern "C" Node *FUN_00158124(Stream *param_1, char **param_2)
{
    char *local_4;
    void *local_8;

    char *end = *param_2;
    local_4 = end;
    Node *node;
    if ((node = (Node *)FUN_00000bcc(0x10)) != 0) {
        char *start = local_4;
        FUN_0015b314(node);
        int len = 0x10;
        for (char *p = start; p < start + 0x10; p++) {
            if (*p == '\0') {
                len = p - start;
                break;
            }
        }
        node->fc = FUN_00000a90(len + 1);
        FUN_00014b74(node->fc, start, len);
        node->fc[len] = '\0';
    }
    local_4 += 0x10;
    end += FUN_0015b03c(&local_4);
    while (local_4 < end) {
        local_8 = param_1->v0(&local_4);
        if (local_8 != 0) {
            node->list.insert(&local_8);
        }
    }
    *param_2 = local_4;
    return node;
}
