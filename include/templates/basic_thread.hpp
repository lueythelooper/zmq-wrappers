#ifndef ZMQWRAPPER_TEMPLATES_BASIC_THREAD_HPP_
#define ZMQWRAPPER_TEMPLATES_BASIC_THREAD_HPP_

#include <boost/thread.hpp>

class basic_thread
{
private:
    /**
    * Target for the thread instance of this basic thread template
    * This thread calls a set of virtual functions that are implemented
    * in child classes
    */
    void run();

public:
    /**
    * @brief Start the thread
    * 
    * Start the thread instance of this class. First stops any running instances
    */
    void start_thread();

    /**
     * @brief Stop the thread
     * 
     * A function that stops the thread if it is running
     * Relies on implementations of virtual functions that stop the thread wait
     * function
     */
    void stop_thread();


private:
    boost::thread basic_thread_instance_;
};

#endif // ZMQWRAPPER_TEMPLATES_BASIC_THREAD_HPP_