// photon-dose-sim.cpp : Defines the entry point for the application.
//

#include "photon-dose-sim.h"

// User Interfaces:
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"


using namespace std;

int main(int argc, char** argv)
{
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
        UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
        delete ui;
        
    }

}
