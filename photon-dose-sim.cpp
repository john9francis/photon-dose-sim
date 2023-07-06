// photon-dose-sim.cpp : Defines the entry point for the application.
//

#include "photon-dose-sim.h"

// User Interfaces:
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"


using namespace std;

int main(int argc, char** argv)
{
    // if this program is run on it's own with no other args, the ui is defined.
	G4UIExecutive* ui = nullptr;
	if (argc == 1) { ui = new G4UIExecutive(argc, argv); }
	
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
        // Note: we don't have an init_vis.mac file yet... I gotta make one.
        //UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
        delete ui;
        
    }

}
