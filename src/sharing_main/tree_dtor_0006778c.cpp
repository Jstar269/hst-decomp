/* HSTMATCH module=hstp_trans_main.prx start=0x0006778c end=0x000677e8 symbol=__dt__13Tree_0006778cFv lang=c++ */
/* Clone of src/eboot/tree_dtor_00066338.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_0006778c;
struct Tree_0006778c {
    int header;
    Node_0006778c *root;
    ~Tree_0006778c();
};
extern "C" void FUN_0006811c(Tree_0006778c *t, Node_0006778c *x);
Tree_0006778c::~Tree_0006778c()
{
    if (root)
        FUN_0006811c(this, root);
}
