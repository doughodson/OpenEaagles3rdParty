/////////////////////////////////////////////////////////////////
// Event class
//
// Author: Douglas Pearson, www.threepenny.net
// Date  : October 2004
//
// An event can be used to connect two threads.  One thread waits
// on the thread for a set amount of time (or forever) and the other can trigger
// the event to awake the first.
//
/////////////////////////////////////////////////////////////////

#ifndef THREAD_EVENT_H
#define THREAD_EVENT_H

#include "thread_OSspecific.h"
#include "Export.h"

namespace soar_thread
{

    class EXPORT Event
    {
        protected:
            // OS specific implementation
            OSSpecificEvent*    m_Imp ;
            
        public:
            Event() ;
            ~Event() ;
            
            void WaitForEventForever()
            {
                m_Imp->WaitForEventForever() ;
            }
            
            // Returns true if event was triggered.  False if we just timed out.
            //The timeout is seconds + milliseconds, where milliseconds < 1000
            bool WaitForEvent(int seconds, int milliseconds)
            {
                return m_Imp->WaitForEvent(seconds, milliseconds) ;
            }
            
            void TriggerEvent()
            {
                m_Imp->TriggerEvent() ;
            }
    } ;
    
} // Namespace

#endif // THREAD_EVENT_H
