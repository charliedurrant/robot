using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MakeItSoLib
{
  public class ProjectPath
  {
    public string Path;
    public bool Absolute;
    public ProjectPath(string path, bool absolute)
    {
      this.Path = path;
      this.Absolute = absolute;
    }
  }
}
