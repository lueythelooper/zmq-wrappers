#include "templates/basic_thread.hpp"

void basic_thread::run()
{

}

void basic_thread::start_thread()
{
    stop_thread();

    basic_thread_instance_ = boost::thread(&basic_thread::run, this);
}

void basic_thread::stop_thread()
{

}