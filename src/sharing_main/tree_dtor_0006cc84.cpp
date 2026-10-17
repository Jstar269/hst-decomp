/* HSTMATCH module=hstp_trans_main.prx start=0x0006cc84 end=0x0006cce0 symbol=__dt__13Tree_0006cc84Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_00066338.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_0006cc84;
struct Tree_0006cc84 {
    int header;
    Node_0006cc84 *root;
    ~Tree_0006cc84();
};
extern "C" void FUN_0006d754(Tree_0006cc84 *t, Node_0006cc84 *x);
Tree_0006cc84::~Tree_0006cc84()
{
    if (root)
        FUN_0006d754(this, root);
}
