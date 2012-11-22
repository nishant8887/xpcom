#include "mozilla/ModuleUtils.h"
#include "MainComponent.h"

NS_GENERIC_FACTORY_CONSTRUCTOR(MainComponent)
NS_DEFINE_NAMED_CID(GIGACOMP_CID);

static const mozilla::Module::CIDEntry kSampleCIDs[] = {
    { &kGIGACOMP_CID, false, NULL, MainComponentConstructor },
    { NULL }
};

static const mozilla::Module::ContractIDEntry kSampleContracts[] = {
    { GIGACOMP_CONTRACTID, &kGIGACOMP_CID },
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