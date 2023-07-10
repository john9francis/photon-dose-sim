
#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace photon_dose_sim
{
    G4VPhysicalVolume* DetectorConstruction::Construct()
    {
        // Get nist material manager
        G4NistManager* nist = G4NistManager::Instance();

        // world properties
        G4Material* worldMaterial = nist->FindOrBuildMaterial("G4_AIR");
        G4bool checkOverlaps = false;

        // define worlds
        auto solidWorld = new G4Box("World",
            10, 10, 10);

        auto logicWorld = new G4LogicalVolume(solidWorld,
            worldMaterial, "World");

        auto physWorld = new G4PVPlacement(nullptr,  // no rotation
            G4ThreeVector(),                           // at (0,0,0)
            logicWorld,                                // its logical volume
            "World",                                   // its name
            nullptr,                                   // its mother  volume
            false,                                     // no boolean operation
            0,                                         // copy number
            checkOverlaps);                            // overlaps checking

        // detector made of tissue material
        G4Material* detectorMaterial = nist->FindOrBuildMaterial("G4_A-150_TISSUE");

        auto solidDetector = new G4Box("Detector",
            1, 1, 1);

        auto logicDetector = new G4LogicalVolume(solidDetector,
            detectorMaterial,
            "Detector");

        new G4PVPlacement(nullptr,  // no rotation
            G4ThreeVector(),          // at (0,0,0)
            logicDetector,                 // its logical volume
            "Detector",               // its name
            logicWorld,               // its mother  volume
            false,                    // no boolean operation
            0,                        // copy number
            checkOverlaps);           // overlaps checking


        // set scoring volume
        fScoringVolume = logicDetector;

        return physWorld;
    }
}
