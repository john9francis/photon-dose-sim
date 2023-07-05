// photon-dose-sim.cpp : Defines the entry point for the application.
//

#include "photon-dose-sim.h"
#include "G4UIExecutive.hh"

using namespace std;

int main(int argc, char** argv)
{
	G4UIExecutive ui(argc, argv);
	ui.SessionStart();
}
