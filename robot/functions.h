#pragma once
#include "framework.h"
using namespace std;


class Exception;

class Functions
{  
  public:
    static string ApplicationExePath();
    static string ApplicationPath();
    static void  Init(char* applicationExePath);

    static string TrimLeft(string s);

    static string TrimRight(string s);
    
    static string Trim(string s);
    
    static string FullPath(string s);
        
    static bool FileExists(string& path);
    
    static float SinDegrees(float angleInDegrees);
    static float CosDegrees(float angleInDegrees);
    static float TanDegrees(float angleInDegrees);
    static float ATanDegrees(float tanValue);
    static float DegreesToRadians(float angleInDegrees);
    static float RadiansToDegrees(float angleInDegrees);
    static float RectangleDimensionToOtherByDegrees(float width, float degrees);
    static SIZE_FRAMEWORK ScaleToWidth(SIZE_FRAMEWORK size, int width);
    static SIZEF ScaleToWidth(SIZEF size, float width);
    static SIZEF ScaleToWidth(SIZE_FRAMEWORK size, float width);
    static int PointInPolygon(POINTF pt, POINTF* points, int numberOfPoints);
    static bool ConvexPolygonsOverlap(POINTF* polygonA, int numberOfPointsInPolyGonA, POINTF* polygonB, int numberOfPointsInPolyGonB);
    static bool ConvexPolygonsOverlap(POINT_FRAMEWORK* polygonA, int numberOfPointsInPolyGonA, POINT_FRAMEWORK* polygonB, int numberOfPointsInPolyGonB);
    static bool PolygonInsidePolygon(POINTF* polygonInside, int numberOfPointsInPolyGonInside, POINTF* polygonOutside, int numberOfPointsInPolyGonOutside);
    static bool PolygonInsidePolygon(POINT_FRAMEWORK* polygonInside, int numberOfPointsInPolyGonInside, POINT_FRAMEWORK* polygonOutside, int numberOfPointsInPolyGonOutside);
    static bool AnyPointInRect(POINTF* polygonA, int numberOfPointsInPolyGonA, RECTF rectangle);
    static float Round(float number);
    static string TextFileRead(string fileName);
    static TiXmlDocument* XMLFileLoad(string pathAndFile);
    static TiXmlDocument* XMLStringLoad(const string& data);
    static TiXmlDocument* XMLStringLoad(const string& data, const string& source_file);
    static TiXmlElement* XMLFindFirstElementByName(TiXmlDocument* xmlDocument, string name, bool throwExceptionIfNotFound = true);
    static TiXmlElement* XMLFindFirstElementByName(TiXmlElement* xmlElement, string name, bool throwExceptionIfNotFound = true);
    static TiXmlElement* XMLFindFirstChildByName(TiXmlElement* elem, std::string name, bool raiseExceptionIfNotPresent = true);
    static string XMLFindFirstChildByNameText(TiXmlElement* elem, string name, string defaultValue, bool raiseExceptionIfNotPresent = false ) ;
    static TiXmlElement* XMlFindFirstChildByNameAndAttribute(TiXmlElement* parent, string name, string attributeName, string attributeValue, bool raiseExceptionIfNotPresent = true);
    static string XMLElementText(TiXmlElement* xmlElement, string& defaultValue);
    static Exception* XMLNewExceptionAppendElementDetails(TiXmlElement* element, string message, Exception* innerException);
    static bool XMLAttributeExists(TiXmlElement* elem, std::string name);

    static int XMLAttributeInt(TiXmlElement* xmlElement, string name, int defaultValue, bool throwExceptionIfNotFound = false);    
    static string XMLAttributeString(TiXmlElement* xmlElement, string name, string defaultValue, bool throwExceptionIfNotFound = false);
    static string XMLAttributeString(TiXmlElement* xmlElement, string name );
    static bool XMLAttributeBool(TiXmlElement* xmlElement, string name, bool defaultValue, bool throwExceptionIfNotFound = false);
    static float XMLAttributeFloat(TiXmlElement* xmlElement, string name, float defaultValue);
    static string XMLElementPath(TiXmlElement* xmlElement);
    static string XMLElementDetails(TiXmlElement* xmlElement);
    static string StringToUpper(string& s);
    static string StringToLower(string& s);
    static void StringReplace(string& str, const string& find, const string& replace);

    static string BoolToString(bool b);
    static void CenterRectInRect(RECT_FRAMEWORK* rectToCenter,RECT_FRAMEWORK* rectToCenterIn);
    static void CenterRectInRect(RECTF* rectToCenter,RECTF* rectToCenterIn);
    static void CenterRectInRect(RECTF* rectToCenter,RECT_FRAMEWORK* rectToCenterIn);
    static bool RectsIntersect(RECTF* rect1,RECTF* rect2);
    static int Scale(int valueUnscaled, int numerator, int denominator);
    static size_t StrPos(const string &haystack, const string &needle);
 
    // templated version of my_equal so it could work with both char and wchar_t
    template<typename charT>
    struct my_equal 
    {
      my_equal( const std::locale& loc ) : loc_(loc) {}
      bool operator()(charT ch1, charT ch2) { return std::toupper(ch1, loc_) == std::toupper(ch2, loc_); }
      private:
        const std::locale& loc_;
    };

    //does not compile with GCC
    // find substring (case insensitive)
    /*
    template<typename T>
    static int StringFindCaseInsentive( const T& haystack, const T& needle, const std::locale& loc = std::locale() )
    {
      T::const_iterator it = std::search( haystack.begin(), haystack.end(), 
        needle.begin(), needle.end(), my_equal<T::value_type>(loc) );
      if ( it != haystack.end() ) return it - haystack.begin();
      else return -1; // not found
    }
    */
    RECT_FRAMEWORK RectCenterInAnother(RECT_FRAMEWORK* container, RECT_FRAMEWORK* rectToCenter);

  private:
    static string _applicationExePath;
    static POINTF* POINTArrayToPOINTFArray(POINT_FRAMEWORK* polygon, int numberOfPointsInPolyGon);
};
