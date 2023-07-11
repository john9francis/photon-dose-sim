#ifndef PhotonDoseSimRunAction_h
#define PhotonDoseSimRunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "globals.hh"

class G4Run;

/// Run action class

namespace photon_dose_sim
{

    class RunAction : public G4UserRunAction
    {
    public:
        RunAction();
        ~RunAction() override = default;

        void BeginOfRunAction(const G4Run*) override;
        void   EndOfRunAction(const G4Run*) override;

        void AddEdep(G4double edep);

    private:
        G4Accumulable<G4double> fEdep = 0.;
        G4Accumulable<G4double> fEdep2 = 0.;
    };

}

#endif