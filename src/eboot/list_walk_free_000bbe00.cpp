/* HSTMATCH module=EBOOT.BIN start=0x000bbe00 end=0x000bbf20 symbol=FUN_000bbe00 lang=c++ data=0x002d5320 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d5320-0x002d5366) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Member_000bbe00 {
    Member_000bbe00 *next;
    int data;
};
struct Self_000bbe00 {
    char pad0[0x16c];
    int matching_id;   /* 0x16c matching handle, -1 when closed */
};
extern "C" {
extern Member_000bbe00 *FUN_000104b0(int);
extern void FUN_000104e0(void *);
extern void FUN_000ba3ac(const char *, ...);
extern void FUN_000bb888(Self_000bbe00 *, void *, int, int, int);
extern int FUN_002b7de0(int, int *, void *);
}

/* Fetches the matching member list (size query, then allocate and fetch) and passes each member to FUN_000bb888; returns 1 on success. */
extern "C" int FUN_000bbe00(Self_000bbe00 *self)
{
    int buf_size = 0;
    int result;
    if (self->matching_id == -1) {
        result = 0;
    } else {
        int err = FUN_002b7de0(self->matching_id, &buf_size, 0);
        if (err < 0) {
            FUN_000ba3ac("sceNetAdhocMatchingGetMembers() failed. ret = %d\n", err);
            result = 0;
        } else {
            Member_000bbe00 *it;
            Member_000bbe00 *head = FUN_000104b0(buf_size);
            it = head;
            if (head == 0) {
                FUN_000ba3ac("malloc() failed.\n");
                result = 0;
            } else {
                err = FUN_002b7de0(self->matching_id, &buf_size, head);
                if (err < 0) {
                    FUN_000ba3ac("sceNetAdhocMatchingGetMembers() failed. ret = %d\n", err);
                    if (head) FUN_000104e0(head);
                    result = 0;
                } else {
                    for (; it != 0; it = it->next)
                        FUN_000bb888(self, &it->data, 0, 0, -1);
                    if (head) FUN_000104e0(head);
                    result = 1;
                }
            }
        }
    }
    return result;
}
