/* HSTMATCH module=EBOOT.BIN start=0x0006bc0c end=0x0006bc68 symbol=__dt__13Tree_0006bc0cFv lang=c++ */
/* Clone of src/eboot/tree_dtor_000d5ca8.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_0006bc0c;
struct Tree_0006bc0c {
    int header;
    Node_0006bc0c *root;
    ~Tree_0006bc0c();
};
extern "C" void FUN_0006cf1c(Tree_0006bc0c *t, Node_0006bc0c *x);
Tree_0006bc0c::~Tree_0006bc0c()
{
    if (root)
        FUN_0006cf1c(this, root);
}
