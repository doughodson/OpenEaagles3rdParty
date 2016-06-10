/////////////////////////////////////////////////////////////////
// ClientAnalyzedXML class
//
// Author: Douglas Pearson, www.threepenny.net
// Date  : September 2005
//
// Represents an XML message that has been analyzed to identify
// where parameters and other important values occur within the message.
// This allows an efficient "random access" to the values within the message
// and provides some level of abstraction over exactly how the message is structured.
//
// It's a subset of the functionality offered by AnalyzeXML.
//
/////////////////////////////////////////////////////////////////

#ifndef SML_CLIENT_ANALYZED_XML_H
#define SML_CLIENT_ANALYZED_XML_H

#include <string>
#include "Export.h"

namespace soarxml
{
    class ElementXML ;
}

namespace sml
{

    class AnalyzeXML ;
    class ClientKernel ;
    
    class EXPORT ClientAnalyzedXML
    {
            // Allow access to getAnalyzeXML method
            friend class Kernel ;
            
        private:
            AnalyzeXML*     m_pAnalyzeXML ;
            
            AnalyzeXML* GetAnalyzeXML()
            {
                return m_pAnalyzeXML ;
            }
            
        public:
            ClientAnalyzedXML() ;
            virtual ~ClientAnalyzedXML() ;
            
            void Attach(AnalyzeXML* pAnalyzeXML) ;
            
            // Each of these either returns a reference to the tag or NULL (if this document doesn't contain that tag)
            soarxml::ElementXML const* GetCommandTag() const    ;
            soarxml::ElementXML const* GetResultTag() const ;
            soarxml::ElementXML const* GetErrorTag()    const ;
            
            bool IsSML() const ;
            
            // Returns the name of the command (or NULL if no command tag or no name in that tag)
            char const* GetCommandName() const ;
            
            // Returns the character data from the result tag (or NULL if no result tag or no character data in that tag)
            char const* GetResultString() const ;
            
            // Returns the character data from the result tag as an int (or default value if there is no character data in the tag)
            int GetResultInt(int defaultValue) const ;
            
            // Returns the character data from the result tag as an long long (or default value if there is no character data in the tag)
            long long GetResultInt(long long defaultValue) const ;
            
            // Returns the result as a bool
            bool GetResultBool(bool defaultValue) const ;
            
            // Returns the result as a double
            double GetResultFloat(double defaultValue) const ;
            
            // Returns the string form of the XML.  Must be released with the static DeleteString method
            char* GenerateXMLString(bool includeChildren, bool insertNewLines = false) const ;
            
            static void DeleteString(char* pString) ;
            
            /*************************************************************
            * @brief Look up an argument by name.  Returns NULL if not found.
            *************************************************************/
            char const* GetArgString(char const* pArgName) const ;
            
            /*************************************************************
            * @brief As "GetArgString" but parsed as a boolean.
            *************************************************************/
            bool GetArgBool(char const* pArgName, bool defaultValue) const ;
            
            /*************************************************************
            * @brief As "GetArgString" but parsed as an int.
            *************************************************************/
            int GetArgInt(char const* pArgName, int defaultValue) const ;
            
            /*************************************************************
            * @brief As "GetArgString" but parsed as an long long.
            *************************************************************/
            long long GetArgInt(char const* pArgName, long long defaultValue) const ;
            
            /*************************************************************
            * @brief As "GetArgString" but parsed as an float (double).
            *************************************************************/
            double GetArgFloat(char const* pArgName, double defaultValue) const ;
    } ;
    
} //closes namespace

#endif //SML_CLIENT_ANALYZED_XML_H
