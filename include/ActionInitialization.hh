/// \file photon-dose-sim/include/ActionInitialization.hh
/// \brief Definition of the photon-dose-sim::ActionInitialization class

#ifndef PhotonDoseSimActionInitialization_h
#define PhotonDoseSimActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

namespace photon_dose_sim
{

    class ActionInitialization : public G4VUserActionInitialization
    {
    public:
        ActionInitialization() = default;
        ~ActionInitialization() override = default;

        void BuildForMaster() const override;
        void Build() const override;
    };

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
