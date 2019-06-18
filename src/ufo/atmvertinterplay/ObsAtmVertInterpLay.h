/*
 * (C) Copyright 2017-2018 UCAR
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 */

#ifndef UFO_ATMVERTINTERPLAY_OBSATMVERTINTERPLAY_H_
#define UFO_ATMVERTINTERPLAY_OBSATMVERTINTERPLAY_H_

#include <memory>
#include <ostream>
#include <string>

#include "oops/base/Variables.h"
#include "oops/util/ObjectCounter.h"

#include "ufo/atmvertinterplay/ObsAtmVertInterpLay.interface.h"
#include "ufo/ObsOperatorBase.h"

/// Forward declarations
namespace eckit {
  class Configuration;
}

namespace ioda {
  class ObsSpace;
  class ObsVector;
}

namespace ufo {
  class GeoVaLs;

// -----------------------------------------------------------------------------
/// AtmVertInterpLay observation operator class
class ObsAtmVertInterpLay : public ObsOperatorBase,
                   private util::ObjectCounter<ObsAtmVertInterpLay> {
 public:
  static const std::string classname() {return "ufo::ObsAtmVertInterpLay";}

  ObsAtmVertInterpLay(const ioda::ObsSpace &, const eckit::Configuration &);
  virtual ~ObsAtmVertInterpLay();

// Obs Operator
  void simulateObs(const GeoVaLs &, ioda::ObsVector &) const;

// Other
  const oops::Variables & variables() const {return *varin_;}

  int & toFortran() {return keyOper_;}
  const int & toFortran() const {return keyOper_;}

 private:
  void print(std::ostream &) const;
  F90hop keyOper_;
  const ioda::ObsSpace& odb_;
  std::unique_ptr<const oops::Variables> varin_;
};

// -----------------------------------------------------------------------------

}  // namespace ufo
#endif  // UFO_ATMVERTINTERPLAY_OBSATMVERTINTERPLAY_H_
