#include "templates/basic_thread.hpp"

void basic_thread::run()
{
    // Local return value for thread iteration function implemented
    // by subclasses
    basic_thread_return_enum return_value_local;

    // Iterate on the running variable, stopping only when boolean is set to false
    // Not needed to be thread safe, because its a boolean
    while (thread_running_)
    {
        // Sleep when child class
        if (thread_iteration() == basic_thread_return_enum::LOOSE_LOOP)
        {
            boost::this_thread::sleep_for(boost::chrono::milliseconds(DEFAULT_LOOSE_LOOP_SLEEP_MILLIS));
        }
    }
}

void basic_thread::start_thread()
{
    stop_thread();

    basic_thread_instance_ = boost::thread(&basic_thread::run, this);
}

void basic_thread::stop_thread()
{
    thread_running_ = false;
}