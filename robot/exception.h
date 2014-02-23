#pragma once
#include "stdafx.h"
#include "framework.h"



using namespace std;

class Exception : public std::exception
{
   public:
     string Message;
     Exception* InnerException ;
     Exception() : InnerException(nullptr)
     {
       this->Message = string("");   
     }

     explicit Exception(const Exception* copy ) : std::exception(), InnerException(nullptr)
     {
       this->Message = string(copy->Message);   
       if ( copy->InnerException )
       {
         this->InnerException = new Exception(copy->InnerException);          
       } 
     }
     
     explicit Exception(string message, Exception* innerException) : std::exception(), InnerException(nullptr)
     {
       this->Message = message;

       this->InnerException = new Exception(innerException);
       if ( innerException )
       {
         delete innerException;
       }
     }

     /*
     explicit Exception(string message, Exception& innerException) : InnerException(nullptr)
     {
       this->Message = message;
       this->InnerException = new Exception(innerException);
     }
     */
     explicit Exception(string message) : std::exception(), InnerException(nullptr) 
     {
       this->Message = string(message);     
     }

     string ToString()
     {
       string message;
       Exception* ex; 
       //loop around all the inner exceptions and append
       message = string("");
       ex = this;
       while ( ex != NULL )
       {
         if ( ex->Message.length() )
         {
           message += string(NEWLINE) + ex->Message;
         }
         ex = ex->InnerException;
       }
       return Functions::Trim(message);       
     }

     virtual ~Exception() throw () 
     {       
       if ( this->InnerException != nullptr )
       {
         delete this->InnerException;
         this->InnerException = nullptr;
       }       
     }      
};


class ExceptionSDL : public Exception
{
   public:
     ExceptionSDL() : Exception()
     {
      
     }
     ExceptionSDL(string message, Exception* innerException)  : Exception(message, innerException)
     {
       Construct(message);           
     }

     ExceptionSDL(string message) : Exception(message)
     {
       Construct(message);           
     }
   private:
     void Construct(string message)
     {
       const char* buffer;
       buffer = SDL_GetError();

       this->Message = message + " -  SDL error: " + string(buffer);

     }
};

class ExceptionSDLImage : public Exception
{
   public:
     ExceptionSDLImage() : Exception()
     {
        ;
     }
     ExceptionSDLImage(string message, Exception* innerException)  : Exception(message, innerException)
     {
       Construct(message);           
     }

     ExceptionSDLImage(string message) : Exception(message)
     {
       Construct(message);           
     }
   private:
     void Construct(string message)
     {
       const char* buffer;
       buffer = IMG_GetError();
       this->Message = message + " -  SDL_Image error: " + string(buffer);

     }
};


class ExceptionSDLTTF : public Exception
{
   public:
     ExceptionSDLTTF() : Exception()
     {
        ;
     }
     ExceptionSDLTTF(string message, Exception* innerException)  : Exception(message, innerException)
     {
       Construct(message);           
     }

     ExceptionSDLTTF(string message) : Exception(message)
     {
       Construct(message);           
     }
   private:
     void Construct(string message)
     {
       const char* buffer;
       buffer = TTF_GetError();
       this->Message = message + " -  SDL2_TTF error: " + string(buffer);

     }
};

