/////////////////////////////////////////////////////////////////
// Error Code List
//
// Author: Douglas Pearson, www.threepenny.net
// Date  : August 2004
//
// List of error codes SML functions can return.
//
/////////////////////////////////////////////////////////////////

#ifndef SML_ERRORS_H
#define SML_ERRORS_H

typedef int ErrorCode;

#include <string>

class Error
{
    public:
        enum
        {
            kNoError,
            kInvalidArgument,
            kCallbackNotFound,
            kNoDocType,
            kNoCallback,
            kNoResponseToCall,
            kNoEmbeddedLink,
            kArgumentIsNotSML,
            kFunctionsNotFound,
            kCreationFailed,
            kSMLHasNoCommand,
            kNullArgument,
            kConnectionTimedOut,
            kSocketError,
            kParsingXMLError,
            kConnectionFailed,
            kInvalidResponse,
            kResponseIsNotSML,
            kFailedToGetResponse,
            kSMLErrorMessage,
            kDetailedError,
            kAgentExists,
            kOutputError,
        } ;
        
        /** Returns a description of the error which can be shown to a user */
        static char const* GetErrorDescription(::ErrorCode code)
        {
            switch (code)
            {
                case kNoError:
                    return "No Error" ;
                case kInvalidArgument:
                    return "Invalid argument" ;
                case kCallbackNotFound:
                    return "Did not find a matching callback to remove" ;
                case kNoDocType:
                    return "This message does not contain a doctype attribute" ;
                case kNoCallback:
                    return "No callback is registered for this type of incoming message (that may be ok)" ;
                case kNoResponseToCall:
                    return "This type of message requires a response but no callback created a response" ;
                case kNoEmbeddedLink:
                    return "This embedded connection has not been set up correctly, so there is nowhere to send the messages to" ;
                case kArgumentIsNotSML:
                    return "The ElementXML object passed in is not a pointer to a valid SML message" ;
                case kFunctionsNotFound:
                    return "Loaded the shared library, but could not find the necessary exported functions.  Check their names and types." ;
                case kCreationFailed:
                    return "Loaded the shared library, but the attempt to create an embedded connection failed." ;
                case kSMLHasNoCommand:
                    return "This SML object does not contain a command tag" ;
                case kNullArgument:
                    return "Null argument passed" ;
                case kConnectionTimedOut:
                    return "Socket connection timed out" ;
                case kSocketError:
                    return "Error reading data from the socket" ;
                case kParsingXMLError:
                    return "Error parsing the incoming XML message" ;
                case kConnectionFailed:
                    return "Failed to connect to the remote server" ;
                case kInvalidResponse:
                    return "The connection sent a response when none should have been sent." ;
                case kResponseIsNotSML:
                    return "The kernel sent back a response that is not formatted as an SML message." ;
                case kFailedToGetResponse:
                    return "No response came back for the command we sent." ;
                case kSMLErrorMessage:
                    return "The SML message contained an error tag.  We should display that instead of this generic error." ;
                case kDetailedError:
                    return "There should be a detailed error message to accompany this and we should show that instead of this!" ;
                case kAgentExists:
                    return "Trying to create an agent that already exists in the kernel." ;
                case kOutputError:
                    return "Invalid format for output." ;
            }
            
            return "Unknown error code" ;
        }
} ;


#endif // SML_ERRORS_H

