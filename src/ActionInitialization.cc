#include "ActionInitialization.hh"

#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

namespace photon_dose_sim
{


	void ActionInitialization::BuildForMaster() const
	{
		auto runAction = new RunAction;
		SetUserAction(runAction);
		
	}

	void ActionInitialization::Build() const
	{
		SetUserAction(new PrimaryGeneratorAction);

		auto runAction = new RunAction;
		SetUserAction(runAction);

	}

}
