#include "ActionInitialization.hh"
#include "RunAction.hh"

namespace photon_dose_sim
{


	void ActionInitialization::BuildForMaster() const
	{
		auto runAction = new RunAction;
		SetUserAction(runAction);
		
	}

}
