/* HSTMATCH module=hstp_trans_main.prx start=0x0028b678 end=0x0028b7b8 symbol=FUN_0028b678 lang=c++ */
/* Clone of src/eboot/list_insert_0027a394.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the sibling list insert src/eboot/list_insert_vertex_00289544.cpp: 56-byte node with a 48-byte payload of three plain Vec4 members copied in lwc1/swc1 batches of four, allocation-failure message printed through 0xf3e8); exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned size);
struct Reent_0028b678 { int pad[3]; void *err; };
Reent_0028b678 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_00000a00(void *);
extern char DAT_002dafc4[];
}
inline void *operator new(unsigned, void *p) { return p; }
struct Vec4_0028b678 { float x, y, z, w; };
struct Mat34_0028b678 { Vec4_0028b678 a, b, c; };
struct Node_0028b678 { Node_0028b678 *next; Node_0028b678 *prev; Mat34_0028b678 v; };
struct Guard_0028b678 { int *p; Node_0028b678 *n; ~Guard_0028b678() { if (n) FUN_00000a00(n); } };
extern "C" int FUN_0028b678(Node_0028b678 **out, int *count, Node_0028b678 **head, const Mat34_0028b678 *src)
{
    int *cp = count + 1;
    Node_0028b678 *n = (Node_0028b678 *)FUN_00000bcc(0x38);
    if (n == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dafc4);
        FUN_0000d530();
    }
    Guard_0028b678 g;
    g.p = cp;
    g.n = n;
    new (&n->v) Mat34_0028b678(*src);
    g.n = 0;
    Node_0028b678 *h = *head;
    h->next->prev = n;
    n->next = h->next;
    h->next = n;
    n->prev = h;
    *count = *count + 1;
    *out = n;
    return 0;
}
