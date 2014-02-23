using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MakeItSoLib
{
    /// <summary>
    /// Holds config for a configuration (debug / release) in a project.
    /// </summary>
    public class MakeItSoConfig_Configuration
    {
        #region Public methods and properties
        public string Name;
        /// <summary>
        /// Constructor
        /// </summary>
        public MakeItSoConfig_Configuration(string name, MakeItSoConfig_Project projectConfig)
        {
            this.Name = name;
            m_projectConfig = projectConfig;
            
        }

        /// <summary>
        /// The 'parent' project config.
        /// </summary>
        public MakeItSoConfig_Project ProjectConfig
        {
            get { return m_projectConfig; }
        }

        /// <summary>
        /// Adds a library to the collection to be added to the
        /// configuration we're managing.
        /// </summary>
        public void addLibraryToAdd(string libraryName)
        {
            m_librariesToAdd.Add(libraryName);
        }

        /// <summary>
        /// Returns the collection of libraries to add to this configuration.
        /// </summary>
        public List<string> getLibrariesToAdd()
        {
            return m_librariesToAdd.ToList();
        }

        /// <summary>
        /// Adds a library-path to the collection to be added to the
        /// configuration we're managing.
        /// </summary>
        public void addLibraryPathToAdd(string libraryPath, bool absolute)
        {
          this.AddPathToList(m_libraryPathsToAdd, libraryPath, absolute);                    
        }

        

        /// <summary>
        /// Adds a include-path to the collection to be added to the
        /// configuration we're managing.
        /// </summary>
        public void addIncludePathToAdd(string includePath, bool pathIsAbsolute)
        {
          this.AddPathToList(m_includePathsToAdd, includePath,pathIsAbsolute);          
        }

        private void AddPathToList(HashSet<ProjectPath> paths, string path, bool pathIsAbsolute)
        {
          string newPath;

          if (!pathIsAbsolute)
          {
            newPath = Path.Combine(ProjectConfig.SolutionConfig.SolutionRootFolder, path);
            newPath = Path.GetFullPath(path);
          }
          else
          {
            newPath = path;
          }

          paths.Add(new ProjectPath(newPath, pathIsAbsolute));
        }

        /// <summary>
        /// Returns the collection of library paths to add to this configuration.
        /// </summary>
        public List<ProjectPath> getLibraryPathsToAdd()
        {
            return m_libraryPathsToAdd.ToList();
        }

        /// <summary>
        /// Returns the collection of include paths to add to this configuration.
        /// </summary>
        public List<ProjectPath> getIncludePathsToAdd()
        {
            return m_includePathsToAdd.ToList();
        }

        /// <summary>
        /// Adds a preprocessor-definition to the configuration.
        /// </summary>
        public void addPreprocessorDefinitionToAdd(string definition)
        {
            m_preprocessorDefinitionsToAdd.Add(definition);
        }

        /// <summary>
        /// Gets the collection of preprocessor-definitions to add.
        /// </summary>
        public List<string> getPreprocessorDefinitionsToAdd()
        {
            return m_preprocessorDefinitionsToAdd.ToList();
        }

        /// <summary>
        /// Adds a compiler flag to the configuration.
        /// </summary>
        public void addCompilerFlagToAdd(string flag)
        {
            m_compilerFlagsToAdd.Add(flag);
        }

        /// <summary>
        /// Gets the collection of compiler flags to add.
        /// </summary>
        public List<string> getCompilerFlagsToAdd()
        {
            return m_compilerFlagsToAdd.ToList();
        }

        #endregion

        #region Private data

        // The project-config that this configuration-config is part of...
        private MakeItSoConfig_Project m_projectConfig = null;

        // Libraries to be added to the configuration...
        private HashSet<string> m_librariesToAdd = new HashSet<string>();

        // Library paths to add to the configuration (stored as full paths)...
        private HashSet<ProjectPath> m_libraryPathsToAdd = new HashSet<ProjectPath>();

        // Include paths to add to the configuration (stored as full paths)...
        private HashSet<ProjectPath> m_includePathsToAdd = new HashSet<ProjectPath>();

        // Preprocessor definitions to add to the configuration...
        private HashSet<string> m_preprocessorDefinitionsToAdd = new HashSet<string>();

        // Compiler flags to add to the configuration...
        private HashSet<string> m_compilerFlagsToAdd = new HashSet<string>();

        #endregion
    }
}
