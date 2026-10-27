/* HSTMATCH module=EBOOT.BIN start=0x0006b384 end=0x0006b480 symbol=FUN_0006b384 lang=c++ */
/* Clone of src/sharing_main/list_insert_0006c96c.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the sibling list insert src/sharing_main/list_insert_0028b678.cpp: 192-byte node whose 16-aligned 176-byte payload is built through the out-of-line placement new FUN_00002f60 and the out-of-line copy constructor FUN_0006b480, so the guard node is re-read after those calls); exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned size);
struct Reent_0006b384 { int pad[3]; void *err; };
Reent_0006b384 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_00000a00(void *);
void *FUN_00002f60(unsigned size, void *p);
void *FUN_0006b480(void *dst, const void *src);
extern char DAT_002bc6f8[];
}
struct Value_0006b384 { char b[176]; } __attribute__((aligned(16)));
struct Node_0006b384 { Node_0006b384 *next; Node_0006b384 *prev; Value_0006b384 v; };
struct Guard_0006b384 { int *p; Node_0006b384 *n; ~Guard_0006b384() { if (n) FUN_00000a00(n); } };
extern "C" int FUN_0006b384(Node_0006b384 **out, int *count, Node_0006b384 **head, const Value_0006b384 *src)
{
    int *cp = count + 1;
    Node_0006b384 *n = (Node_0006b384 *)FUN_00000bcc(0xc0);
    if (n == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc6f8);
        FUN_0000d518();
    }
    Guard_0006b384 g;
    g.p = cp;
    g.n = n;
    void *q = FUN_00002f60(sizeof(Value_0006b384), &n->v);
    if (q != 0)
        FUN_0006b480(q, src);
    Node_0006b384 *m = g.n;
    g.n = 0;
    Node_0006b384 *h = *head;
    h->next->prev = m;
    m->next = h->next;
    h->next = m;
    m->prev = h;
    *count = *count + 1;
    *out = m;
    return 0;
}
