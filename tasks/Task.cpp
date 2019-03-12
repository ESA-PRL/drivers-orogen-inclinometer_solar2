/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "Task.hpp"

using namespace inclinometer_solar2;

Task::Task(std::string const& name)
    : TaskBase(name)
{
    driver = NULL;
}

Task::Task(std::string const& name, RTT::ExecutionEngine* engine)
    : TaskBase(name, engine)
{
    driver = NULL;
}

Task::~Task()
{
    delete driver;
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See Task.hpp for more detailed
// documentation about them.

bool Task::configureHook()
{
    if (! TaskBase::configureHook())
        return false;

    driver = new inclinometer_solar2::Solar2();


    driver->activatePrinting();

    if(!driver->openSerial(_port.value(), _baudrate.value()))
    {
        fprintf(stderr, "Inclination: Cannot initialize driver\n");
        return false;
    }

    driver->setRate(_rate.value());

    return true;
}
bool Task::startHook()
{
    if (! TaskBase::startHook())
        return false;

    // Mandatory for a FD driven component
    RTT::extras::FileDescriptorActivity* activity = getActivity<RTT::extras::FileDescriptorActivity>();
    if(activity)
    {
        activity->watch(driver->getFileDescriptor());
        // Set the timeout to 2 seconds
        activity->setTimeout(2000);
    }
    else
    {
        fprintf(stderr, "Inclination: File descriptor error\n");
        return false;
    }


    return true;
}
void Task::updateHook()
{
    TaskBase::updateHook();
    RTT::extras::FileDescriptorActivity* activity = getActivity<RTT::extras::FileDescriptorActivity>();


    if(activity)
    {
        if(activity->hasError())
        {
            fprintf(stderr, "Inclination: IO error\n");
        }

        if(activity->hasTimeout())
        {
            fprintf(stderr, "Inclination: Timeout\n");
        }
    }
    else
    {
        fprintf(stderr, "Inclination: No RTT activity\n");
        return;
    }


    // Building Message
    float inclinations[2];
    if(!driver->update(inclinations))
    {
        fprintf(stderr, "Inclination: Error reading device\n");
    }
    else
    {
        inclinometer_solar2::Inclinations inclintation_msg;
        inclintation_msg.time = base::Time::now();

        inclintation_msg.inc[0] = inclinations[0]*3.1415/180;
        inclintation_msg.inc[1] = inclinations[1]*3.1415/180;
        inclinometer_msg.inc[2] = 0;
        _inclinations.write(inclintation_msg);

    }


}
void Task::errorHook()
{
    TaskBase::errorHook();
}
void Task::stopHook()
{
    TaskBase::stopHook();

     RTT::extras::FileDescriptorActivity* activity =
        getActivity<RTT::extras::FileDescriptorActivity>();
    if (activity)
        activity->clearAllWatches();
}
void Task::cleanupHook()
{
    TaskBase::cleanupHook();
}
