// photon-dose-sim.cc : Defines the entry point for the application.
//

// User Interfaces:
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"

// run manager
#include "G4RunManagerFactory.hh"

// visualization
#include "G4VisExecutive.hh"

// scoring
#include "G4ScoringManager.hh"

// other G4 classes
#include "G4RunManagerFactory.hh"
#include "G4SteppingVerbose.hh"
#include "QBBC.hh"

#include "Randomize.hh"

// our own classes
#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"

using namespace photon_dose_sim;

int main(int argc, char** argv)
{
    // if this program is run on it's own with no other args, the ui is defined.
    G4UIExecutive* ui = nullptr;
    if (argc == 1) { ui = new G4UIExecutive(argc, argv); }

    // Construct the default run manager
    //
    auto* runManager =
        G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

    // create scoring manager to allow ui scoring
    G4ScoringManager::GetScoringManager();

    // Set mandatory initialization classes
    //
    // Detector construction
    runManager->SetUserInitialization(new DetectorConstruction());

    // Physics list
    G4VModularPhysicsList* physicsList = new QBBC;
    physicsList->SetVerboseLevel(1);
    runManager->SetUserInitialization(physicsList);

    // User action initialization
    runManager->SetUserInitialization(new ActionInitialization());


    // Initialize visualization
    //
    G4VisManager* visManager = new G4VisExecutive;
    // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
    // G4VisManager* visManager = new G4VisExecutive("Quiet");
    visManager->Initialize();

    // initialize geometry
    runManager->InitializeGeometry();

    // Get the pointer to the User Interface manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();


    // Process macro or start UI session
    //
    if (!ui) {
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    }
    else {
        // interactive mode

        UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
        delete ui;

    }

    //clean up
    delete visManager;
    delete runManager;

    return 0;

}
