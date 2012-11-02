//#include "nsIGenericFactory.h"
#include "mozilla/ModuleUtils.h"
#include "MKComp.h"

NS_GENERIC_FACTORY_CONSTRUCTOR(MKComponent)
NS_DEFINE_NAMED_CID(MKCOMP_CID);

static const mozilla::Module::CIDEntry kSampleCIDs[] = {
    { &kMKCOMP_CID, false, NULL, MKComponentConstructor },
    { NULL }
};


static const mozilla::Module::ContractIDEntry kSampleContracts[] = {
    { MKCOMP_CONTRACTID, &kMKCOMP_CID },
    { NULL }
};

static const mozilla::Module::CategoryEntry kSampleCategories[] = {
    { NULL }
};

static const mozilla::Module kSampleModule = {
    mozilla::Module::kVersion,
    kSampleCIDs,
    kSampleContracts,
    kSampleCategories
};
NSMODULE_DEFN(nsSampleModule) = &kSampleModule;

/*static nsModuleComponentInfo components[] = 
{
{
MKCOMP_CLASSNAME,
MKCOMP_CID,
MKCOMP_CONTRACTID,
MKComponentConstructor,
}
};

NS_IMPL_NSGETMODULE("MKComponentsModule", components)*/
