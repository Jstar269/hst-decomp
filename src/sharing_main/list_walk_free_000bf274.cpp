/* HSTMATCH module=hstp_trans_main.prx start=0x000bf274 end=0x000bf394 symbol=FUN_000bf274 lang=c++ */
/* Clone of src/eboot/list_walk_free_000bbe00.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node_000bf274 {
    Node_000bf274 *next;
    int data;
};
struct Self_000bf274 {
    char pad0[0x16c];
    int f16c;
};
extern "C" {
extern char DAT_0037bc2c[];
extern char DAT_0037bc60[];
extern Node_000bf274 *FUN_000104b0(int);
extern void FUN_000104e0(void *);
extern void FUN_000bd6f0(const char *, ...);
extern void FUN_000becfc(Self_000bf274 *, void *, int, int, int);
extern int FUN_002c7b68(int, int *, void *);
}

extern "C" int FUN_000bf274(Self_000bf274 *s)
{
    int local_4 = 0;
    int r;
    if (s->f16c == -1) {
        r = 0;
    } else {
        int e = FUN_002c7b68(s->f16c, &local_4, 0);
        if (e < 0) {
            FUN_000bd6f0(DAT_0037bc2c, e);
            r = 0;
        } else {
            Node_000bf274 *it;
            Node_000bf274 *head = FUN_000104b0(local_4);
            it = head;
            if (head == 0) {
                FUN_000bd6f0(DAT_0037bc60);
                r = 0;
            } else {
                e = FUN_002c7b68(s->f16c, &local_4, head);
                if (e < 0) {
                    FUN_000bd6f0(DAT_0037bc2c, e);
                    if (head) FUN_000104e0(head);
                    r = 0;
                } else {
                    for (; it != 0; it = it->next)
                        FUN_000becfc(s, &it->data, 0, 0, -1);
                    if (head) FUN_000104e0(head);
                    r = 1;
                }
            }
        }
    }
    return r;
}
