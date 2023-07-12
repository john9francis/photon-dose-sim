
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

        G4int worldSizeX = 50*cm;
        G4int worldSizeY = 50*cm;
        G4int worldSizeZ = 50*cm;


        // define worlds
        auto solidWorld = new G4Box("World",
            worldSizeX,                 // default is mm (it seems like)
            worldSizeY,
            worldSizeZ);

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

        // create envelope
        G4double env_sizeXY = 20 * cm, env_sizeZ = 30 * cm;
        G4Material* env_mat = nist->FindOrBuildMaterial("G4_AIR");

        auto solidEnv = new G4Box("Envelope",                    // its name
            0.5 * env_sizeXY, 0.5 * env_sizeXY, 0.5 * env_sizeZ);  // its size

        auto logicEnv = new G4LogicalVolume(solidEnv,  // its solid
            env_mat,                                     // its material
            "Envelope");                                 // its name

        new G4PVPlacement(nullptr,  // no rotation
            G4ThreeVector(),          // at (0,0,0)
            logicEnv,                 // its logical volume
            "Envelope",               // its name
            logicWorld,               // its mother  volume
            false,                    // no boolean operation
            0,                        // copy number
            checkOverlaps);           // overlaps checking


        // detector made of tissue material
        G4Material* detectorMaterial = nist->FindOrBuildMaterial("G4_A-150_TISSUE");
        G4int detectorSizeX = 5*cm;
        G4int detectorSizeY = 5*cm;
        G4int detectorSizeZ = 1*cm;
        G4ThreeVector detectorPos = G4ThreeVector(0, 0, -5*cm);

        auto solidDetector = new G4Box("Detector",
            detectorSizeX,
            detectorSizeY,
            detectorSizeZ);

        auto logicDetector = new G4LogicalVolume(solidDetector,
            detectorMaterial,
            "Detector");
        
        new G4PVPlacement(nullptr,    // rotation
            detectorPos,          // position
            logicDetector,            // its logical volume
            "Detector",               // its name
            logicWorld,               // its mother  volume
            false,                    // boolean operation
            0,                        // copy number
            checkOverlaps);           // overlaps checking


        // set scoring volume
        fScoringVolume = logicDetector;

        return physWorld;
    }
}
