#include "PrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

namespace photon_dose_sim
{
	PrimaryGeneratorAction::PrimaryGeneratorAction()
	{
		G4int n_particle = 1;
		fParticleGun = new G4ParticleGun(n_particle);

		// define particle stuff
		G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
		G4String particleName;

		G4ParticleDefinition* particle = particleTable->FindParticle(particleName = "gamma");
		fParticleGun->SetParticleDefinition(particle);
		fParticleGun->SetParticlePolarization(G4ThreeVector());
		fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
		fParticleGun->SetParticleEnergy(6. * MeV);
	}

	PrimaryGeneratorAction::~PrimaryGeneratorAction() 
	{
		delete fParticleGun;
	}

	void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
	{
		//this function is called at the begining of ecah event

		// random gun placement
		G4double x0 = 0 * cm, y0 = 0 * cm, z0 = -3 * cm;
		G4double dx0 = 5 * cm, dy0 = 5 * cm, dz0 = 5 * cm;
		x0 += dx0 * (G4UniformRand() - 0.5);
		y0 += dy0 * (G4UniformRand() - 0.5);
		z0 += dz0 * (G4UniformRand() - 0.5);
		fParticleGun->SetParticlePosition(G4ThreeVector(x0, y0, z0));
		fParticleGun->GeneratePrimaryVertex(anEvent);

		fParticleGun->GeneratePrimaryVertex(anEvent);
	}
}