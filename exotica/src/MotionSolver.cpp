#include "exotica/MotionSolver.h"

exotica::MotionSolver::MotionSolver()
{
}

exotica::EReturn exotica::MotionSolver::initBase(tinyxml2::XMLHandle & handle,
        const Server_ptr & server)
{
    Object::initBase(handle,server);
	if (!server)
	{
		INDICATE_FAILURE
		return FAILURE;
	}
	server_ = server;
	return initDerived(handle);
}

exotica::EReturn exotica::MotionSolver::specifyProblem(PlanningProblem_ptr pointer)
{
	problem_ = pointer;
    for(auto& map : problem_->getTaskMaps())
    {
        map.second->poses = problem_->poses;
        map.second->posesJointNames = problem_->posesJointNames;
    }
	return SUCCESS;
}
