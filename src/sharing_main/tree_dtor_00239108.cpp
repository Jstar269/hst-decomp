/* HSTMATCH module=hstp_trans_main.prx start=0x00239108 end=0x00239164 symbol=__dt__13Tree_00239108Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_00066338.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_00239108;
struct Tree_00239108 {
    int header;
    Node_00239108 *root;
    ~Tree_00239108();
};
extern "C" void FUN_00239698(Tree_00239108 *t, Node_00239108 *x);
Tree_00239108::~Tree_00239108()
{
    if (root)
        FUN_00239698(this, root);
}
