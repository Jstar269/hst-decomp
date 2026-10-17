/* HSTMATCH module=hstp_trans_main.prx start=0x0006cf54 end=0x0006cfb0 symbol=__dt__13Tree_0006cf54Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_00066338.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_0006cf54;
struct Tree_0006cf54 {
    int header;
    Node_0006cf54 *root;
    ~Tree_0006cf54();
};
extern "C" void FUN_0006dae8(Tree_0006cf54 *t, Node_0006cf54 *x);
Tree_0006cf54::~Tree_0006cf54()
{
    if (root)
        FUN_0006dae8(this, root);
}
