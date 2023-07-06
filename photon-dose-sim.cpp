// photon-dose-sim.cpp : Defines the entry point for the application.
//

#include "photon-dose-sim.h"

// User Interfaces:
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"

// run manager
#include "G4RunManagerFactory.hh"

// visualization
#include "G4VisExecutive.hh"

using namespace std;

int main(int argc, char** argv)
{
    // if this program is run on it's own with no other args, the ui is defined.
	G4UIExecutive* ui = nullptr;
	if (argc == 1) { ui = new G4UIExecutive(argc, argv); }
	
    // Construct the default run manager
    //
    auto* runManager =
        G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);


    // Initialize visualization
    //
    G4VisManager* visManager = new G4VisExecutive;
    // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
    // G4VisManager* visManager = new G4VisExecutive("Quiet");
    visManager->Initialize();

    // Get the pointer to the User Interface manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();


    // Process macro or start UI session
    //
    if ( ! ui) {
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    }
    else {
        // interactive mode
        // 
        // set the macro path to 'mac_files'
        UImanager->ApplyCommand("/control/macroPath mac_files");

        UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
        delete ui;
        
    }

    //clean up
    delete visManager;
    delete runManager;


}
