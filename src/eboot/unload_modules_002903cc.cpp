/* HSTMATCH module=EBOOT.BIN start=0x002903cc end=0x0029045c symbol=FUN_002903cc lang=c++ */
/* Hand-written reconstruction (port of src/sharing_main/unload_modules_002a1b24.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Unloads the modules FUN_00290288 loaded ("LoadModule(): %s"): when the loaded flag DAT_0034a7f8 is set, each
   module id in DAT_0034a7fc[] goes to FUN_0029045c (stop + unload, logging sceKernelStopModule/UnloadModule
   errors) until one fails, and every slot is cleared. Retail's loop bound is the id table itself (`i < ids[i]`,
   re-read every pass), kept as written. Names provisional. */
extern "C" {
extern unsigned char DAT_0034a7f8;
extern int DAT_0034a7fc[];
int FUN_0029045c(int id);
}

extern "C" bool FUN_002903cc(void)
{
    if (!DAT_0034a7f8) {
        return true;
    }
    bool ok = true;
    for (int i = 0; i < DAT_0034a7fc[i]; i++) {
        ok = ok && FUN_0029045c(DAT_0034a7fc[i]);
        DAT_0034a7fc[i] = 0;
    }
    DAT_0034a7f8 = 0;
    return ok;
}
