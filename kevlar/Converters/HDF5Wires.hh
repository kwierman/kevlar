/**
  TODO:: Stop writing documentation before v0.5
**/
#ifndef HDF5Wires_hh_
#define HDF5Wires_hh_

#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include <boost/multi_array.hpp>
#include "H5Cpp.h"
#include <string>

namespace fhicl{
  class ParameterSet;
}
namespace art{
  class Event;
  class SubRun;  
}

namespace kevlar{
  class HDF5Wires : public art::EDAnalyzer {
    std::string fProducerName;
    std::string fDataSetName;
    hsize_t fDims[4];// Dataset dimensions
    hsize_t fMaxDims[4];
    hsize_t fChunkDims[4];// Chunk Dimensions
    H5::DataSpace fDataSpace;/// Buffer
    H5::DSetCreatPropList fParms;// IO Parameters
    H5::DataSet* fDataSet;// points at dataset
    int fFillValue;
    uint32_t fNEvents;
    boost::multi_array<int, 4>  fBuffer;
    uint32_t fBufferCounter;

  public:
    HDF5Wires(::fhicl::ParameterSet const& );
    ~HDF5Wires();
    void analyze(::art::Event const&) override;
    void beginJob() override;
    void endJob() override;
  };
}

DEFINE_ART_MODULE(kevlar::HDF5Wires)
#endif //HDF5Wires_hh_
