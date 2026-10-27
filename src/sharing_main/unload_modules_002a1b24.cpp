/* HSTMATCH module=hstp_trans_main.prx start=0x002a1b24 end=0x002a1bb4 symbol=FUN_002a1b24 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Unloads the modules FUN_002a19e0 loaded ("LoadModule(): %s"): when the loaded flag DAT_003f3b28 is set, each
   module id in DAT_003f3b2c[] goes to FUN_002a1bb4 (stop + unload, logging sceKernelStopModule/UnloadModule
   errors) until one fails, and every slot is cleared. Retail's loop bound is the id table itself (`i < ids[i]`,
   re-read every pass), kept as written. Names provisional. */
extern "C" {
extern unsigned char DAT_003f3b28;
extern int DAT_003f3b2c[];
int FUN_002a1bb4(int id);
}

extern "C" bool FUN_002a1b24(void)
{
    if (!DAT_003f3b28) {
        return true;
    }
    bool ok = true;
    for (int i = 0; i < DAT_003f3b2c[i]; i++) {
        ok = ok && FUN_002a1bb4(DAT_003f3b2c[i]);
        DAT_003f3b2c[i] = 0;
    }
    DAT_003f3b28 = 0;
    return ok;
}
