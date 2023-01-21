#ifndef ZMQWRAPPER_TEMPLATES_BASIC_THREAD_HPP_
#define ZMQWRAPPER_TEMPLATES_BASIC_THREAD_HPP_

#include <cstdint>
#include <boost/thread.hpp>

enum class basic_thread_return_enum
{
    TIGHT_LOOP = 0,
    LOOSE_LOOP = 1
};

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

protected:
    /**
     * @brief Thread iteration function
     * 
     * Intended to be implemented by subclasses. Called when iterating on a tight or loose
     * loop. Return value indicates whether to return tight or loop.
     * 
     * @return Enumeration to indicate whether the calling process should tightloop or sleep
     */
    virtual basic_thread_return_enum thread_iteration() = 0;
private:
    // Thread instance
    boost::thread basic_thread_instance_;

    // Variable to be checked by thread while loop
    bool thread_running_ {false};

    // Loose loop sleep time milliseconds, intended to return when user is a butt
    static constexpr std::size_t DEFAULT_LOOSE_LOOP_SLEEP_MILLIS = 125;
};

#endif // ZMQWRAPPER_TEMPLATES_BASIC_THREAD_HPP_