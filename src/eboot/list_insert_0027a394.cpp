/* HSTMATCH module=EBOOT.BIN start=0x0027a394 end=0x0027a4d4 symbol=FUN_0027a394 lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the sibling list insert src/eboot/list_insert_vertex_00289544.cpp: 56-byte node with a 48-byte payload of three plain Vec4 members copied in lwc1/swc1 batches of four, allocation-failure message printed through 0xf3e8); exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned size);
struct Reent_0027a394 { int pad[3]; void *err; };
Reent_0027a394 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_00000a00(void *);
extern char DAT_002caa04[];
}
inline void *operator new(unsigned, void *p) { return p; }
struct Vec4_0027a394 { float x, y, z, w; };
struct Mat34_0027a394 { Vec4_0027a394 a, b, c; };
struct Node_0027a394 { Node_0027a394 *next; Node_0027a394 *prev; Mat34_0027a394 v; };
struct Guard_0027a394 { int *p; Node_0027a394 *n; ~Guard_0027a394() { if (n) FUN_00000a00(n); } };
extern "C" int FUN_0027a394(Node_0027a394 **out, int *count, Node_0027a394 **head, const Mat34_0027a394 *src)
{
    int *cp = count + 1;
    Node_0027a394 *n = (Node_0027a394 *)FUN_00000bcc(0x38);
    if (n == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002caa04);
        FUN_0000d518();
    }
    Guard_0027a394 g;
    g.p = cp;
    g.n = n;
    new (&n->v) Mat34_0027a394(*src);
    g.n = 0;
    Node_0027a394 *h = *head;
    h->next->prev = n;
    n->next = h->next;
    h->next = n;
    n->prev = h;
    *count = *count + 1;
    *out = n;
    return 0;
}
