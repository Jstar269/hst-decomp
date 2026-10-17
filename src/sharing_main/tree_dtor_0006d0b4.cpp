/* HSTMATCH module=hstp_trans_main.prx start=0x0006d0b4 end=0x0006d110 symbol=__dt__13Tree_0006d0b4Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_00066338.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_0006d0b4;
struct Tree_0006d0b4 {
    int header;
    Node_0006d0b4 *root;
    ~Tree_0006d0b4();
};
extern "C" void FUN_0006df1c(Tree_0006d0b4 *t, Node_0006d0b4 *x);
Tree_0006d0b4::~Tree_0006d0b4()
{
    if (root)
        FUN_0006df1c(this, root);
}
