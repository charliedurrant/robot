#pragma once
#include "stdafx.h"
#define PI 3.14159265f
#include "framework.h"

namespace std
{
#ifdef _UNICODE
  typedef wstring tstring;
#else
  typedef string tstring;

#endif
}

using namespace std;

string Functions::_applicationExePath = string("");
  
void Functions::Init(char* applicationExePath)
{
  string path = string(applicationExePath);
  Functions::_applicationExePath = Functions::Trim(path); 
}

string Functions::ErrorMessageString(const string& message, Exception* ex)
{
  string text;
  
  text = message;

  if (ex != nullptr)
  {
    text = string("An error has occured in the application:") + NEWLINE + NEWLINE + message + NEWLINE + NEWLINE + ex->ToString();
  }

  return text;
}

void Functions::ErrorMessageConsole(const string& message, Exception* ex)
{
  string text;
  //SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, (string("An exception occured in the application: ") + ex->Message).c_str());
  text = Functions::ErrorMessageString(message, ex);
  SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, text.c_str());
}


float Functions::SinDegrees(float angleInDegrees)
{
  float param;
  param = Functions::DegreesToRadians(angleInDegrees);
  return sin(param);
}

float Functions::CosDegrees(float angleInDegrees)
{
  float param;
  param = Functions::DegreesToRadians(angleInDegrees);
  return sin(param);
}

float Functions::TanDegrees(float angleInDegrees)
{
  float param;
  param = Functions::DegreesToRadians(angleInDegrees);
  return tan(param);
}


float Functions::DegreesToRadians(float angleInDegrees)
{
  float param;   
  param = angleInDegrees * PI / 180;
  return param;
}

float Functions::RadiansToDegrees(float angleInRadians)
{
  float angleInDegrees;
  
  angleInDegrees = angleInRadians / PI * 180;
  return angleInDegrees;
}

SIZE_FRAMEWORK Functions::ScaleToWidth(SIZE_FRAMEWORK size, int width)
{
  float ratio;

  ratio = (float)width / (float)size.Width;
  size.Width = width;
  size.Height = (int)(ratio * (float)(size.Height));
  return size;
}

SIZEF Functions::ScaleToWidth(SIZEF size, float width)
{
  float ratio;

  ratio = width / size.Width;
  size.Width = width;
  size.Height = (ratio * (float)(size.Height));
  return size;
}

SIZEF Functions::ScaleToWidth(SIZE_FRAMEWORK size, float width)
{
  float ratio;
  SIZEF szF;

  ratio = width / (float)size.Width;
  szF.Width = width;
  szF.Height = (ratio * (float)(size.Height));
  return szF;
}




float Functions::ATanDegrees(float tanValue)
{
  float radiansValue;

  radiansValue = atan(tanValue);
  return Functions::RadiansToDegrees(radiansValue);
}

RECT_FRAMEWORK Functions::RectCenterInAnother(RECT_FRAMEWORK* container, RECT_FRAMEWORK* rectToCenter)
{
  RECT_FRAMEWORK r;
  r.Height = 0;
  return r;      
}

string Functions::ApplicationExePath()
{
  return string(Functions::_applicationExePath);
}

string Functions::ApplicationPath()
{
  int p0, p1;
  string s;
  try
  {    
    p0 = Functions::_applicationExePath.find_last_of('\\');
    p1 = Functions::_applicationExePath.find_last_of('/');
    if ( p1 == string::npos )
    { p1 = -1; }
    if ( p0 == string::npos )
    { p0 = -1; }
    if( p1 > p0 )
    { p0 = p1; }
    if ( p0 == -1 )
    {
      s = string(Functions::_applicationExePath);
      s = Functions::FullPath(s);
    }
    else
    {
      s = Functions::_applicationExePath.substr(0,p0 + 1);
    }
    return s;
  }
  catch( Exception* ex )
  {
    throw new Exception("Failed to get the ApplicationPath",ex); 
  }
}




bool Functions::FileExists(string& path)
{
  if (FILE *file = fopen(path.c_str(), "r")) 
  {
    fclose(file);
    return true;
  } 
  else 
  {
    return false;
  }   
}

string Functions::Trim(string s) 
{
  return TrimLeft(TrimRight(s));
}


string Functions::TrimLeft(string s) 
{
  
  size_t  i, p0, p1;
  size_t length;
  p0 = 0;
  p1 = -1;

  length = s.length();
  for( i = 0; i < length; i++ )
  {
    if ( isspace(s[i]) )
    { p1 = i; }
    else
    { break; }
  } 
  if ( p1 != -1 )
  {
    p1++;
    s.erase(p0,p1);
  }
  return s;
}

string Functions::TrimRight(string s) 
{
  int i, length, p0, p1;
    
  length = (int)s.length();
  p1 = length - 1;
  p0 = -1;
  for( i = length - 1; i > -1; i-- )
  {
    if ( isspace(s[i]) )
    { p0 = i; }
    else
    { break; }
  } 
  if ( p0 != -1 )
  {
    s.erase(p0,p1  - p0 + 1);
  }
  return s;
}

string Functions::FullPath(string path)
{
  size_t p0;
  string newPath;
  try
  {
    if ( path.length() > 0 )
    {
      p0 = path.length() - 1;
      if ( ! (path[p0] == '\\' || path[p0] == '/') )
      {
        path.append("/");  
      }    
    } 
    return path; 
  }
  catch( Exception* ex )
  {
    throw new Exception("Failed in full path",ex); 
  }
}

typedef struct { int n; POINTF* v; } polygon_t, *polygon;
#define BIN_V(op, xx, yy) POINTF v##op(POINTF a,POINTF b){POINTF c;c.X=xx;c.Y=yy;return c;}
#define BIN_S(op, r) float  v##op(POINTF a, POINTF b){ return r; }
BIN_V(sub, a.X - b.X, a.Y - b.Y);
BIN_V(add, a.X + b.X, a.Y + b.Y);
BIN_S(dot, a.X * b.X + a.Y * b.Y);
BIN_S(cross, a.X * b.Y - a.Y * b.X);

/* return a + s * b */
POINTF vmadd(POINTF a, float s, POINTF b)
{
  POINTF c;
  c.X = a.X + (s * (float)b.X);
  c.Y = a.Y + (s * (float)b.Y);
  return c;
}

/* check if x0->X1 edge crosses y0->Y1 edge. dx = x1 - x0, dy = y1 - y0, then
solve  x0 + a * dx == y0 + b * dy with a, b in real
cross both sides with dx, then: (remember, cross product is a scalar)
x0 X dx = y0 X dx + b * (dy X dx)
similarly,
x0 X dy + a * (dx X dy) == y0 X dy
there is an intersection iff 0 <= a <= 1 and 0 <= b <= 1

returns: 1 for intersect, -1 for not, 0 for hard to say (if the intersect
point is too close to y0 or y1)
*/
int intersect(POINTF x0, POINTF  x1, POINTF y0, POINTF y1, float tol, POINTF *sect)
{
  POINTF dx = vsub(x1, x0), dy = vsub(y1, y0);
  float d = vcross(dy, dx), a;
  if (!d) return 0; /* edges are parallel */

  a = (vcross(x0, dx) - vcross(y0, dx)) / d;
  if (sect)
    *sect = vmadd(y0, a, dy);

  if (a < -tol || a > 1 + tol) return -1;
  if (a < tol || a > 1 - tol) return 0;

  a = (vcross(x0, dy) - vcross(y0, dy)) / d;
  if (a < 0 || a > 1) return -1;

  return 1;
}

/* distance between x and nearest point on y0->Y1 segment.  if the point
lies outside the segment, returns infinity */
double dist(POINTF x, POINTF y0, POINTF y1, float tol)
{
  POINTF dy = vsub(y1, y0);
  POINTF x1, s;
  int r;

  x1.X = x.X + dy.Y; x1.Y = x.Y - dy.X;
  r = intersect(x, x1, y0, y1, tol, &s);
  if (r == -1) return HUGE_VAL;
  s = vsub(s, x);
  return sqrt(vdot(s, s));
}

#define for_v(i, z, p) for(i = 0, z = p->v; i < p->n; i++, z++)
/* returns 1 for inside, -1 for outside, 0 for on edge */
int inside(POINTF v, polygon p, float tol)
{
  /* should assert p->n > 1 */
  int i, k, crosses;
  POINTF *pv;
  double min_x, max_x, min_y, max_y;

  for (i = 0; i < p->n; i++) {
    k = i + 1 % p->n;
    min_x = dist(v, p->v[i], p->v[k], tol);
    if (min_x < tol) return 0;
  }

  min_x = max_x = p->v[0].X;
  min_y = max_y = p->v[1].Y;

  /* calculate extent of polygon */
  for_v(i, pv, p) {
    if (pv->X > max_x) max_x = pv->X;
    if (pv->X < min_x) min_x = pv->X;
    if (pv->Y > max_y) max_y = pv->Y;
    if (pv->Y < min_y) min_y = pv->Y;
  }
  if (v.X < min_x || v.X > max_x || v.Y < min_y || v.Y > max_y)
    return -1;

  max_x -= min_x; max_x *= 2;
  max_y -= min_y; max_y *= 2;
  max_x += max_y;

  POINTF e;
  while (1) {
    crosses = 0;
    /* pick a rand point far enough to be outside polygon */
    e.X = v.X + (int)((1 + rand() / ((float)RAND_MAX + 1.)) * max_x);
    e.Y = v.Y + (int)((1 + rand() / ((float)RAND_MAX + 1.)) * max_x);

    for (i = 0; i < p->n; i++) {
      k = (i + 1) % p->n;
      k = intersect(v, e, p->v[i], p->v[k], tol, 0);

      /* picked a bad point, ray got too close to vertex.
      re-pick */
      if (!k) break;

      if (k == 1) crosses++;
    }
    if (i == p->n) break;
  }
  return (crosses & 1) ? 1 : -1;
}

int Functions::PointInPolygon(POINTF pt, POINTF* points, int numberOfPoints)
{
  polygon_t p;
  p.v = points;
  p.n = numberOfPoints;
  return inside(pt,&p,0);
}


// Dot product operator
float dot(const POINTF &a, const POINTF &b)
{
  return (float)(a.X*b.X + a.Y*b.Y);
}

// Gather up one-dimensional extents of the projection of the polygon
// onto this axis.
void gatherPolygonProjectionExtents(
  int vertCount, const POINTF *vertList, // input polygon verts
  const POINTF &v,                       // axis to project onto
  float &outMin, float &outMax          // 1D extents are output here
  ) {

  // Initialize extents to a single point, the first vertex
  outMin = outMax = dot(v, vertList[0]);

  // Now scan all the rest, growing extents to include them
  for (int i = 1; i < vertCount; ++i)
  {
    float d = dot(v, vertList[i]);
    if (d < outMin) outMin = d;
    else if (d > outMax) outMax = d;
  }
}



// Helper routine: test if two convex polygons overlap, using only the edges of
// the first polygon (polygon "a") to build the list of candidate separating axes.
bool findSeparatingAxis(
  int aVertCount, const POINTF *aVertList,
  int bVertCount, const POINTF *bVertList
  ) {

  // Iterate over all the edges
  int prev = aVertCount - 1;
  for (int cur = 0; cur < aVertCount; ++cur)
  {

    // Get edge vector.  (Assume operator- is overloaded)
    POINTF edge = aVertList[cur] - aVertList[prev];

    // Rotate vector 90 degrees (doesn't matter which way) to get
    // candidate separating axis.
    POINTF v;
    v.X = edge.Y;
    v.Y = -edge.X;

    // Gather extents of both polygons projected onto this axis
    float aMin, aMax, bMin, bMax;
    gatherPolygonProjectionExtents(aVertCount, aVertList, v, aMin, aMax);
    gatherPolygonProjectionExtents(bVertCount, bVertList, v, bMin, bMax);

    // Is this a separating axis?
    if (aMax < bMin) return true;
    if (bMax < aMin) return true;

    // Next edge, please
    prev = cur;
  }

  // Failed to find a separating axis
  return false;
}


// Here is our high level entry point.  It tests whether two polygons intersect.  The
// polygons must be convex, and they must not be degenerate.
bool convexPolygonOverlap(
  int aVertCount, POINTF *aVertList,
  int bVertCount, POINTF *bVertList
  ) {

  // First, use all of A's edges to get candidate separating axes
  if (findSeparatingAxis(aVertCount, aVertList, bVertCount, bVertList))
    return false;

  // Now swap roles, and use B's edges
  if (findSeparatingAxis(bVertCount, bVertList, aVertCount, aVertList))
    return false;

  // No separating axis found.  They must overlap
  return true;
}

POINTF* Functions::POINTArrayToPOINTFArray(POINT_FRAMEWORK* polygon, int numberOfPointsInPolyGon)
{
  POINTF* polygonF;
  POINTF* polygonFRet;
  int i;
  polygonF = new POINTF[numberOfPointsInPolyGon];
  polygonFRet = polygonF;
  for (i = 0; i < numberOfPointsInPolyGon; i++)
  {
    polygonF->X = (float)polygon->X;
    polygonF->Y = (float)polygon->Y;
    polygon++;
    polygonF++;
  }
  return polygonFRet;
}

bool Functions::ConvexPolygonsOverlap(POINT_FRAMEWORK* polygonA, int numberOfPointsInPolyGonA, POINT_FRAMEWORK* polygonB, int numberOfPointsInPolyGonB)
{
  POINTF* polygonAF;
  POINTF* polygonBF;
  bool ret;

  polygonAF = Functions::POINTArrayToPOINTFArray(polygonA,numberOfPointsInPolyGonA);
  polygonBF = Functions::POINTArrayToPOINTFArray(polygonB, numberOfPointsInPolyGonB);

  ret =  convexPolygonOverlap(numberOfPointsInPolyGonA, polygonAF, numberOfPointsInPolyGonB, polygonBF);

  delete polygonAF;
  delete polygonBF;

  return ret;
}

bool Functions::RectsIntersect(RECTF* rect1,RECTF* rect2)
{
  POINTF rect1Points[4]; 
  POINTF rect2Points[4]; 

  rect1Points[0].X = rect1->X;
  rect1Points[0].Y = rect1->Y;

  rect1Points[1].X = rect1->X + rect1->Width;
  rect1Points[1].Y = rect1->Y;

  rect1Points[2].X = rect1->X + rect1->Width;
  rect1Points[2].Y = rect1->Y + rect1->Height;

  rect1Points[3].X = rect1->X;
  rect1Points[3].Y = rect1->Y + rect1->Height;

  rect2Points[0].X = rect2->X;
  rect2Points[0].Y = rect2->Y;

  rect2Points[1].X = rect2->X + rect2->Width;
  rect2Points[1].Y = rect2->Y;

  rect2Points[2].X = rect2->X + rect2->Width;
  rect2Points[2].Y = rect2->Y + rect2->Height;

  rect2Points[3].X = rect2->X;
  rect2Points[3].Y = rect2->Y + rect2->Height;

  return ConvexPolygonsOverlap(&rect1Points[0],4, &rect2Points[0], 4);

}


bool Functions::ConvexPolygonsOverlap(POINTF* polygonA, int numberOfPointsInPolyGonA, POINTF* polygonB, int numberOfPointsInPolyGonB)
{
  return convexPolygonOverlap(numberOfPointsInPolyGonA, polygonA, numberOfPointsInPolyGonB, polygonB) ;
}

bool Functions::AnyPointInRect(POINTF* polygonA, int numberOfPointsInPolyGonA, RECTF rectangle)
{
  POINTF rectPoints[4]; 

  rectPoints[0].X = rectangle.X;
  rectPoints[0].Y = rectangle.Y;

  rectPoints[1].X = rectangle.X + rectangle.Width;
  rectPoints[1].Y = rectangle.Y;

  rectPoints[2].X = rectangle.X + rectangle.Width;
  rectPoints[2].Y = rectangle.Y + rectangle.Height;

  rectPoints[3].X = rectangle.X;
  rectPoints[3].Y = rectangle.Y + rectangle.Height;

  return convexPolygonOverlap(numberOfPointsInPolyGonA, polygonA, 4, rectPoints);
}


bool Functions::PolygonInsidePolygon(POINTF* polygonInside, int numberOfPointsInPolyGonInside, POINTF* polygonOutside, int numberOfPointsInPolyGonOutside)
{
  int i;
  bool b;

  for (i = 0; i < numberOfPointsInPolyGonInside; i++)
  {
    b = convexPolygonOverlap(1, polygonInside, numberOfPointsInPolyGonOutside, polygonOutside);
    if (!b)
    { return false; }
    polygonInside++;    
  }
  return true;
}

bool Functions::PolygonInsidePolygon(POINT_FRAMEWORK* polygonInside, int numberOfPointsInPolyGonInside, POINT_FRAMEWORK* polygonOutside, int numberOfPointsInPolyGonOutside)
{
  POINTF* polygonInsideF;
  POINTF* polygonOutsideF;
  bool b;


  polygonInsideF = Functions::POINTArrayToPOINTFArray(polygonInside, numberOfPointsInPolyGonInside);
  polygonOutsideF = Functions::POINTArrayToPOINTFArray(polygonOutside, numberOfPointsInPolyGonOutside);

  b = Functions::PolygonInsidePolygon(polygonInsideF, numberOfPointsInPolyGonInside, polygonOutsideF, numberOfPointsInPolyGonOutside);

  delete polygonInsideF;
  delete polygonOutsideF;

  return b;

}

float Functions::Round(float number)
{
  return number < 0.0f ? ceil(number - 0.5f) : floor(number + 0.5f);
}    

//if width is the width of the rectangle then if the diagonal is at 'degrees' the function returns the height
float Functions::RectangleDimensionToOtherByDegrees(float width, float degrees)
{
  float height;

  height = Functions::TanDegrees(degrees) * width;
  return height;
}


string Functions::BoolToString(bool b)
{
  if ( b )
  { return "True"; }
  return "False"; 
}


string Functions::TextFileRead(string fileName)
{
  std::ifstream in(fileName);
  std::stringstream buffer;
  buffer << in.rdbuf();
  std::string contents(buffer.str());
  return contents;
}

void Functions::StringReplace(std::string& str, const std::string& find, const std::string& replace) 
{
  size_t start_pos;

  if (find.empty())
  { return; }
  start_pos = 0;
  while ((start_pos = str.find(find, start_pos)) != std::string::npos)
  {
    str.replace(start_pos, find.length(), replace);
    start_pos += replace.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
  }
}

TiXmlDocument* Functions::XMLFileLoad(string pathAndFile)
{
  TiXmlDocument* xmlDoc = nullptr;
  try
  {
    xmlDoc = new TiXmlDocument();
    if ( ! xmlDoc->LoadFile(pathAndFile,TIXML_ENCODING_UTF8) )
    {
      throw new Exception(str(fmt::Format("{0}, row: {1}, column: {2}") << xmlDoc->ErrorDesc() << xmlDoc->ErrorRow() << xmlDoc->ErrorCol() )); //TODO: add other info to exception
    }
    return xmlDoc;
  }
  catch( Exception* ex )
  {
    if ( xmlDoc != nullptr )
    { delete xmlDoc; }
    throw new Exception(string("Failed to load the xml file: ") + pathAndFile,ex); 
  }
}

TiXmlDocument* Functions::XMLStringLoad(const string& data)
{
  return Functions::XMLStringLoad(data, ""
  
  );
}

TiXmlDocument* Functions::XMLStringLoad(const string& data, const string& source_file)
{
  TiXmlDocument* xmlDoc = nullptr;
  const char* ret;
  try
  {
    xmlDoc = new TiXmlDocument();
    ret = xmlDoc->Parse(data.c_str(), 0, TIXML_ENCODING_UTF8);
    if (ret)
    {
      throw new Exception(str(fmt::Format("{0}, row: {1}, column: {2}") << xmlDoc->ErrorDesc() << xmlDoc->ErrorRow() << xmlDoc->ErrorCol())); //TODO: add other info to exception
    }
    return xmlDoc;
  }
  catch (Exception* ex)
  {
    string message;
    if (xmlDoc != nullptr)
    { delete xmlDoc; }

    message = "Failed to load xml from a string";
    if ((source_file.length() > 0))
    {
      message = str(fmt::Format("{0}, source file: {1}") << message << source_file );      
    }
    throw new Exception(message, ex);
  }
}

string Functions::XMLElementPath(TiXmlElement* xmlElement)
{
  string s;
  
  s = xmlElement->ValueStr(); 
  while( (xmlElement = (TiXmlElement*)xmlElement->Parent()) && xmlElement->Type() == TiXmlNode::TINYXML_ELEMENT)
  {
    s =  xmlElement->ValueStr() + "\\" + s; 
  }

  return s; 
  
}

string Functions::XMLElementDetails(TiXmlElement* xmlElement)
{
  string details;
  string path;

  path = Functions::XMLElementPath(xmlElement);

  details = str(fmt::Format("path: {0}, row: {1} ,column {2}") << path << xmlElement->Row() << xmlElement->Column());
  return details;  
}

TiXmlElement* Functions::XMlFindFirstChildByNameAndAttribute(TiXmlElement* elementParent, string name, const string attributeName, const string attributeValue, bool raiseExceptionIfNotPresent)
{
  TiXmlElement* returnElement;

  returnElement = nullptr;

  for(TiXmlElement* element = elementParent->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
  {
    if ( (string(element->Value()) == name) )
    {
      if ( *element->Attribute(attributeName) == attributeValue ) 
      { returnElement = element; }
      break;
    }
  }
  if ( returnElement == nullptr && raiseExceptionIfNotPresent)
  {
    throw new Exception(str(fmt::Format("Failed to find an element with name='{0} and attribute '{1}={2}' under {3}") << name << attributeName << attributeValue));
  }
  return returnElement;
}
    

TiXmlElement * Functions::XMLFindFirstElementByName(TiXmlDocument* xmlDocument, std::string name, bool throwExceptionIfNotFound)
{ return Functions::XMLFindFirstElementByName(xmlDocument->RootElement(),name, throwExceptionIfNotFound); }

TiXmlElement* Functions::XMLFindFirstElementByName(TiXmlElement* elem, std::string name, bool throwExceptionIfNotFound) 
{
  TiXmlElement* elementRoot;
  TiXmlElement* nextParentSibling;
  string elementName;
 
  try
  { 
    elementRoot = elem;
    if ( elem == nullptr )
    {
      throw new Exception("Search below 'element' is null"); 
    }

    while (elem) 
    {
      elementName = std::string(elem->Value());
      if (!elementName.compare(name)) 
      { return (elem); }
      /*elem = elem->NextSiblingElement();*/
      if (elem->FirstChildElement()) {
          elem = elem->FirstChildElement();
      } else if (elem->NextSiblingElement()) {
          elem = elem->NextSiblingElement();
      } else {
        
          while (!(nextParentSibling = elem->Parent()->NextSiblingElement())) 
          {
            if (elem->Parent()->ToElement() == elementRoot) 
            {
               goto NO_VALUE;
            }
            elem = elem->Parent()->ToElement();
          }
          elem = nextParentSibling;
      }
     }
NO_VALUE:
     if ( throwExceptionIfNotFound )
     { throw new Exception(str(fmt::Format("Failed to find the xml element with name='{0]' under the element '{1}'") << name << Functions::XMLElementDetails(elem))); }
     else
     { return nullptr; }
  }
  catch( Exception* ex )
  {
     throw new Exception(str(fmt::Format("Failed to find the xml element with name='{0}'") << name),ex);
  }
}

string Functions::XMLElementText(TiXmlElement* xmlElement, string& defaultValue)
{
  string text;
  /*
  TiXmlText* textElement;
  
  textElement = xmlElement->ToText();
  if ( ! textElement ) 
  { return string(defaultValue); }
  textElement->
  */

  text = xmlElement->GetText();
  
  if ( text.length() == 0 )
  {
    text = defaultValue;
  }
  return text;
}

string Functions::XMLFindFirstChildByNameText(TiXmlElement* elem, string name, string defaultValue, bool raiseExceptionIfNotPresent) 
{
  TiXmlElement* child;
  
  child = Functions::XMLFindFirstChildByName(elem,name);
  if ( ! child )
  { return defaultValue; }

  return Functions::XMLElementText(child,defaultValue);  
}


TiXmlElement* Functions::XMLFindFirstChildByName(TiXmlElement* elem, string name, bool raiseExceptionIfNotPresent) 
{
  string elementName;
  elem = elem->FirstChildElement();
  while (elem) 
  {
    elementName = std::string(elem->Value());
    if ( elementName == name )
    { return elem->ToElement(); }
    elem = elem->NextSiblingElement();    
  }
  if ( raiseExceptionIfNotPresent )
  {
    throw new Exception(str(fmt::Format("Failed to find the first child with name='{0}' under '{1}") << name << Functions::XMLElementDetails(elem)));
  }
  return nullptr;
}


string Functions::StringToUpper(string& s)
{
  std::string result;

  std::locale loc;
  for (unsigned int i = 0; i < s.length(); ++i)
  {
      result += std::toupper(s.at(i), loc);
  }
  return result;
}

string Functions::StringToLower(string& s)
{
  std::string result;

  std::locale loc;
  for (unsigned int i = 0; i < s.length(); ++i)
  {
      result += std::tolower(s.at(i), loc);
  }
  return result;
}


bool Functions::XMLAttributeBool(TiXmlElement* xmlElement, string name, bool defaultValue, bool throwExceptionIfNotFound )
{
  string s;

  try
  {
    s = Functions::XMLAttributeString(xmlElement,name,"",throwExceptionIfNotFound);
    s = Functions::StringToLower(s);
    if ( s == "" )
    { return defaultValue; }

    if ( s== "false" || s == "0" )
    { return false; }

    return true;
  }
  catch( Exception* ex )
  {
    throw XMLNewExceptionAppendElementDetails(xmlElement,str(fmt::Format("Failed to get the bool value from the attribute '{0}'") << name),ex);
  }
}
    
bool Functions::XMLAttributeExists(TiXmlElement* elem, std::string name)
{
  const string* value;
  value = elem->Attribute(name);
  if ( ! value )
  { return false; }
  return true;
}

Exception* Functions::XMLNewExceptionAppendElementDetails(TiXmlElement* element, string message, Exception* innerException)
{
  if ( element )
  { 
    return new Exception(str(fmt::Format("{0}, element: {1}") << message << Functions::XMLElementDetails(element)), innerException);    
  }
  else
  {
    return new Exception(message, innerException);    
  }
}

int Functions::XMLAttributeInt(TiXmlElement* xmlElement, string name, int defaultValue, bool raiseExceptionIfNotFound)
{
  int value;
  const string* ret = nullptr;
  try
  {
    if ( xmlElement == nullptr )
    { throw new Exception("Element is null"); }

    value = defaultValue;
    ret = xmlElement->Attribute(name, &value);
    if ( ! ret && raiseExceptionIfNotFound)
    { throw new Exception(str(fmt::Format("Attribute '{0}' does not exist") << name)); }
    return value;
  }
  catch( Exception* ex )
  {
    throw XMLNewExceptionAppendElementDetails(xmlElement,str(fmt::Format("Failed to find the attribute '{0}'") << name),ex);
  }
}

float Functions::XMLAttributeFloat(TiXmlElement* xmlElement, string name, float defaultValue)
{
  double value;
  value = (double)defaultValue;

  xmlElement->Attribute(name, &value);
  return (float)value;
}


string Functions::XMLAttributeString(TiXmlElement* xmlElement, string name ) { return Functions::XMLAttributeString(xmlElement,name,"",true); }

string Functions::XMLAttributeString(TiXmlElement* xmlElement, string name, string defaultValue, bool throwExceptionIfNotFound )
{
  const string* value;
  string valueRet;

  try
  {
    if ( ! xmlElement )
    {
      if ( throwExceptionIfNotFound )
      { throw new Exception("Element is null");  }
      else
      { return defaultValue; }
    }
    value = xmlElement->Attribute(name);
    if ( ! value  )
    { 
      if ( throwExceptionIfNotFound )
      { throw new Exception(str(fmt::Format("Attribute '{0}' was not found'") << name)); }
      valueRet = string(defaultValue); 
    }
    else
    {
      valueRet.assign(*value);
      valueRet = Functions::Trim(valueRet);
    } 
    return valueRet; 
  }
  catch( Exception* ex )
  { 
    throw XMLNewExceptionAppendElementDetails(xmlElement,str(fmt::Format("Failed to find the attribute '{0}'") << name),ex);    
  }
}


void Functions::CenterRectInRect(RECT_FRAMEWORK* rectToCenter,RECT_FRAMEWORK* rectToCenterIn)
{
   rectToCenter->X = rectToCenterIn->X - ((rectToCenter->Width - rectToCenterIn->Width) / 2);
   rectToCenter->Y = rectToCenterIn->Y - ((rectToCenter->Height - rectToCenterIn->Height) / 2);
}

void Functions::CenterRectInRect(RECTF* rectToCenter,RECTF* rectToCenterIn)
{
   rectToCenter->X = rectToCenterIn->X - ((rectToCenter->Width - rectToCenterIn->Width) / 2.0f);
   rectToCenter->Y = rectToCenterIn->Y - ((rectToCenter->Height - rectToCenterIn->Height) / 2.0f);
}

void Functions::CenterRectInRect(RECTF* rectToCenter,RECT_FRAMEWORK* rectToCenterIn)
{
   rectToCenter->X = (float)rectToCenterIn->X - ((rectToCenter->Width - (float)rectToCenterIn->Width) / 2.0f);
   rectToCenter->Y = (float)rectToCenterIn->Y - ((rectToCenter->Height - (float)rectToCenterIn->Height) / 2.0f);
}

 /* windows example = "C:\Documents and Settings\User\My Documents\Digi_ESP\blah.ggg"; */
 /* unix example ? = "/usr/bin/blah.ggg" */
 /* unix example2 ? = "/durp <-- just a drive name */

size_t Functions::StrPos(const string &haystack, const string &needle)
{
    int sleng = haystack.length();
    int nleng = needle.length();
 
    if (sleng==0 || nleng==0)
        return string::npos;
 
    for(int i=0, j=0; i<sleng; j=0, i++ )
    {
      while (i+j<sleng && j<nleng && haystack[i+j]==needle[j])
        j++;
      if (j==nleng)
        return i;
    }
    return string::npos;
} 

int Functions::Scale(int valueUnscaled, int numerator, int denominator)
{
  int scaled;

  scaled = (int)Functions::Round(((float)numerator / float(denominator)) * (float)valueUnscaled);
  return scaled;
}

