/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "PresageEDK_autodefs.h"
#include "s3eEdk.h"
#include "PresageEDK.h"
//Declarations of Init and Term functions
extern s3eResult PresageEDKInit();
extern void PresageEDKTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_TVOS ||defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static void PresageStart_wrap()
{
    IwTrace(PRESAGEEDK_VERBOSE, ("calling PresageEDK func on main thread: PresageStart"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)PresageStart, 0);
}
static void PresageAdToServe_wrap()
{
    IwTrace(PRESAGEEDK_VERBOSE, ("calling PresageEDK func on main thread: PresageAdToServe"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)PresageAdToServe, 0);
}
static void PresageLoadAd_wrap()
{
    IwTrace(PRESAGEEDK_VERBOSE, ("calling PresageEDK func on main thread: PresageLoadAd"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)PresageLoadAd, 0);
}
static void PresageShowAd_wrap()
{
    IwTrace(PRESAGEEDK_VERBOSE, ("calling PresageEDK func on main thread: PresageShowAd"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)PresageShowAd, 0);
}
static void PresageLaunchEula_wrap()
{
    IwTrace(PRESAGEEDK_VERBOSE, ("calling PresageEDK func on main thread: PresageLaunchEula"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)PresageLaunchEula, 0);
}
#define PresageStart PresageStart_wrap

#define PresageAdToServe PresageAdToServe_wrap

#define PresageLoadAd PresageLoadAd_wrap

#define PresageShowAd PresageShowAd_wrap

#define PresageLaunchEula PresageLaunchEula_wrap


#endif

s3eResult PresageEDKRegister(PresageEDKCallback cbid, s3eCallback fn, void* pData)
{
    return s3eEdkCallbacksRegister(S3E_EXT_PRESAGEEDK_HASH, PRESAGEEDK_CALLBACK_MAX, cbid, fn, pData, 0);
};

s3eResult PresageEDKUnRegister(PresageEDKCallback cbid, s3eCallback fn)
{
    return s3eEdkCallbacksUnRegister(S3E_EXT_PRESAGEEDK_HASH, PRESAGEEDK_CALLBACK_MAX, cbid, fn);
}

void PresageEDKRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[7];
    funcPtrs[0] = (void*)PresageEDKRegister;
    funcPtrs[1] = (void*)PresageEDKUnRegister;
    funcPtrs[2] = (void*)PresageStart;
    funcPtrs[3] = (void*)PresageAdToServe;
    funcPtrs[4] = (void*)PresageLoadAd;
    funcPtrs[5] = (void*)PresageShowAd;
    funcPtrs[6] = (void*)PresageLaunchEula;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[7] = { 0 };

    /*
     * Register the extension
     */
s3eEdkRegister("PresageEDK", funcPtrs, sizeof(funcPtrs), flags, PresageEDKInit, PresageEDKTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int PresageEDKStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&PresageEDKRegisterExt;
    return 0;
}

int g_PresageEDKVal = PresageEDKStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    PresageEDKRegisterExt();
}
#endif

#endif
