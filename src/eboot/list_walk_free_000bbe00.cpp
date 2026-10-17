/* HSTMATCH module=EBOOT.BIN start=0x000bbe00 end=0x000bbf20 symbol=FUN_000bbe00 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node_000bbe00 {
    Node_000bbe00 *next;
    int data;
};
struct Self_000bbe00 {
    char pad0[0x16c];
    int f16c;
};
extern "C" {
extern char DAT_002d5320[];
extern char DAT_002d5354[];
extern Node_000bbe00 *FUN_000104b0(int);
extern void FUN_000104e0(void *);
extern void FUN_000ba3ac(const char *, ...);
extern void FUN_000bb888(Self_000bbe00 *, void *, int, int, int);
extern int FUN_002b7de0(int, int *, void *);
}

extern "C" int FUN_000bbe00(Self_000bbe00 *s)
{
    int local_4 = 0;
    int r;
    if (s->f16c == -1) {
        r = 0;
    } else {
        int e = FUN_002b7de0(s->f16c, &local_4, 0);
        if (e < 0) {
            FUN_000ba3ac(DAT_002d5320, e);
            r = 0;
        } else {
            Node_000bbe00 *it;
            Node_000bbe00 *head = FUN_000104b0(local_4);
            it = head;
            if (head == 0) {
                FUN_000ba3ac(DAT_002d5354);
                r = 0;
            } else {
                e = FUN_002b7de0(s->f16c, &local_4, head);
                if (e < 0) {
                    FUN_000ba3ac(DAT_002d5320, e);
                    if (head) FUN_000104e0(head);
                    r = 0;
                } else {
                    for (; it != 0; it = it->next)
                        FUN_000bb888(s, &it->data, 0, 0, -1);
                    if (head) FUN_000104e0(head);
                    r = 1;
                }
            }
        }
    }
    return r;
}
